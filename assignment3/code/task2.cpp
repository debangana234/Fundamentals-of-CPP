#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

// Function for mean
double get_mean(const vector<double>& v) {
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

// Function for sample std deviation
double getsd(const std::vector<double>& vec, double mean) {
    // Using accumulate with a lambda function to calculate the sum of squared differences
    double variance = std::accumulate(vec.begin(), vec.end(), 0.0,
                                      [mean](double accumulator, double value) {
                                          return accumulator + pow(value - mean, 2);
                                      });

    // Divide by the number of elements to get the variance
    variance /= vec.size()-1;

    return sqrt(variance);
}

// Function for scaling elements
vector<double> scale_elements(const vector<double>& v) {
    vector<double> temp;
    temp.reserve(v.size()); // Reserve space to avoid unnecessary reallocations

    for (double value : v) {
        double val = log2(abs(value) + 1);
        temp.push_back(val);
    }

    return temp;
}

// Function for t-test
double calculateTTest(double mean1, double mean2, double sampleSizeGroup1, double sampleSizeGroup2, double stdDevGroup1, double stdDevGroup2) {
    double differenceOfMeans = mean1 - mean2;
    double pooledVarianceNumerator = ((sampleSizeGroup1 - 1) * std::pow(stdDevGroup1, 2)) + ((sampleSizeGroup2 - 1) * std::pow(stdDevGroup2, 2));
    double pooledVarianceDenominator = sampleSizeGroup1 + sampleSizeGroup2 - 2;
    double pooledStandardDeviation = std::sqrt(pooledVarianceNumerator / pooledVarianceDenominator);

    double standardError = pooledStandardDeviation * std::sqrt(1 / sampleSizeGroup1 + 1 / sampleSizeGroup2);
    double tStatistic = differenceOfMeans / standardError;

    return tStatistic;
}


// Function for printing the top elements
void top_elements(const std::vector<double>& t, int x, int limit) {
    // Create a copy of the input vector and sort it in descending order
    vector<double> sorted_t(t);
    partial_sort(sorted_t.begin(), sorted_t.begin() + limit, sorted_t.end(), greater<double>());

    // Print the top elements
    for (int i = 0; i < limit; ++i) {
        cout << std::setprecision(3) << sorted_t[i];
        if (i < limit - 1) {
            cout << ", ";
        }
    }
    cout << std::endl;
}


vector<double> generate_random_numbers(int size, unsigned int seed, int k, double p) {
    mt19937_64 gen(seed);
    negative_binomial_distribution<int> distribution(k, p);

    vector<double> random_numbers;
    random_numbers.reserve(size);

    for (int i = 0; i < size; ++i) {
        double num = distribution(gen);
        random_numbers.push_back(num);
    }

    return random_numbers;
}

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "Invalid arguments" << argv[0] << " <n> <m> <s> <p> <k>" << endl;
        exit(1);
    }


    double p, m, n;
    unsigned int s, k;
    int x1 = 10, x2 = 10;
    vector<double> V1, V2, V3;

    n = atoi(argv[1]);
    m = atoi(argv[2]);
    s = atoi(argv[3]);
    p = atof(argv[4]);
    k = atoi(argv[5]);

    // Generating random numbers for V1
    V1 = generate_random_numbers(n, s, k, p);

    // Generate random numbers for V2
    V2 = generate_random_numbers(m, s * 2, k, p);

    // Generating indices for V3
    int value = 1;
    for(auto& item : V3) {
        item = value++;
    }


    // Get mean value, sd value, scale elements and print out elements
    double mean1 = get_mean(V1);
    double sd1 = getsd(V1, mean1);
    cout << "V1 Mean: " << setprecision(3) << mean1 << endl;
    cout << "V1 Sample standard deviation: " << setprecision(3) << sd1 << endl;
    vector<double> temp1 = scale_elements(V1);
    if (n < x1) {
        x1 = n;
    }
    if (m < x2) {
        x2 = m;
    }
    cout << "V1 Top " << x1 << " elements: ";


    mt19937_64 gen_1 (s), gen_2 (s*2), gen_3(s*7);
    top_elements(temp1, n, x1);
    double mean2 = get_mean(V2);
    double sd2 = getsd(V2, mean2);

    vector<double> temp2 = scale_elements(V2);

    double scaled_mean1 = get_mean(temp1);
    double scaled_sd1 = getsd(temp1, scaled_mean1);
    double scaled_mean2 = get_mean(temp2);
    double scaled_sd2 = getsd(temp2, scaled_mean2);

    //  Calling t-statistic

    double t_test = calculateTTest(mean1, mean2,  n, m, sd1, sd2);
    double scale_t_test = calculateTTest(scaled_mean1, scaled_mean2,  n, m, scaled_sd1, scaled_sd2);

    cout << "V2 Mean: " << setprecision(3) << mean2 << endl;
    cout << "V2 Sample standard deviation: " << setprecision(3) << sd2 << endl;

    cout << "V2 Top " << x2 << " elements: ";
    top_elements(temp2, m, x2);


    cout << "\nComparing V1 and V2..." << endl;
    cout << "Unscaled t-statistic: " << setprecision(3) << t_test << endl;
    cout << "Comparing log2 scaled V1 and V2..." << endl;
    cout << "Scaled t-statistic: " << setprecision(3) << scale_t_test << endl; scaled_sd1, scaled_sd2;

    cout << "Total degrees of freedom: " << (n+m-2) << "\n" << endl;

    // Shuffle using m-t algorithm
    shuffle(V3.begin(), V3.end(), gen_3);

    vector<double> even_vec , vec_odd;


    for (auto i = 0; i < n; ++i) {
        double value = V3[i] * temp1[i];
        if (static_cast<int>(round(value)) % 2 == 0) {
            even_vec.push_back(value);
        } else {
            vec_odd.push_back(value);
        }
    }

    // Sort vector
    sort(vec_odd.begin(), vec_odd.end());
    sort(even_vec.begin(), even_vec.end(), greater<double>());

    // We have to concatenate sorted even and odd vectors
    vector<double> sorted_vector;
    sorted_vector.insert(sorted_vector.end(), even_vec.begin(), even_vec.end());
    sorted_vector.insert(sorted_vector.end(), vec_odd.begin(), vec_odd.end());

    cout << "Sorted vector: ";
    for (auto x : even_vec) {
        cout << x << ", ";
    }
    int y = 0;
    for (auto x : vec_odd) {
        if (y == vec_odd.size() - 1) {
            cout << setprecision(3) << x << '\n' << endl;
        } else {
            cout << setprecision(3) << x << ", ";
        }
        y++;
    }
    return 0;
}












