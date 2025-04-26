#include <stdio.h>
#define MAX 10

struct Stack
{
    int arr[MAX];
    int top;
};

typedef struct Stack Stack;

void initialize(Stack *stack)
{
    (stack)->top = -1;
}

void push(Stack *stack, int x)
{
    (stack)->top++;
    (stack)->arr[(stack)->top] = x;
    printf("Pushed -> %d\n", x);
}

void pop(Stack *stack)
{
    printf("Popped -> %d\n", stack->arr[stack->top]);
    (stack)->arr[(stack)->top] = 0;
    (stack)->top--;
}

int isFull(Stack *stack)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack is full\n");
        return 1;
    }
    printf("Stack is not full\n");
    return 0;
}

int isEmpty(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty\n");
        return 1;
    }
    printf("Stack is not empty\n");
    return 0;
}

int main()
{
    Stack s1;
    initialize(&s1);
    isEmpty(&s1);
    isFull(&s1);
    push(&s1, 3);
    isEmpty(&s1);
    isFull(&s1);
    push(&s1, 2);
    push(&s1, 1);
    pop(&s1);
    isEmpty(&s1);
    isFull(&s1);
    pop(&s1);
    pop(&s1);
    isEmpty(&s1);
    return 0;
}