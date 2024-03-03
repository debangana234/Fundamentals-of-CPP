
##  Why is it dangerous to return a reference when you must return an object?

Returning a reference can be dangerous as compared to returning an object in the following situations:

In case of dangling references. If the reference returned by a function refers to a local object within that function, the object will be destroyed when the function exits
Therefore, the reference points to a memory location that no longer holds the valid object. Accessing such a reference can lead to undefined behavior.

Memory Management Confusion: When a function returns a reference,it's not clear who owns the object being referred to or who 
should deallocate it (if it was dynamically allocated). This can lead double deletion or memory leaks, which could cause the program to crash.

## What is an implicit interface in the context of compile-time polymorphism?

An implicit interface in the context of compile-time polymorphism, is a concept where the interface of an object or function is not explicitly defined through an abstract class or interface, 
but it is determined by the syntax and semantics of its usage. This is associated with the concept of templates and generic programming.
Template Programming: Template can operate on types that are not specified until the template is instantiated.
They are used to implement compile time polymorphism.
Implicit Interface: When we write a template function, we don’t explicitly specify an interface like we would do in inheritance(base classes). 
The implicit interface is composed of operations performed on the template arguments.
Compile-Time Checking: The compliance with the implicit interface is checked at compile time. 
If a type does not fulfill the specifications of the implicit interface (for example, it lacks necessary operators or functions), the code will not compile.
This approach offers stability and leads to more efficient code as the compiler can optimize specific instances of templates.

## Why should you prefer range member functions to their single-element counterparts?

We prefer range member functions as compared to their single-element counterparts for the following reasons:
Efficiency: Range member functions provide better performance. For example,
while inserting or deleting elements in a container, a range-based operation can optimize memory allocations and deallocations.
Instead of adjusting the container size for each element, a range-based function can do it at once for the entire range. This results in increased efficiency.

Readability and Maintainability: Instead of writing a loop to insert or delete elements one by one, 
a single line of code using a range member function can achieve the same result. 

Algorithmic Clarity: Range functions make the intent of the code clearer. For example, 
std::copy(begin, end, destination) states that a range of elements is being copied from one location to another.

Error Reduction: When we use range functions, the chance of occurence of off-by-one errors or other common mistakes associated with manual iteration is less.

## Why should you avoid in-place modification of keys in a set?

In-place modification of keys in a set in C++ should be avoided because it can lead to undefined behavior by breaking the internal ordering and invariants of the container. 
The safe way to modify an element is to remove it, modify it, and then re-insert it.

Violation of Container Invariants: Set is typically implemented as a balanced binary tree. The order of elements in a set is determined by the key values 
and a specified comparison function. This order is required for efficient operation of the set. If we modify a key directly while it is in the set, we could disrupt this order, which would violate the invariants of the set. 
This can lead to undefined behavior.

Breaks Binary Search Tree Properties: A set relies on the ordering of its elements for the operations. Therefore, modifying an element in place can break the binary search tree property. 
This could lead to a loss in the sorted structure of the binary search tree. This could lead to incorrect results or failures when performing operations like searches or insertions.

## Why should predicate functions be pure?

A pure function is a function that, given the same input, will always return the same output and does not modify global state or input arguments. Purity is important for predicate functions for the following reasons:

Pure functions are predictable. Since they return the same output for the same input and do not depend on or alter any state outside their scope, 
they are much easier to reason about. This predictability is important for predicates used in algorithms that rely on consistent behavior to function correctly.

Pure functions can be reused and composed. Since they don’t rely on external state, they can be used in different contexts without worrying about the environment in which they are executed.

We can perform parallel execution with pure functions. Since they don’t rely on or modify shared state, there are no race conditions or other concurrency issues that we need to consider.

Pure functions are easier to test and debug since their behavior is solely dependent on their inputs. There are no hidden dependencies or states to consider. 


## Why should you avoid the default capture modes of lamdbas?

Avoiding default capture modes could help us in the following ways:
Explicitness and Readability: Using default capture modes makes it less clear which variables are actually being used inside the lambda. 
The lack of explicitness can make the code more difficult to read and understand. Explicitly capturing only the variables that are needed makes the code more self-documenting and easier to maintain.

Avoiding Unintended Captures: Default capture modes can lead to acidentally capturing more variables than intended, which can lead to bugs.
For example, capturing by reference could lead to the problem of dangling references.

Managing resources needs to be done efficiently. When we capture by reference using, we must ensure that the lambda does not outlive the captured references. 
This can be problematic with asynchronous operations or callbacks. Capturing by value can be safer in such scenarios, 
but it also means we need to be aware of the lifetime and copy semantics of the captured objects.

## What do std::move and std::forward do?

std::move is used to indicate that an object  may be moved from (allowing the efficient transfer of resources) from the current object to another object.

It effectively converts its argument into  rvalue reference, enabling the move constructor or move assignment operator of the receiving object to be invoked.
````
string a = "Hello";
string b = move(a);  // calls the move constructor of std::string
````
After move is called, 'a' is in a valid but unspecified state. This means we cannot make assumptions about its value or state, but we can assign a new value to it or destroy it.
It casts its argument to rvalue only if that argument is bound to  rvalue. This is key in template functions where we don't know in advance if the arguments will be lvalues or rvalues.

std::forward is used in the context of template programming and perfect forwarding. It preserves the lvalue or rvalue of a function argument, enabling us to forward it correctly to another function.

````
template<typename T>
void wrapper(T&& arg) {
    func(std::forward<T>(arg));  // Forwards arg to func preserving its value category
}
````
## How are the strings of a std::set<std::string*> sorted? How you would make them sorted lexicographically? Provide the necessary code.

std::set is implemented as a binary search tree (usually a Red-Black tree) and elements in the set are automatically sorted according to a comparison function.
By default, this comparison function is std::less, which for pointers (like std::string*) compares the addresses they point to, not the values they point at. 
Hence, a std::set<std::string*> will sort the pointers based on their memory addresses, not the string content they refer to.

To sort the std::string* pointers lexicographically based on the strings they point to, we would need to provide a custom comparator that dereferences the pointers and compares the strings.

````

struct DerefCompare {
    bool operator()(const std::string* a, const std::string* b) const {
        return *a < *b;
    }
};

int main() {
    std::set<std::string*, DerefCompare> mySet;

    std::string str1 = "Debangana";
    std::string str2 = "Chakraborty";
    std::string str3 = "C++";

    mySet.insert(&str1);
    mySet.insert(&str2);
    mySet.insert(&str3);

    for (const auto& ptr : mySet) {
        std::cout << *ptr << std::endl;
    }

    return 0;
}
````

DerefCompare is a custom comparator struct that overloads the () operator. 
It takes two std::string* pointers, dereferences them, and compares the strings they point to.

The std::set is declared with DerefCompare as the comparator, so it will use this to sort the std::string* pointers based on the string values.

When we insert string pointers into the set, they will be sorted based on the actual string content, not their addresses.
