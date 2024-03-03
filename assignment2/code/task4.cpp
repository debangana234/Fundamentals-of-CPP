#include <iostream>
#include <vector>
#include <functional>
#include <limits>
#include <algorithm>

using namespace std;

int match = 1;
int mismatch_score = -1;
int gap = -1;

void needlemanWunsch(const string& str1, const string& str2) {
    // Initialization
    int rows = str1.length() + 1;
    int cols = str2.length() + 1;

    // Creating the score matrix
    vector<vector<int>> scoreMatrix(rows, vector<int>(cols, 0));

    // Filling in the gap penalties for the first row and column
    for (int i = 1; i < rows; ++i) {
        scoreMatrix[i][0] = scoreMatrix[i - 1][0] + gap;
    }

    for (int j = 1; j < cols; ++j) {
        scoreMatrix[0][j] = scoreMatrix[0][j - 1] + gap;
    }

    // We fill in the score matrix based on the Needleman-Wunsch algorithm
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            int matchScore = scoreMatrix[i - 1][j - 1] + ((str1[i - 1] == str2[j - 1]) ? match : mismatch_score);  // match or mismatch score considered in case of diagonal elements
            int deleteScore = scoreMatrix[i - 1][j] + gap; //gap score is considered in case of the element above
            int insertScore = scoreMatrix[i][j - 1] + gap; // gap score is considered in case of element to the left

            // We Choose the maximum of match, delete, or insert as the score for the particular matrix cell
            scoreMatrix[i][j] = max({matchScore, deleteScore, insertScore});
        }
    }

    // Tracing back to find alignments
    vector<pair<string, string>> alignments;
    int i = rows - 1, j = cols - 1;

    // Defining the recursive traceback function
    function<void(int, int, string, string)> traceback = [&](int i, int j, string a, string b) {
        while (i > 0 || j > 0) {
            int currentScore = scoreMatrix[i][j];
            int matchScore = (i > 0 && j > 0) ? scoreMatrix[i - 1][j - 1] : numeric_limits<int>::min();
            int deleteScore = (i > 0) ? scoreMatrix[i - 1][j] : numeric_limits<int>::min();
            int insertScore = (j > 0) ? scoreMatrix[i][j - 1] : numeric_limits<int>::min();

            // Check if reached the end of the matrix
            if (j < 0 || i < 0) {
                break;
            }

            // Determining the direction of the traceback (considering three possible direction of traceback)
            if (currentScore == matchScore + ((str1[i - 1] == str2[j - 1]) ? match : mismatch_score)) {
                if (currentScore == deleteScore + gap) {
                    if (currentScore == insertScore + gap) {
                        // Diagonal traceback
                        string g, h;
                        g = '-' + a;
                        h = str2[j - 1] + b;
                        traceback(i, j - 1, g, h);
                    }
                    // Vertical traceback to the cell above
                    string c, d;
                    c = str1[i - 1] + a;
                    d = '-' + b;
                    traceback(i - 1, j, c, d);
                } else if (currentScore == insertScore + gap) {
                    // Horizontal traceback to the cell to the left
                    string e, f;
                    e = '-' + a;
                    f = str2[j - 1] + b;
                    traceback(i, j - 1, e, f);
                }
                // Moving to the previous diagonal position
                a = str1[i - 1] + a;
                b = str2[j - 1] + b;
                --i;
                --j;
            } else if (currentScore == deleteScore + gap) {
                if (currentScore == insertScore + gap) {
                    // Diagonal traceback
                    string q, t;
                    q = '-' + a;
                    t = str2[j - 1] + b;
                    traceback(i, j - 1, q, t);
                }
                // Vertical traceback
                a = str1[i - 1] + a;
                b = '-' + b;
                --i;
            } else {
                // Horizontal traceback
                a = '-' + a;
                b = str2[j - 1] + b;
                --j;
            }
        }
        // Adding the current alignment to the vector
        alignments.emplace_back(a, b);
    };

    // We need to call traceback with initial conditions
    traceback(i, j, "", "");

    // Printing results
    cout << scoreMatrix[rows - 1][cols - 1] << endl;
    for (const auto& alignment : alignments) {
        cout << alignment.first << endl << alignment.second << endl << endl;
    }
}

int main(int argc, char* argv[]) {
    // Check for the correct number of command-line arguments
    if (argc != 3) {
        cerr << "Error in input: " << argv[0] << " <string1> <string2>" << endl;
        return 1;
    }

    // Getting the input strings as command-line arguments
    string str1 = argv[1];
    string str2 = argv[2];

    // Calling  the Needleman-Wunsch function
    needlemanWunsch(str1, str2);

    return 0;
}
