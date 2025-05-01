# List

## Basic Characteristics

1. Store a given number of elements of a given data-type
2. Read element at a position
3. Write/modify element at a position
4. Insert element at a position
5. Delete element at a position

## Operations

1. Search for an element in the list
2. Sort the list
3. Reverse the list
4. Merge two lists
5. Split a list into two lists
6. Copy a list
7. Clear a list
8. Find the length of a list
9. Find the maximum element in a list
10. Find the minimum element in a list
11. Find the sum of all elements in a list
12. Find the average of all elements in a list
13. Find the median of all elements in a list
14. Find the mode of all elements in a list
15. Find the standard deviation of all elements in a list
16. Find the variance of all elements in a list
17. Find the range of all elements in a list
18. Find the frequency of all elements in a list
19. Find the frequency of a given element in a list
20. Find the index of a given element in a list
21. Find the last index of a given element in a list
22. Find the first index of a given element in a list...

## List in C/C++

```c
#include <stdio.h>
#define MAXSIZE 100 // Maximum size of the list
struct List {
    int A[MAXSIZE]; // Pointer to the array of elements
    int end = -1; //initial end of the list
};
 ```

## Benefits and Drawbacks of List

1. Easy to implement and use
2. Read - O(1) time complexity
3. Modify - O(1) time complexity
4. Insertion - O(n) time complexity
5. Deletion - O(n) time complexity
6. Addition - O(n) time complexity (if the list is full which is the worst case)
7. Memory usage - When array is full, create a new array of double size and copy the elements from the old array to the new array. Free the memory of the previous array. This is called **dynamic** array. Again memory remains allocated even if the list is empty. This is called **static** array.
