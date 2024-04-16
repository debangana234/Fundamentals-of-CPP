#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

template<typename Predicate>
auto find_if(const vector<int> &v, Predicate pred)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (pred(v[i]))
            return i;
    }
    return -1;
}

int main() {
    vector <int> v = {1,2,3,4,5,6};
    int a = find_if(v,[](int i){ return i%2==0; });
    //cout<< "Hello World"<< endl;
    cout << a << endl;

};