/**
 * @file stack_using_linked_list.c
 * @brief Implementation of a stack using a linked list data structure
 *
 * This file contains a simple implementation of a stack using a linked list
 * along with basic operations like push, pop, and isEmpty.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Node
 * @brief Structure representing a node in the linked list
 *
 * Each node contains an integer data value and a pointer to the next node
 */
typedef struct Node Node;
typedef struct Stack Stack;

typedef struct Node
{
    int data;   /**< The integer value stored in the node */
    Node *next; /**< Pointer to the next node in the list */
};

/**
 * @struct Stack
 * @brief Structure representing a stack
 *
 * The stack is implemented using a linked list.
 * The top of the stack is represented by A.
 */
struct Stack
{
    Node *A; /**< Pointer to the top node of the stack */
};

/**
 * Initialize an empty stack
 *
 * @param stack Pointer to the Stack structure to initialize
 */
void initialize(Stack *stack)
{
    stack->A = NULL;
}

/**
 * Check if the stack is empty
 *
 * @param stack Pointer to the Stack structure
 * @return 1 if the stack is empty, 0 otherwise
 */
int isEmpty(Stack *stack)
{
    if (stack->A == NULL)
    {
        printf("Stack is empty\n");
        return 1;
    }
    printf("Stack is not empty\n");
    return 0;
}

/**
 * Push an element onto the top of the stack
 *
 * Visual Representation of Push Operation:
 *
 * Before push(2):      After push(2):
 *
 *    TOP                   TOP
 *     |                     |
 *     v                     v
 *    [3]                   [2]
 *     |                     |
 *     v                     v
 *    [7]                   [3]
 *     |                     |
 *     v                     v
 *    [9]                   [7]
 *     |                     |
 *     v                     v
 *   NULL                   [9]
 *                           |
 *                           v
 *                         NULL
 *
 * This function creates a new node, assigns the given value to it,
 * and places it at the top of the stack.
 *
 * @param stack Pointer to the Stack structure
 * @param x The integer value to be pushed onto the stack
 */
void push(Stack *stack, int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = stack->A;
    stack->A = temp;
    printf("pushed -> %d\n", stack->A->data);
}

/**
 * Pop the top element from the stack
 *
 * Visual Representation of Pop Operation:
 *
 * Before pop():         After pop():
 *
 *    TOP                   TOP
 *     |                     |
 *     v                     v
 *    [2] <-- removed       [3]
 *     |                     |
 *     v                     v
 *    [3]                   [7]
 *     |                     |
 *     v                     v
 *    [7]                   [9]
 *     |                     |
 *     v                     v
 *    [9]                  NULL
 *     |
 *     v
 *   NULL
 *
 * This function removes the top element from the stack and frees the memory.
 * If the stack is empty, it prints an error message and returns.
 *
 * @param stack Pointer to the Stack structure
 */
void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Can't pop. Stack is empty\n");
        return;
    }

    Node *temp = stack->A;
    stack->A = stack->A->next;
    printf("Popped -> %d\n", temp->data);
    free(temp);
}

int main()
{
    Stack s;
    initialize(&s);
    isEmpty(&s);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
    pop(&s);
    pop(&s);
    return 0;
}