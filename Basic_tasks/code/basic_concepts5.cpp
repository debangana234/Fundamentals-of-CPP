//
// Created by Debangana Chakraborty on 16.02.24.
//
#include<set>
#include<unordered_map>
#include<map>
#include <algorithm>
#include<string>
#include <iostream>

using namespace std;
int main()
{
    //std::set <int> s = {1,2,3,4,5,6};
    map <string,int> Employee={{"sdjd",44},{"dfgh",89}};
    vector<int> v = {1,2,3,4,5,6,7,8};
    for( auto it :Employee)
    {
        cout<<it.first<<"   "<<it.second<< endl;
    }
    Employee["Debangana"] = 26000;
    for( auto it :Employee)
    {
        cout<<it.first<<"   "<<it.second<< endl;
    }
    auto itr = Employee.find("Debangana");
    if(itr != Employee.end())
    {
        cout<< itr->second<<endl;
    }

   v.erase(remove_if(v.begin(),v.end(),[=](auto p){return p % 2 ==0;}), v.end());
    v.erase(remove(v.begin(),v.end(),3),v.end());

    for(auto i =0; i < v.size(); ++i)
   {
       cout<< v[i]<< endl;
   }
}

