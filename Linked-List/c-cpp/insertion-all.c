#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void insert_beginning(struct Node **A, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    if ((*A) == NULL)
    {
        // printf("insert_beginning: 1st case\n");
        temp->next = NULL;
        (*A) = temp;
        return;
    }
    // printf("insert_beginning: 2nd case\n");
    temp->next = (*A);
    (*A) = temp;
}

void insert_end(struct Node **A, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (*A == NULL)
    {
        *A = temp;
        return;
    }
    struct Node *temp_traverse = *A;
    while (temp_traverse->next != NULL)
    {
        temp_traverse = temp_traverse->next;
    }
    temp_traverse->next = temp;
}

void insert_middle(struct Node **A, int x, int position)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    if (*A == NULL)
    {
        // printf("insert middle: case 1");
        temp->next = NULL;
        *A = temp;
        return;
    }
    // printf("insert middle: case 2\n");
    struct Node *temp_traverse = *A;
    int i = 1;
    while (i < position - 1)
    {
        if (temp_traverse->next == NULL)
        {
            printf("Position out of bound. Exiting...");
            return;
        }
        temp_traverse = temp_traverse->next;
        i++;
    }
    temp->next = temp_traverse->next;
    temp_traverse->next = temp;
}

void traverse(struct Node *A)
{
    if (A == NULL)
    {
        // printf("Traverse: 1st case\n");
        printf("List is empty\n");
        return;
    }
    struct Node *temp_traverse = A;
    // printf("Traverse: 2nd case\n");
    while (temp_traverse->next != NULL)
    {
        printf("%d, ", temp_traverse->data);
        temp_traverse = temp_traverse->next;
    }
    printf("%d\n", temp_traverse->data);
}

int main()
{
    struct Node *A = NULL;
    traverse(A);              // empty
    insert_beginning(&A, 3);  // 3
    insert_beginning(&A, 2);  // 2, 3
    insert_beginning(&A, 1);  // 1, 2, 3
    insert_beginning(&A, 0);  // 0, 1, 2, 3
    insert_end(&A, 4);        // 0, 1, 2, 3, 4
    insert_end(&A, 5);        // 0, 1, 2, 3, 4, 5
    insert_middle(&A, 10, 3); // 0, 1, 10, 2, 3, 4, 5
    insert_middle(&A, 55, 2); // 0, 1, 10, 2, 3, 4, 5
    traverse(A);
    return 0;
}