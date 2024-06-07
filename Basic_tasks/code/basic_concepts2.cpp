//
#include <iostream>
using namespace std;
#include <string>

bool dna (const string seq)
{
    string non_nucleotide_sequence = "DGBJKPOAGTC";
    bool temp = true;
    for(char x : non_nucleotide_sequence)
    {
        if(seq.find(x)!= string::npos)
        {
            temp = false;
            break;
        }
    }
    return temp;
}
    int main()
    {
        string x = "ATGC";
        cout << dna(x) <<endl;
    }



// Created by Debangana Chakraborty on 15.02.24.



