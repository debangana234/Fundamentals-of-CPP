#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

double get_sum(const vector<double> &vec)
{
    double sum = 0.0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum = sum + vec[i];
    }
    return sum;
}

double get_mean(const vector<double> &vec)
{
    return get_sum(vec) / vec.size();
}

double get_sd(const vector<double> &vec, double mean)
{
    double variance = 0.0;
    for (int i = 0; i < vec.size(); i++)
    {
        variance += pow((vec[i] - mean), 2);
    }
    variance /= vec.size() - 1;
    return sqrt(variance);
}

vector<double> standardize(const vector<double> &vec)
{
    vector<double> standardized_vec;
    double mean = get_mean(vec);
    double stddev = get_sd(vec, mean);

    for (int i = 0; i < vec.size(); i++)
    {
        double zscore = (vec[i] - mean) / stddev;
        standardized_vec.push_back(round(zscore * 100.0) / 100.0);
    }

    return standardized_vec;
}

vector<vector<double>> transpose_matrix(const vector<vector<double>> &a)
{
    vector<vector<double>> trans(a[0].size(), vector<double>(a.size()));
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            trans[j][i] = a[i][j];
        }
    }
    return trans;
}

void display_matrix(const vector<vector<double>> &matrix)
{   double value;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            ostringstream vectorstream;
            vectorstream << fixed << setprecision(2) << matrix[i][j];
            value = stod(vectorstream.str());
            cout << value;
            if (j < matrix[i].size() - 1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
    }
}

int main()
{
    vector<vector<double>> matrix;
    string input;

    // Getting the matrix from standard input
    while (getline(cin, input))
    {
        if (input.empty())
            break;

        vector<double> vec;
        double number;
        istringstream numbers(input);
        while (numbers >> number)
        {
            vec.push_back(number);
        }
        matrix.push_back(vec);
    }

    vector<vector<double>> transposed_matrix = transpose_matrix(matrix);
    vector<vector<double>> standardized_matrix;

    // Standardizing every column
    for (const auto &column : transposed_matrix)
    {
        standardized_matrix.push_back(standardize(column));
    }

    // Transpose the standardized matrix for display
    vector<vector<double>> transposed_standardized_matrix = transpose_matrix(standardized_matrix);

    // Display the result
    display_matrix(transposed_standardized_matrix);

    return 0;
}