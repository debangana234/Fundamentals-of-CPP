#include "cxxopts.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

unsigned int line_no = 0;  //  variable to track the current line number.

// Trimming leading and trailing whitespace from a string.
string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\n\r\f\v");
    size_t end = s.find_last_not_of(" \t\n\r\f\v");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

// Compiling a regex pattern, with an option for case insensitivity.
regex compile_pattern(const string &pattern, bool case_insensitive) {
    return case_insensitive ? regex(pattern, regex_constants::icase) : regex(pattern);
}

// Searching a line for a match with the given regex pattern. Inverts the match if specified.
bool search_line(const string &line, const regex &pattern, bool invert_match) {
    bool match_found = regex_search(line, pattern);
    return invert_match ? !match_found : match_found;
}

// Performing a simple string search within a line, with an option for case insensitivity.
bool string_search(const string &line, const string &pattern, bool case_insensitive) {
    if (case_insensitive) {
        string line_lower = line;
        string pattern_lower = pattern;
        transform(line_lower.begin(), line_lower.end(), line_lower.begin(), ::tolower);
        transform(pattern_lower.begin(), pattern_lower.end(), pattern_lower.begin(), ::tolower);
        return line_lower.find(pattern_lower) != string::npos;
    } else {
        return line.find(pattern) != string::npos;
    }
}

// Processing a line to find a match based on the given pattern and options. Returns the matching line.
string process_line(const string &line, const string &pattern, const string &options) {
    bool case_insensitive = options.find("i") != string::npos;
    bool fixed_string = options.find("F") != string::npos;
    bool invert_match = options.find("v") != string::npos;
    bool show_line_number = options.find("n") != string::npos;

    bool match;
    if (fixed_string) {
        match = string_search(line, pattern, case_insensitive);
    } else {
        regex compiled_pattern = compile_pattern(pattern, case_insensitive);
        match = search_line(line, compiled_pattern, invert_match);
    }

    if (match) {
        return show_line_number ? to_string(line_no) + ":" + line : line;
    }
    return "";
}

// Reading patterns from a given file and returns them as a vector of strings.
vector<string> read_patterns_from_file(const string& filename) {
    vector<string> patterns;
    ifstream file(filename);
    if (!file) {
        cerr << "Pattern file could not be opened: " << filename << endl;
        throw runtime_error("File opening failed");
    }

    string pattern;
    while (getline(file, pattern)) {
        pattern = trim(pattern); // Trim the pattern to remove any leading/trailing whitespace
        if (!pattern.empty()) {
            patterns.push_back(pattern);
        }
    }

    return patterns;
}

int main(int argc, char *argv[]) {
    cxxopts::Options options(argv[0], "lightweight version of grep");
    options.add_options()
            ("i", "Case Insensitivity")
            ("F", "Pattern should be treated as string")
            ("w", "Whole word match")
            ("f,file", "File name for patterns", cxxopts::value<string>())
            ("v", "Non-matching patterns")
            ("n", "Number of lines")
            ("pattern", "Search pattern", cxxopts::value<string>())
            ("input-file", "Input file", cxxopts::value<string>());

    options.parse_positional({"pattern", "input-file"});
    auto result = options.parse(argc, argv);

    // Checking whether an input file is specified.
    if (!result.count("input-file")) {
        cerr << "Input file is required." << endl;
        return 1;
    }

    string filename = result["input-file"].as<string>();
    vector<string> patterns;

    // Reading patterns from a file or the command line.
    if (result.count("f")) {
        string pattern_file = result["f"].as<string>();
        patterns = read_patterns_from_file(pattern_file);
    } else if (result.count("pattern")) {
        patterns.push_back(result["pattern"].as<string>());
    } else {
        cerr << "Either a pattern or a pattern file is required." << endl;
        return 1;
    }

    string func;
    for (const auto &flag : {"i", "F", "w", "v", "n"}) {
        if (result.count(flag)) {
            func += flag;
        }
    }

    ifstream file(filename);
    if (!file) {
        cerr << "File can't be opened: " << filename << endl;
        return 1;
    }

    // Processing each line of the file with each pattern.
    for (const auto& pattern : patterns) {
        line_no = 0;
        file.clear(); // To clear any error flags
        file.seekg(0); // Going back to the beginning of the file
        string line;
        while (getline(file, line)) {
            line_no++;
            string result = process_line(line, pattern, func);
            if (!result.empty()) {
                cout << result << endl;
            }
        }
    }

    return 0;
}
