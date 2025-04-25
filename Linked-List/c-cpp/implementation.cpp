#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
int main()
{
    Node *A;
    A = NULL;                // empty list
    Node *temp = new Node(); // temp pointer to create new nodes
    /*
        Node *temp = (Node *)malloc(sizeof(Node));
        allocate memory for a new node
        and assign it to temp pointer
        here malloc returns a void pointer
        so we need to typecast it to Node pointer
        same as
    */
    temp->data = 2; // same as (*temp).data = 2;
    temp->next = NULL;
    A = temp;          // A points to the first node
    temp = new Node(); // create a new node
    temp->data = 3;    // assign data to the new node
    temp->next = NULL; // assign next pointer to NULL
    Node *temp1 = A;
    /*
        temp1 is created to traverse the list
    */
    while (temp1->next != NULL) // traverse the list to find the last node
    {
        temp1 = temp1->next; // move to the next node
    }
    temp1->next = temp; // link the new node to the last node
}
/*
    caution -  A is never modified
*/