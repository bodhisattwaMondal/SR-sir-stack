#include <stdio.h>
#include <stdlib.h>

// Stack implementation using Linked List
struct Stack{
    int element;
    struct Stack *next;
};

void push(struct Stack **top, int item){
    // creating new node 
    struct Stack *newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->element = item;

    // pushing new node into the stack 
    newNode->next = *top;
    *top = newNode;
    // printf("Node succesfully inserted!!");
}

int pop(struct Stack **top){
    if (*top == NULL)
        printf("\nStack underflow!!\n");
    else{
        struct Stack *temp = *top;
        int tempVal = temp->element;
        *top = (*top)->next;
        free(temp);
        return tempVal;
    }
}


int display(struct Stack *top){
    if (top == NULL)
        printf("\nEmpty stack!!\n");
    else{
        printf("The stack is:\n");
        while (top!= NULL)
        {
            printf("%d--->",top->element);
            top = top->next;
        }
        printf("\n");
    }
}
int main()
{
    // Creating empty Stack 
    struct Stack *top = NULL;

    // Test Case: empty stack 
    display(top);

    // Test Case : push
    push(&top, 78);
    push(&top, 9);
    push(&top, 48);
    push(&top, 780);
    display(top);

    // Test Case : pop 
    pop(&top);
    display(top);
    return 0;
}