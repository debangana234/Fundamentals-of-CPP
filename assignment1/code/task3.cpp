#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>

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

double get_sd(const vector<double> &vec, double mean)
{
    double variance = 0.0;
    for (int i = 0; i < vec.size(); i++)
    {
        variance +=  pow((vec[i] - mean), 2);
    }
    variance/= vec.size() -1;
    return sqrt(variance);
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
    string input;
    vector<string> input_lines;

    while (getline(cin, input))
    {
        if (input.empty())
            break;
        else
            input_lines.push_back(input);
    }

    for (const string line : input_lines)
    {
        vector<double> input_vector;
        double data;

        istringstream number(line);
        while (number >> data)
        {
            input_vector.push_back(data);
        }

        sort(input_vector.begin(), input_vector.end());
        double median = get_median(input_vector);
        ostringstream medianStream;
        medianStream << fixed << setprecision(2) << median;
        median = stod(medianStream.str());

        double sum = get_sum(input_vector);
        ostringstream sumStream;
        sumStream << fixed << setprecision(2) << sum;
        sum = stod(sumStream.str());

        double mean = get_mean(input_vector, sum);
        ostringstream meanStream;
        meanStream << fixed << setprecision(2) << mean;
        mean = stod(meanStream.str());

        double stdDev = get_sd(input_vector, mean);
        ostringstream stdDevStream;
        stdDevStream << fixed << setprecision(2) << stdDev;
        stdDev = stod(stdDevStream.str());

        double firstQuartile = quartile_1(input_vector);
        ostringstream firstQuartileStream;
        firstQuartileStream << fixed << setprecision(2) << firstQuartile;
        firstQuartile = stod(firstQuartileStream.str());

        double thirdQuartile = quartile_3(input_vector);
        ostringstream thirdQuartileStream;
        thirdQuartileStream << fixed << setprecision(2) << thirdQuartile;
        thirdQuartile = stod(thirdQuartileStream.str());

        cout << median << " " << mean << " " << sum << " " << stdDev << " " << firstQuartile << " " << thirdQuartile << endl;
    }

    return 0;
}
