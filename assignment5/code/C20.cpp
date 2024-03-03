
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;


/*int main()
{
    set <string> s = {"Cat", "Dog", "Horse", "Pig"};
    auto itr = s.find("Cat");
    if(itr != s.end())
    {
        string s1 = *itr;
        s.erase(itr);
        s1= "Lion";
        s.insert(s1);


    }
    for(auto x: s)
    {
        cout << x << endl;
    }
   // vector <int> v = {1,2,34,5};
    //sort(v.begin(),v.end());
    //for (auto x : v)
   // {
     //   cout << x << endl;
    //}
}*/


/*int main()
{
    int divisor = 30;
    auto d = [&divisor] (int value){return value % divisor;};
    divisor = 100;
    cout << d(100) << endl;
}*/


//Friend function

/*class A
{
private:
    int i;
public :
    A (int value): i(value){};
    friend int increment(int i);
};

int increment(int i)
{
    return (++i);
}

int main()
{
    int i = 10;
    A a(10);
   cout<<  increment(i) << endl;
}*/


bool greater_than (string *s1, string *s2)
{
    return *s1 > *s2;
}

int main()
{
  string lhs = "Dat";
  string rhs = "Cog";
  cout << greater_than(&lhs,&rhs) << endl;
}



