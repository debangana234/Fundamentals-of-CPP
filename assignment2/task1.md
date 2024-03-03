## What is the difference between a struct and a class?
Struct is  used for typically simple data types and do not have complex behavior associated with them.
Data Members are defaultly public.
Inheritance is public by default

```
struct ComplexNumber
{
int real;
float imaginary;
}
```
    


Class is used to encapsulate data and attributes together, to control access to the data through member functions.We can access the
data members and the member functions of the class by creating instances of the class known as objects.
Data members are by default private.
Inheritance is private by default.

```class Point {
int x;
int y;

public:
// functions can provide controlled access to the data members
int getX() const { return x; }
int getY() const { return y; }
};
```

## Why should the public interface to a class be as small as possible?

The public interface of the class should be kept small following the principle of encapsulation.

It promotes abstraction, allowing users of the class to focus on what the class does rather than how it does it. 
This in turn simplifies the complexity.

Hiding implementation details from the external users.

Provides increased flexibility to modify the internal implementation of the class without affecting its users.

It ensures fewer methods to test.

## What is the difference between const and static?

Const ensures immutability. Const assures that a variable or a member function doesn't modify the data it refers to.
Static variables are shared among instances or function calls, and static member functions operate on class-level rather than instance-level.


Const does not affect memory allocation directly. It specifies how the variable should be used. 
Static influences memory allocation by indicating that the variable or function has static storage duration, which refers to its persistence during the duration of program execution.

## Why should you distinguish between functions that modify objects and those that do not?
Distinguishing between functions that modify data and functions that provide only access to data is important for the developers to understand
whether a particular function  modifies the object's state or just provides access to its data.

This approach makes debugging easier.

It simplifies the maintenance and update of code.

This promotes encapsulation. Accessor functions allow controlled access to the objects, this in turn promotes encapsulation by hiding implementation details.


## What is the concept and effect of inline functions? When would you prefer inline functions over function calls?

An inline function, at the compiler's discretion, is expanded inline at the point of the function call.
rather than being invoked through a regular function call mechanism. So we can avoid the overhead associated with a traditional function call.

Inline functions are preferred when the functions are small and simple.
They are preferred when a function is called frequently. They are preferred in performance-critical code sections where the efficiency of a function call is an important factor to consider.

````
inline int add(int a, int b) {
    return a + b;
}

int main() {
    int sum = add(1,2);  // inline function expanded during function call
    cout << "Addition: " << sum << endl;
    
    return 0;
}
````

## What is a destructor and when is it called? What is the typical consequence of its usage?

A destructor is a special member function of the class. It is responsible for clearing up resources when an object goes out of scope or is  deleted.
It has the same name as the class, preceded by a tilde (~). 
The compiler calls it by default when an object is destroyed.

Destructors are crucial in implementing RAII(Resource Aquisition is Initialization), where resource acquisition and release are tied to object lifetimes. 
This ensures that the code written is more robust and exception-safe.
```
class Test {
public:
    // Constructor
    Test() {
        // Initialization code
    }

    // Destructor
    ~Test() {
        // Code to cleanup
    }
};
```

## In which context are virtual functions used? (1 P.)

Virtual functions are used in the context of polymorphism and dynamic dispatch.

Polymorphism:
A fundamental concept in object-oriented programming. Polymorphism implies objects of different derived classes being treated as objects of the same base class. This provides a common interface for diverse types.

Dynamic Binding: This is also known as runtime polymorphism. With virtual functions, the decision about which function to call is made at runtime based on the actual type of the object, the arguments passed.

They are also used in the context of Interfaces and abstract classes.

Function Overriding: Virtual functions in derived classes override the base class functions, allowing for customization of the function in each derived class. This enables a high level of flexibility and extensibility.

```
class Shape {
public:
    virtual void area() const {
        // Base class function
    }
};

class Circle : public Shape {
public:
    void area() const override {
        // implementing the virtual function in derived class
    }
};

class Square : public Shape {
public:
    void area() const override {
        // implementing the virtual function in derived class
    }
};
```

## What is the semantic result of combining the keywords friend and virtual for a class function? Explain and state reasons for your observations. (1 P.)

The friend keyword grants non-member functions or other classes access to the private and protected members of a class. 
When a function is declared as a friend of a class, it can access the private and protected data members of that class.
Virtual keyword is used in the context of polymorphism and object-oriented programming.

On combining these two keywords, we get the following semantic implications:
Provides access to private members and also ensures that the function can be overridden in derived classes.
We could combine the friend and virtual keywords in scenarios where a non-member function needs to be part of the polymorphic behavior of a class, and that function requires access to private members.

I would write that it is possible to combine the keywords 'virtual' and 'friend' at the cost of reducing the encapsulation because a non-member function (even if it's a friend) is granted access to private members.

## When would you make a virtual member function pure?

A virtual member function is pure when the base class intends to declare an interface 
without specifying a default implementation. 
It is also known as an abstract function. It is like a blueprint for derived classes, indicating that the derived class should provide a customized implementation for the pure virtual function.

We could make a virtual member function pure in the following scenarios:

Creating an Abstract Base Class.
```
class Shape {
public:
    virtual void area() const = 0;  // Pure virtual function
};
```
When the derived class should implement specific functionalities:

````
class Shape {
public:
    virtual void area() const = 0;  // Pure virtual function
};

class Derived : public Shape {
public:
    void area() const override {
        // Derived class implementation
    }
};
````
When we want to facilitate the property of Run Time Polymorphism.

## What are pitfalls of multiple inheritance?

Multiple inheritance in C++ allows a class to inherit from more than one base class. 

One issue is the "diamond problem." It occurs when a class is inherited from two classes that share a common base class. In this case, the compiler might be uncertain about which version of the shared base class to use.

````
class A {
public:
    void foo() {}
};

class B : public A {};
class C : public A {};

// Diamond problem
class D : public B, public C {};
````
Increased code complexity.

If multiple base classes have members with the same name, then there could be name clashes in the derived class.

## What is the difference between a concrete class and an interface?

A concrete class provides a concrete implementation for all the methods. 
It can be instantiated, and objects can be created from it. 
Concrete classes can have attributes, fields, and methods with actual code.
While an interface serves as a set of abstract methods without providing any implementation. It serves as a blueprint for classes that implement it. 

Instances (objects) can be created from a concrete class while 
Interfaces cannot be instantiated on their own.