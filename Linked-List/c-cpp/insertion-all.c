#include <stdio.h>
#include <stdlib.h>

/**
 * Structure representing a node in a linked list
 * Contains data and a pointer to the next node
 */
struct Node
{
    int data;
    struct Node *next;
};

/**
 * Inserts a new node at the beginning of the linked list
 * @param A Double pointer to the head of the linked list
 * @param x The value to be inserted in the new node
 * @return 1 if successful, 0 if memory allocation failed
 */
int insert_beginning(struct Node **A, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }
    temp->data = x;
    if ((*A) == NULL)
    {
        // printf("insert_beginning: 1st case\n");
        temp->next = NULL;
        (*A) = temp;
        return 1;
    }
    // printf("insert_beginning: 2nd case\n");
    temp->next = (*A);
    (*A) = temp;
    return 1;
}

/**
 * Inserts a new node at the end of the linked list
 * @param A Double pointer to the head of the linked list
 * @param x The value to be inserted in the new node
 * @return 1 if successful, 0 if memory allocation failed
 */
int insert_end(struct Node **A, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }
    temp->data = x;
    temp->next = NULL;
    if (*A == NULL)
    {
        *A = temp;
        return 1;
    }
    struct Node *temp_traverse = *A;
    while (temp_traverse->next != NULL)
    {
        temp_traverse = temp_traverse->next;
    }
    temp_traverse->next = temp;
    return 1;
}

/**
 * Inserts a new node at a specified position in the linked list
 * @param A Double pointer to the head of the linked list
 * @param x The value to be inserted in the new node
 * @param position The position at which to insert the new node (1-based indexing)
 * @return 1 if successful, 0 if memory allocation failed or position is invalid
 */
int insert_middle(struct Node **A, int x, int position)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }
    temp->data = x;
    if (*A == NULL)
    {
        // printf("insert middle: case 1");
        temp->next = NULL;
        *A = temp;
        return 1;
    }
    else if (position == 1)
    {
        // printf("insert middle: case 2\n");
        free(temp); // Free the allocated memory since we'll use insert_beginning
        return insert_beginning(A, x);
    }
    // printf("insert middle: case 3\n");
    struct Node *temp_traverse = *A;
    int i = 1;
    while (i < position - 1)
    {
        if (temp_traverse->next == NULL)
        {
            printf("Position out of bound. Exiting...\n");
            free(temp); // Free the allocated memory before returning
            return 0;
        }
        temp_traverse = temp_traverse->next;
        i++;
    }
    temp->next = temp_traverse->next;
    temp_traverse->next = temp;
    return 1;
}

/**
 * Traverses the linked list and prints all elements
 * @param A Pointer to the head of the linked list
 */
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

/**
 * Frees all the memory allocated for the linked list
 * @param A Double pointer to the head of the linked list
 */
void free_list(struct Node **A)
{
    struct Node *current = *A;
    struct Node *temp_traverse;

    while (current != NULL)
    {
        temp_traverse = current->next;
        free(current);
        current = temp_traverse;
    }

    *A = NULL; // Set head to NULL after freeing all nodes
}

/**
 * Main function to demonstrate linked list operations
 */
int main()
{
    struct Node *A = NULL;
    traverse(A); // empty

    // Check return values of insertion operations
    if (!insert_beginning(&A, 3)) // 3
        printf("Failed to insert 3 at beginning\n");

    if (!insert_beginning(&A, 2)) // 2, 3
        printf("Failed to insert 2 at beginning\n");

    if (!insert_beginning(&A, 1)) // 1, 2, 3
        printf("Failed to insert 1 at beginning\n");

    if (!insert_beginning(&A, 0)) // 0, 1, 2, 3
        printf("Failed to insert 0 at beginning\n");

    if (!insert_end(&A, 4)) // 0, 1, 2, 3, 4
        printf("Failed to insert 4 at end\n");

    if (!insert_end(&A, 5)) // 0, 1, 2, 3, 4, 5
        printf("Failed to insert 5 at end\n");

    if (!insert_middle(&A, 10, 4)) // 0, 1, 2, 10, 3, 4, 5
        printf("Failed to insert 10 at position 4\n");

    traverse(A);

    if (!insert_middle(&A, 55, 1)) // 55, 0, 1, 2, 10, 3, 4, 5
        printf("Failed to insert 55 at position 1\n");

    traverse(A);

    // Free the allocated memory before exiting
    free_list(&A);

    return 0;
}
