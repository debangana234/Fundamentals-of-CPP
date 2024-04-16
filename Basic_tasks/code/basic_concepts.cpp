//
// Created by Debangana Chakraborty on 16.02.24.
//
#include<iostream>
#include<vector>
using namespace std;

template <class In, class T>
In Find(In first, In last, T &x) {
    while (first != last && *first != x) {
        first++;
        return x;
    }
}

//find an element in a vector
void f (vector<int>vec,  int x)
{
    //vector<int> v = {1,2,3,4,5};
    vector<int>::iterator i = find(vec.begin(),vec.end(),5);
    if(i!= vec.end())
    {
        cout << "Data found in vector"<<endl;
    }
}
struct Node{ Node *next; int data;};

Node* push (Node **head, int node_data)
{
    Node *new_node = new Node();
    new_node -> data = node_data;
    new_node -> next = *head;
    *head = new_node;
    return *head;
}
void f( Node *head, int find_data)
{
    Node (*first) = head;
    //Node(*last) = nullptr;
    while(first -> next != nullptr && first ->data != find_data )
    {
        first++;
        cout <<"Data found in list!"<< endl;
    }
    cout<<"Data not found in list"<<endl;
}

//find an element in a list
int main()
{
    Node* first = nullptr;
    vector<int> v = {1,2,3,4,5};
    f(v,5);
    push (&first,6);
    push (&first,7);
    push (&first,4);
    push (&first,5);

    f(first, 5);



}


