# SkipList Implementation in C++
This project implements a Skip List data structure in C++. Skip List is a probabilistic data structure that allows for efficient searching, insertion, and deletion operations in logarithmic time.
### Contents
Introduction
Implementation Details
Compilation
Usage
Example

### Introduction
Skip List is a data structure that maintains a sorted set of elements. It utilizes multiple layers of linked lists to achieve logarithmic time complexity for search, insertion, and deletion operations. The structure is designed to provide a balance between simplicity and efficiency.

### Implementation Details

The C++ implementation includes structures for Node and skipList.
The Node structure represents each element in the Skip List, containing a value and an array of pointers to the next elements in different levels.
The skipList structure represents the Skip List itself, including methods for searching, inserting, deleting, and displaying elements.

### Compilation
Compile the project using a C++ compiler. For example, using g++:
```
g++ main.cpp -o skip_list
```
### Usage
Include the necessary header files: <iostream>, <cstdlib>, <cmath>, <cstring>.
Define the maximum level of the Skip List (MAX_LEVEL) and the probability constant (P).
Create a skipList instance to start using the data structure.
Use the insert, delete_node, search, and display methods to manipulate and view the Skip List.

### Example
```
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

// ... (Include Skip List Implementation)

int main() 
{
    skipList skiplist1;
    int n;
    skiplist1.insert(n = 55);
    skiplist1.insert(n = 3);
    skiplist1.insert(n = 66);
    skiplist1.insert(n = 2);
    skiplist1.insert(n = 99);
    skiplist1.insert(n = 2);
    skiplist1.insert(n = 6);
    skiplist1.insert(n = 11);
    skiplist1.insert(n = 23);
    skiplist1.insert(n = 97);
    skiplist1.display();
    skiplist1.delete_node(n = 66);
    skiplist1.display();
    return 0;
}
```
