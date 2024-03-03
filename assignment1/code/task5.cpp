#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
using std::istringstream;
using std::ostringstream;

double get_sum(const vector<double> &vec)
{
    double sum = 0.0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum = sum + vec[i];
    }
    return sum;
}

double get_mean(const vector<double> &vec, double sum)
{
    double mean = 0.0;
    mean = sum / vec.size();
    return mean;
}


double get_median(vector<double> &vec)
{
    double median = 0.0;
    if (vec.size() == 0)
        return 0;
    else
    {
        if ((vec.size() % 2) == 0)
        {
            median = (vec[vec.size() / 2] + vec[vec.size() / 2 - 1]) / 2;
        }
        else
            median = vec[vec.size() / 2];
        return median;
    }
}

double quartile_1(const vector<double> &vec)
{
    double first_quartile = 0.0;
    vector<double> first_half;
    if (vec.size() == 0)
        return 0;
    else
    {
        for (int i = 0; i < vec.size() / 2; i++)
        {
            first_half.push_back(vec[i]);
        }
    }
    first_quartile = get_median(first_half);
    return first_quartile;
}

double quartile_3(const vector<double> &vec)
{
    double third_quartile = 0.0;
    vector<double> second_half;
    if (vec.size() == 0)
        return 0;
    else
    {
        int start_index = (vec.size() % 2 == 0) ? vec.size() / 2 : vec.size() / 2 + 1;
        for (int i = start_index; i < vec.size(); i++)
        {
            second_half.push_back(vec[i]);
        }
    }
    third_quartile = get_median(second_half);
    return third_quartile;
}

int main()
{
    vector<vector<double>> matrix;
    string input;

    // Read matrix from standard input
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

    vector<double> row;
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        row = matrix[i];

        sort(row.begin(),row.end());
        double sum = get_sum(row);
        ostringstream sumStream;
        sumStream << fixed << setprecision(2) << sum;
        sum = stod(sumStream.str());

        double mean = get_mean(row, sum);
        ostringstream meanStream;
        meanStream << fixed << setprecision(2) << mean;
        mean = stod(meanStream.str());

        double median = get_median(row);
        ostringstream medianStream;
        medianStream << fixed << setprecision(2) << median;
        median = stod(medianStream.str());

        double first_quartile = quartile_1(row);
        ostringstream first_quartileStream;
        first_quartileStream << fixed << setprecision(2) << first_quartile;
        first_quartile = stod(first_quartileStream.str());

        double third_quartile = quartile_3(row);
        ostringstream third_quartileStream;
        third_quartileStream << fixed << setprecision(2) << third_quartile;
        third_quartile = stod(third_quartileStream.str());

        cout << median << " " << mean << " " << sum << " " << first_quartile << " "
             << third_quartile << endl;
    }

    for (int j = 0; j < n; ++j) {
        vector<double> column;
        for (int i = 0; i < n; ++i) {
            column.push_back(matrix[i][j]);
        }
        sort(column.begin(), column.end());
        double sum = get_sum(column);
        ostringstream sumStream;
        sumStream << fixed << setprecision(2) << sum;
        sum = stod(sumStream.str());

        double mean = get_mean(column, sum);
        ostringstream meanStream;
        meanStream << fixed << setprecision(2) << mean;
        mean = stod(meanStream.str());

        double median = get_median(column);
        ostringstream medianStream;
        medianStream << fixed << setprecision(2) << median;
        median = stod(medianStream.str());

        double first_quartile = quartile_1(column);
        ostringstream first_quartileStream;
        first_quartileStream << fixed << setprecision(2) << first_quartile;
        first_quartile = stod(first_quartileStream.str());

        double third_quartile = quartile_3(column);
        ostringstream third_quartileStream;
        third_quartileStream << fixed << setprecision(2) << third_quartile;
        third_quartile = stod(third_quartileStream.str());
        cout <<  median << " " << mean << " " << sum << " " << first_quartile << " "
             << third_quartile << endl;
    }

    vector<double> diagonal;
    for (int i = 0; i < n; ++i) {
        diagonal.push_back(matrix[i][i]);
    }
    double sum = get_sum(diagonal);
    ostringstream sumStream;
    sumStream << fixed << setprecision(2) << sum;
    sum = stod(sumStream.str());

    double mean = get_mean(diagonal, sum);
    ostringstream meanStream;
    meanStream << fixed << setprecision(2) << mean;
    mean = stod(meanStream.str());

    double median = get_median(diagonal);
    ostringstream medianStream;
    medianStream << fixed << setprecision(2) << median;
    median = stod(medianStream.str());

    double first_quartile = quartile_1(diagonal);
    ostringstream first_quartileStream;
    first_quartileStream << fixed << setprecision(2) << first_quartile;
    first_quartile = stod(first_quartileStream.str());

    double third_quartile = quartile_3(diagonal);
    ostringstream third_quartileStream;
    third_quartileStream << fixed << setprecision(2) << third_quartile;
    third_quartile = stod(third_quartileStream.str());

    cout << median << " " << mean << " " << sum << " " << first_quartile << " "
         << third_quartile << endl;

    vector<double> lower_diagonal;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            lower_diagonal.push_back(matrix[i][j]);
        }
    }
    sort(lower_diagonal.begin(), lower_diagonal.end());
    if(!lower_diagonal.empty()) {
        double sum = get_sum(lower_diagonal);
        ostringstream sumStream;
        sumStream << fixed << setprecision(2) << sum;
        sum = stod(sumStream.str());

        double mean = get_mean(lower_diagonal, sum);
        ostringstream meanStream;
        meanStream << fixed << setprecision(2) << mean;
        mean = stod(meanStream.str());

        double median = get_median(lower_diagonal);
        ostringstream medianStream;
        medianStream << fixed << setprecision(2) << median;
        median = stod(medianStream.str());

        double first_quartile = quartile_1(lower_diagonal);
        ostringstream first_quartileStream;
        first_quartileStream << fixed << setprecision(2) << first_quartile;
        first_quartile = stod(first_quartileStream.str());

        double third_quartile = quartile_3(lower_diagonal);
        ostringstream third_quartileStream;
        third_quartileStream << fixed << setprecision(2) << third_quartile;
        third_quartile = stod(third_quartileStream.str());

        cout << median << " " << mean << " " << sum << " " << first_quartile << " " << third_quartile << endl;


    }

    return 0;

}

