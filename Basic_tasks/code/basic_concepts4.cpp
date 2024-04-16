//
// Created by Debangana Chakraborty on 16.02.24.
//
#include<iostream>
#include<vector>
#include<list>

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

void f(list<double>li, int x )
{
    __list_iterator<double, void *> itr = find(li.begin(), li.end(), 5);
    if(itr != li.end())
    {
        cout <<"Data found in list"<<endl;
    }
    else
    {
        cout<< "Data not found in list"<< endl;
    }
}

//illustrate the working of predicates and lamdba functions
auto Odd= [](int i){return i % 2;};

void find_odd(vector<int>vec)
{

    auto x = find_if(vec.begin(),vec.end(),Odd);
    if(x != vec.end())
    {
        cout<< "We found an odd number";

    }
    else
    {
        cout<< "Odd number not there in vector"<<endl;
    }
}

int main()
{
    vector<int> vec = {2,4,6,8};
    list<double> li ={3,4,5,6};
    f(vec,5);
    f(li,5);
    //auto Odd= [](int i){return i % 2;};
    find_odd(vec);
}