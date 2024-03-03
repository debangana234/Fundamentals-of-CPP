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



vector<double> scaling(const vector<double> &vec)
{
    double sum = get_sum(vec);
    vector<double> scaled_vector;
    for (int i = 0; i < vec.size(); i++)
    {
        scaled_vector.push_back(vec[i] / sum);
    }
    return scaled_vector;
}


void display_vector(vector <double> scaling_vector) {

    double number;
    int i = 0;
    while(i < scaling_vector.size()) {
        ostringstream vectorstream;
        vectorstream << fixed << setprecision(2) << scaling_vector[i];
        number = stod(vectorstream.str());


        cout << number;
        if (i < scaling_vector.size() - 1) {
            cout << " ";
        } else
            cout << endl;
        i++;

    }


}

int main()
{
    string input;
    vector<string> input_lines;
    vector <string> :: const_iterator i;
    vector <double> scaling_vector;
    while (getline(cin, input))
    {
        if (input.empty())
            break;
        else
            input_lines.push_back(input);
    }

    for ( i = input_lines.begin(); i< input_lines.end(); i++ )
    {
        vector<double> input_vector;
        double data;

        istringstream number(*i);
        while (number >> data)
        {
            input_vector.push_back(data);
        }

        scaling_vector = scaling(input_vector);
        display_vector(scaling_vector);
    }



    return 0;
}
