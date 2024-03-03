#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Gene {
public:
    string chromosome;
    int start;
    int stop;
    int centre;
    int cluster; // Field for cluster index

    Gene() : start(0), stop(0), centre(0), cluster(0) {}

    Gene(const string &chrom, int start, int stop) : chromosome(chrom), start(start), stop(stop) {
        centre = (start + stop) / 2;
    }
};

// Function to compute gene clusters
void assign_clusters(vector<Gene> &gene_list, int distance) {
    int cluster_count = 1;

    for (size_t i = 0; i < gene_list.size(); ++i) {
        // Skipping genes that are already assigned to a cluster
        if (gene_list[i].cluster != 0) {
            continue;
        }

        // Assigning the current gene to a new cluster
        gene_list[i].cluster = cluster_count;

        // Checking the other genes for cluster assignment
        for (size_t j = i + 1; j < gene_list.size(); ++j) {
            // Skip genes that are already assigned to a cluster
            if (gene_list[j].cluster != 0) {
                continue;
            }
          //Measuring distance by calculating the distance between the centre of the two genes
            int diff = abs(gene_list[j].centre - gene_list[i].centre);

            if (diff <= distance && gene_list[j].chromosome == gene_list[i].chromosome) {
                gene_list[j].cluster = cluster_count;
                cluster_count++;   // Increment the cluster index for the next cluster
            }
        }

    }
}

// Taking two Gene objects, gene1 and gene2, and determining their relative order based on the values of the chromosome and start data members.
bool sortedGenes(const Gene &gene1, const Gene &gene2) {
    if (gene1.chromosome != gene2.chromosome) {
        return gene1.chromosome < gene2.chromosome;
    } else {
        return gene1.start < gene2.start;
    }
}

int main(int argc, const char *argv[]) {
    if (argc != 4) {
        cerr << "Enter correct input: " << argv[0] << " input_file distance output_file" << endl;
        return 1;
    }

    string input_file = argv[1];
    ifstream file(input_file);
    int distance = stoi(argv[2]);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file" << endl;
        return 1;
    }

    vector<Gene> gene_list;

    // Reading genes from the input file
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            cerr << "Check for empty lines" << endl;
            continue;
        }
        istringstream iss(line);
        Gene gene;
        iss >> gene.chromosome >> gene.start >> gene.stop;
        gene_list.push_back(gene);
    }

    file.close();

    // We have to check if the genes are sorted in coordinate order
    if (!is_sorted(gene_list.begin(), gene_list.end(), sortedGenes)) {
        cerr << "Error: Genes are not sorted in coordinate order." << endl;
        return 1;
    }

    // Calling Assign clusters to genes
    assign_clusters(gene_list, distance);

    // Sorting the genes by cluster index and coordinate order
    sort(gene_list.begin(), gene_list.end(), sortedGenes);

    // Writing the result to the output file
    string output_file = argv[3];
    ofstream outputFile(output_file);

    for (const auto &gene : gene_list) {
        outputFile << gene.chromosome << '\t' << gene.start << '\t' << gene.stop << '\t' << "cluster=" << gene.cluster << endl;
    }

    outputFile.close();

    return 0;
}
