#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int minimumBeamingStations(int n, int k, const vector<int>& cities) {
    int count = 0;
    int i = 0;
    while (i < n) {
        if (cities[i] == 1) {
            i += k;
        } else {
            bool found = false;
            for (int j = i; j < min(i + k, n); ++j) {
                if (cities[j] == 1) {
                    i = j + k;
                    found = true;
                    break;
                }
            }
            if (!found) return -1;
            count++;
        }
    }
    return count;
}

int minimumCatapults(int n, int l, const vector<int>& cities) {
    int count = 0;
    int i = 0;
    while (i < n) {
        if (cities[i] == 2) {
            i += l;
        } else {
            bool found = false;
            for (int j = i; j < min(i + l, n); ++j) {
                if (cities[j] == 2) {
                    i = j + l;
                    found = true;
                    break;
                }
            }
            if (!found) return -1;
            count++;
        }
    }
    return count;
}

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> cities(n);

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        cities[i] = c - '0';
    }

    int beamerCount = minimumBeamingStations(n, k, cities);
    int catapultCount = minimumCatapults(n, l, cities);

    cout << "beamer:" << beamerCount << endl;
    cout << "cata:" << catapultCount << endl;

    return 0;
}