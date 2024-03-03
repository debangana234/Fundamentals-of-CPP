a set of abstract methods without providing any implementation. It serves as a blueprint for classes that implement it. I## List 8 built-in types provided by C++. (2 P.)

    Integer(int), Boolean, Character(char), Integer(int), Floating point(float), Double Floating point(double), auto, String(string).
    
## What is the difference between an expression and a statement? Provide an example for each. (1 P.)
   
   Expression is a combination of values, variables and operators producing a single value. Example: a literal value like '5', variables or a combination of these along with operators
   'x+5' or '4+5'
   
   A statement executes a certain by specifying a line of code. A statement often ends with a semi colon. Statement can include declaration, assignment, control structures, function
   calls. Example:'y=x+2' 
   
   Difference between statement and expression:
   
   A statement is a unit that is executed but it may not return  a value whereas an expression always returns a value.
   
## What is type safety and why is it important? (1 P.)

   Type safety refers to the capability of the compiler to check whether we are using the correct types and casts. The language should prevent the users from accidentally mixing up
   the types.
   Type safety is important because it ensures that a variable can access only authorized memory locations in a predefined and permissible manner. It ensures that operations are   
   performed within compatible data types.
   
## When would a programmer prefer a switch-statement over an if-statement? (0.5 P.)
   
   When there are many conditions to be tested, a switch case is more efficient since it makes the code more readable. A switch case can also be preferred with enumerations.

## What is a common problem with switch statements? Provide an example. (1 P.)
   
   The problem with switch statement is that it works only with one type of condition, i.e. either an integer type or an enumeration or a string type.
    The same constant cannot be used in two cases.
   

      //A valid if-else block:
     
    if (x > y) {
        cout << "x is greater than y." << endl;
    } 
    else 
    {
        cout << "x is equal to y." << endl;
    }
   
   
      // An invalid switch statement:
   
     switch (x > y) {
        case true:
            cout << "x is greater than y." << endl;
            break;
        case false:
            cout << "x is less than or equal to y." << endl;
            break;
    }
     The switch statement would give us compilation error.
   
## Name one operation available for strings but not for integers and one operation available for integers but not for strings. (1 P.)
   The property of concatenation is available for strings but not for integers.

## Explain what are references and pointers. Provide examples for each. (2 P.)
   
   Pointer holds the memory address of another variable. It needs to be de-referenced with the '*' before being used.
   Reference variable is an alias for an existing variable. It is also implemented by storing the address of an object. 
   It can be thought of as a constant pointer with automatic indirection, i.e., the compiler applies the '*' by default.
   
    int i = 3; 

    // A pointer to variable i stores the address of i
    int *ptr = &i; 

    // A reference for i.
    int &ref = i; 

## Explain the relationship between pointers and arrays (and C-strings). Provide examples. (2 P.)
   
   An array is a contiguous block of memory. Individual elements of an array should be of the same type.
  
  
  
  Pointers are variables used to store the address : int* p.
  We can assign addresses to pointers in the following way:
  
    /* int* pc, c;
     c = 5;
     pc = &c; */

## Explain the pass by value and pass by reference concepts. Provide examples. (1 P.)

In Pass by value the method parameter values are copied to another variable and then the copied object is passed to the method. The method uses the copy.
 
      int add(int x)
      {
      int y = x+1;
      return y;
      }
      int main()
      {
      x = 2;
      int sum = add(x); // Pass by value
      }
    
     //if print sum is 3 and x is 2

In Pass-by-reference the reference of an argument in the calling function is passed to the corresponding  parameter of the called function. The called function can modify the  
value of the argument by using its reference passed in.

      int add(int *x)
      {     
      int y = *x+1;
      *x =  5;
      return y;
      }
      int main()
      {
      int x = 2;
      int sum = add(&x);
      }
     
     //if printed the out of sum is 3 but x is 5.

## Explain the terms declaration and definition. (1 P.)

Definition allocates memory to an entity. 
Declaration does not allocate memory to the entities.
We cannot keep repeating the process of definition more than once. 
Declaration can be repetitive and is possible at any given instance.


## What is a namespace and what is its typical use? (1 P.)

Namespace  provides a scope to the identifiers (the names of types, functions, variables) inside it.
Namespace is like the declarative region providing a scope for the identifiers.
The advantage of using namespace is that it prevents collision.

We might be writing some code that has a function called foo() and there is another library 
which also has the same function foo(). So the compiler has no way of knowing which version of foo() function we are referring to within our code.

## Why should you avoid using directives in a header? (0.5 P.)

We should avoid using directives in header files (*. h) because any file that includes that header will 
cause everything in the namespace to be included within the  scope. 
This can cause name hiding and name collision problems which are difficult to debug.

## List four kinds of errors and provide an example for each. (2 P.)

Syntax errors are compile time errors. They occur when we do not follow the writing 
techniques of a particular programming language.
e.g:
using namespace std;

      int main() {  
      cout << "Hello123!" // missing semicolon
      return 0;  
      }
Runtime errors occur when the program is running. Since this is not a compilation error, 
the compilation of the program will be completed successfully.
e.g: segmentation fault, divide by zero error.

Logical errors are the errors we get even if the syntax is correct.
In this case we don't get the desired results due to logical issues. 
e.g: A semicolon after a loop, is syntactically correct but results in one blank loop. 
In that case, it will not display the desired output.

Linker errors occur when the program is successfully compiled but 
we attempt to link the different object files with the main object file, 
Executables are not generated during linker errors.

## What is the free store and for what reasons might one use it? (1 P.)

The free store is one of the two dynamic memory areas, allocated/freed by new/delete. 
It is possible that the lifetime of an object is less than 
the time the storage is allocated. When this happens, then free store objects can have 
memory allocated without being immediately initialized, 
and can be destroyed without the memory being immediately deallocated.

## How do you allocate memory and about what do you need to be careful? Provide an example.

The new operator requests for memory allocation on the Free Store. 
If the required memory is available, the new operator initializes the memory 
and returns the address of the newly allocated and initialized memory 
to the pointer variable.
We need to be careful about 

Example:

      int *p = new int(95);
      float *q = new float(16.75);


## How do you safely allocate/manage memory? (1 P.)

Memory should be allocated during declaration but mostly we don't know the exact amount of memory that is required.
We can safely and dynamically allocate/free memory using the new and delete operator.

## What is RAII? (1 P.)

RAII is Resource Acquisition Is Initialization. 
Resource is something that has to be acquired and so it must be released. 
RAII binds the life cycle of a resource that should be available before use 
to the lifetime of an object. RAII also ensures that the resource 
is available to any function that may access the object.
