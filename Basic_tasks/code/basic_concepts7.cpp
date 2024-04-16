#include <iostream>
#include <string>
#include<set>
using namespace std;


class DerefCompare{
       bool operator()(const string **s1, const string **s2) const { return *s1 > *s2;}
    };
int main()
{
    set <std::string,DerefCompare > myset;
    string str1= "Debangana";
    string str2 = "Chakraborty";
    string str3 = "Paul";
    myset.insert(str1);
    myset.insert(str2);
    myset.insert(str3);


}