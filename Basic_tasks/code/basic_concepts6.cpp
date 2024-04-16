//
// Created by Debangana Chakraborty on 17.02.24.
//
#include <iostream>
#include <string>
#include<set>
using namespace std;

template <typename T, int n>
class Array
        {
private:
    T arr[n];
public:
            //Array(int size_array);
    int size_array () const {return n;};
};


int main()
{
    Array<int, 6> a;
    cout << a.size_array()<<endl;
} 

class Complex{
public:
    float real;
    float imaginary;
    Complex(float r = 0, float i =0 ) : real(r), imaginary(i) {}

   Complex add_complex (const Complex &other) ;



};


Complex  add_complex(Complex complex_number1, Complex complex_number2)
{
    Complex sum = Complex(0, 0);
    sum.real = complex_number1.real + complex_number2.real;
    sum.imaginary = complex_number1.imaginary + complex_number2.imaginary;
    return sum;
}

int main()
{
    Complex complex_number1(9.8, 5.0);
    Complex complex_number2(8.9, 5.0);

    Complex  complex_sum = complex_number1.add_complex(complex_number2); // Adding two complex numbers

    std::cout << complex_sum.real<< " "<< complex_sum.imaginary<< " " <<endl;
    return 0;
} 



#include <iostream>

class Complex {
public:
    float real;
    float imaginary;

    // Constructor with default arguments
    Complex(float r = 0, float i = 0) : real(r), imaginary(i) {}

    // Member function to add two Complex numbers
    Complex add_complex(const Complex &other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
};

int main() {
    Complex complex_number1(9.8, 5.0);
    Complex complex_number2(8.9, 5.0);

    // Using the member function to add two complex numbers
    Complex complex_sum = complex_number1.add_complex(complex_number2);

    std::cout << complex_sum.real << " " << complex_sum.imaginary << std::endl;
    return 0;
} 

template <typename T>
T add(T a, T b)
{
   return (a+b);
}


int main()
{
    cout << add (14, 15)<< endl;
    cout<< add(14.5, 15.5)<<endl;
} 


