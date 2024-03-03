//
#include <iostream>
using namespace std;
#include <string>
/*double sum(double array[], int n)
{
    double s =0;
    for (int i = 0; i < n; ++i)
        s = s + array[i];
    return s;
}
struct Node {double data; Node* next;};

//assigning elements to the list
void push(Node **first, double node_data)
{
    Node * new_node = new Node();
    new_node -> data = node_data;
    new_node -> next = (*first);
    (*first) = new_node;
}
double sum1(Node* first)
{
    double s =0;
    while(first)
    {
        //s+= first -> data;
        //first = (first)-> next;

        s += (*first).data;
        first = (*first).next;
    }
    return s;
}
int main()
{   Node* first = nullptr;
    push (&first, 1);
    push (&first, 2);
    push (&first, 3);
    push (&first, 4);

    cout << sum1(first)<< endl;

}*/

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



