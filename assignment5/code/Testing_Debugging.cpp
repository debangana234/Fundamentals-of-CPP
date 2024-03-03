//
// Created by Debangana Chakraborty on 17.02.24.
//
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 //calculate factorial
long FactorialNumber(int n)
{   long fact = 1;
    while (n>1)
    {
        fact = fact * n;
        n = n-1;
    }
    return fact;

}
int main()
{
    cout<< FactorialNumber(5) << endl;
}

//calculate fibonacci
long Fibonacci(int n)
{   long fact = 1;
    while (n>1)
    {
        fact = fact * n;
        n = n-1;
    }
    return fact;

}