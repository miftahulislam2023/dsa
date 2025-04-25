# List

## Basic Characteristics:

1. Each node has data and a pointer to the next node
2. Head -  address of the head node gives us access of the complete list
3.  Head has no data but it points to the first node of the list
4.  Last node has data but it points to NULL (0) which indicates the end of the list

![Structure of a Linked List](./media/structure.jpg)

## Linked List in C/C++:
```c
#include <stdio.h>
struct Node {
    int data; //4 bytes
    Node* next; //C++ style - 4 bytes
    //struct Node* next; -> C style - 4 bytes
}; // End of Node structure
```
## Benefits and Drawbacks of Linked List:
1. Difficult to implement and use
2. Read - O(n) time complexity
3. Modify - O(n) time complexity
4. Insertion -
   1. At the **beginning** - O(1) time complexity
   2. At the **end** - O(n) time complexity
   3. At the **ith** position - O(n) time complexity
5. Deletion - O(n) time complexity
6. Addition - O(n) time complexity
7. Memory usage - No unused memory but extra memory for pointer variables. Memory may be available as multiple small blocks.