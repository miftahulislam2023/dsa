#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// Insert at the end of the list
void insert(struct Node **head, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL; // New node is the last node

    //Case-1: If list is empty, new node becomes the head
    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    //Case-2: If the list is not empty, find the last node
    struct Node *last = *head; //*head means the actual head Node
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Connect the last node to the new node
    last->next = temp;
}

void traverse(struct Node *head)
{
    struct Node *temp_traverse = head;
    while (temp_traverse != NULL)
    {
        printf("%d\n", temp_traverse->data);
        temp_traverse = temp_traverse->next;
    }
}

int main()
{
    struct Node *A = NULL;
    insert(&A, 1); // Pass address of head pointer A
    insert(&A, 2);
    traverse(A);
    return 0;
}