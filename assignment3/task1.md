
## What is the difference between the keywords typedef and using? Also, state one usage example for both.

Using is a modern way to create aliases. 

````
typedef double (*Operation)(double, double);
````
Typedef can create a level of abstraction from the actual types being used. It creates an alias.
In the above example, an alias Operation is created for the pointer to the function that takes two double parameters and returns a double.
This makes it easier to work with such function pointers.

Using is a more modern way of creating aliases. The syntax looks clearer than the syntax of typedef 
````
using Operation = void (*)(int, float);
````
Template aliasing can be done with using, allowing more complex type manipulations which typedef does not support.
We can say that the syntax is more intuitive in case of using when we need to alias more complex types.

## What are iterators? Name at least 3 different types of iterators and explain their functionalities. (1 P.)

An iterator is a type element that supports the iterator operations.
An iterator can be used for the following tasks:

To goto the next element (++), get the value(*) and does this iterator point to the same element as the other iterator.
Three different types of iterators are:

Input iterators: They can move forward through a range of elements and can support reading from a sequence, but not writing.
Typical operations include *iter (dereferencing to read the value, ++iter (increasing the value).  e.g. reading elements from an input stream.

Output iterators: They can move forward and are used for writing to a sequence, but not reading. e.g. Writing elements to an output stream.

Forward Iterators: They support both read and write operations. They can be used in algorithms where each element is processed once.
e.g. *iter, ++iter.

## What is a crucial difference between an input and a forward iterator? (0.5 P.)

Input Iterators work for a single pass through a range. We cannot use an input iterator to read the same sequence of elements more than once.
Forward Iterators support multiple passes over the same range. They iterate through a range, reset to the beginning and then iterate through the same range again. 

## Why are iterators to a std::vector invalided by insert, push_back or erase? (0.5 P.)

Iterators to a <std::vector> in C++ can be invalidated by operations like insert, push_back, or 
erase due to the underlying implementation of the std::vector container, 
which involves dynamic array allocation.  Due to the contiguous and dynamic nature of the memory allocation in <std::vector>, operations 
that change the size of the vector can invalidate iterators because these iterators either point to 
a previous memory location (when objects are reallocated) or have their pointed-to elements moved 
(when we use erase).

## Which container would you choose and why if
## a) you need to do sorted traversal and no duplicates are allowed (0.5 P.)

We could the <std::set> container since it does not allow duplicate elements. This container also allows efficient lookup, insertion and deletion operations.


## b) the order is not important and no duplicates are allowed (0.5 P.)

When you have to preserve the uniqueness of elements occurring in any order, and we want efficient insertions, deletions <std::unordered_set> can be used due to its use of hashing and its performance characteristics.


## c) you only need to add elements at the end and want fast traversal (0.5 P.)

<std::vector> provides a very efficient way to add elements at the end via the push_back method.
This container stores its elements contiguously in the memory which is ideal for fast traversal.
Also supports random access of elements directly by their index in constant time.

## d) you need to provide a dictionary that can associate multiple values with the same key (0.5 P.)

We could use  the container <std::unordered_multimap> . The sorting is by default in ascending order, but you can select a custom order.

## How does an STL algorithm usually indicate "not found" or "failure"? (0.5 P.)

Algorithms typically indicate "not found" or "failure" by returning an iterator to the end of the container. 
This is not an iterator to the last element, rather an iterator that represents a position one previous to the last element of the container.

````
vector<int> vec = {5,1,2,3,5;
auto ptr = std::find(v.begin(), v.end(), 10); // Searching for the element '10'
if (ptr == v.end()) {
    // '10' was not found in the vector.
}
````

## What does std::sort(b,e) use as its sorting criterion? (0.5 P.)?

std::sort(b, e) uses the "less than" (<) operator as its default sorting criterion.
The sorting is based on the operator < applied to the elements present in the range. THis means that an element a will be placed before an element b if a < b is true.

##  Why is the STL container set missing a [] (subscript) operator? (0.5 P.)

The absence of a subscript operator in <std::set>  aligns with the container's purpose of efficiently managing sorted, unique elements, and maintaining the integrity of its internal structure.
In  <std::set>, the value of an element is the key that identifies it in the set. This is used to organize and retrieve the elements.
If it is allowed direct access and modification of its elements via a subscript operator, it could potentially disrupt the internal ordering.

## Why does std::map require its key_type to be copy-constructible and its mapped_type to be default constructible? (1 P.)?

The requirement for mapped_type to be default constructible arises from the fact that <std::map> handles element access, particularly with its subscript operator [].
When we access an element in <std::map> using the subscript operator with a key that does not exist in the map, the map automatically inserts a new element with that key. The value of this new element is default-constructed.
Therefore, we can access and modify elements in a map in a convenient and intuitive way.

## Why is std::forward_list missing a size member function and why is the empty member-function still implemented if it is typically equal to container.size() == 0? (1 P.)

<std::forward_list> is designed differently, and this is reflected in its choice of member functions. There is no size member function and the presence of an empty member function indicate its unique characteristic.
<std::forward_list> implements a singly linked list which does not keep track of its size explicitly.
This requires traversing the entire list to count the elements, which is O(n) operation. This is against the principle of providing a constant-time complexity for common operations in other containers.


The empty function is provided because it can be implemented to run in constant time. It checks whether the list's head pointer is null, indicating an empty list.
The efficiency of empty makes it a better choice for checking if the list has no elements, unlike the inefficient operation of calculating the size