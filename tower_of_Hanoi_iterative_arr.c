#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int capacity;
    int top;
    int *arr;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(sizeof(int) * stack->capacity);
    return stack;
}

int isFull(struct Stack *stack)
{
    return (stack->top == stack->capacity - 1);
}

int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

void push(struct Stack *stack, int element)
{
    if (isFull(stack))
    {
        printf("Stack Overflow !!");
        return;
    }
    stack->arr[++stack->top] = element;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        printf("Stack Underflow !!");
    else
        return stack->arr[stack->top--];
}

void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow !!");
        return;
    }

    printf("Stack:\n");
    for (int i = stack->top; i > -1; i--)
        printf("%d\n", stack->arr[i]);
    printf("\n");
}

// Driver Code
int main()
{
    struct Stack *myStack = createStack(4);
    push(myStack, 78);
    push(myStack, 8);
    push(myStack, 1548);
    pop(myStack);
    display(myStack);
    return 0;
}