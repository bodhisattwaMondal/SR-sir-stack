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
        printf("Empty stack!!\n");
    else{
        // printf("The stack is:\n");
        while (top!= NULL)
        {
            printf("%d--->",top->element);
            top = top->next;
        }
        printf("NULL\n");
    }
}

// Tower of Hanoi Algorithm (recursive)
void toH(int disk, struct Stack **srcTop, struct Stack **auxTop, struct Stack **destTop){
    if (disk == 1)
    {
        // Moving the largest disk from source to destination
        push(destTop,pop(srcTop));
    }
    else{
        // Moving n-1 disks from source to aux using destination stack
        toH(disk - 1, srcTop, destTop, auxTop);

        // Moving the largest disk from source to destination
        push(destTop,pop(srcTop));

        // Moving n-1 disks from aux to destination using source stack
        toH(disk - 1, auxTop, srcTop, destTop);
    }
}


// Driver Code 
int main()
{
    // Creating empty Source Stack 
    struct Stack *srcTop = NULL;   

    // Creating empty Auxilliary Stack 
    struct Stack *auxTop = NULL;   

    // Creating empty Destination Stack 
    struct Stack *destTop = NULL;   

    // Inserting 3 disk(s) in the source stack with value as their weights
    int noOfDisk = 3; 
    push(&srcTop,9);
    push(&srcTop,7);
    push(&srcTop,3);

    // Displaying Stacks
    printf("\nSource Stack : \n");
    display(srcTop);

    printf("\nAux Stack : \n");
    display(auxTop);
    
    printf("\nDestination Stack : \n");
    display(destTop);

    // Applying Tower Of Hanoi Algorithm 
    printf("\n..............Implementing Tower of Hanoi\n");
    toH(noOfDisk, &srcTop, &auxTop, &destTop);

    // Displaying Stacks
    printf("\nSource Stack : \n");
    display(srcTop);

    printf("\nAux Stack : \n");
    display(auxTop);
    
    printf("\nDestination Stack : \n");
    display(destTop);
    return 0;
}