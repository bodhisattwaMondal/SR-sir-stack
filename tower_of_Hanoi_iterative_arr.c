#include <stdio.h>
#include <stdio.h>

struct Stack{
    int capacity;
    int top;
    int *arr;
};

struct Stack* createStack(int capacity){
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(sizeof(int) * stack->capacity);
    return stack;
}

int main()
{
    
    return 0;
}