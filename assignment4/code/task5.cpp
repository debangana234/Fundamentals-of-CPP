#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

vector<int> parseLineToVector(const string& lines) {
    vector<int> LineToVector;
    stringstream ss(lines);
    string input_buffer;
    while (getline(ss, input_buffer, ' ')) {
        LineToVector.push_back(stoi(input_buffer));
    }
    return LineToVector;
}

//Using recursion to find all cliques in te graph
// R: Currently growing clique, P: Potential nodes to be added to R, X: Nodes that should be excluded from R
void clique(set<int> R, set<int> P, set<int> X, const vector<vector<int>> adj) {
    //base case: Both P and X are empty and R(maximal clique)is printed
    if (P.empty() && X.empty()) {
        cout << "{";
        for (auto it = R.begin(); it != R.end(); ++it) {
            if (it != R.begin()) cout << ", ";
            cout << *it;
        }
        cout << "}" << endl;
        return;
    }

    set<int> P_copy = P;
    for (int v : P_copy) {
        set<int> R_new = R, P_new, X_new;
        R_new.insert(v);
   //For each node v in P, we extend the clique R by adding v, and then update P and X for the next recursive call
        for (size_t i = 0; i < adj.size(); ++i) {
            if (adj[v][i] == 1) {
                if (P.find(i) != P.end()) P_new.insert(i);
                if (X.find(i) != X.end()) X_new.insert(i);
            }
        }

        clique(R_new, P_new, X_new, adj);

        P.erase(v);
        X.insert(v);
    }
}

int main() {
    vector<vector<int>> adjMatrix;
    string line;

    while (getline(cin,
                   line) && !line.empty()) {
        adjMatrix.push_back(parseLineToVector(line));
    }


    set<int> R, P, X;
    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        P.insert(i);
    }

    clique(R, P, X, adjMatrix);

    return 0;
}

