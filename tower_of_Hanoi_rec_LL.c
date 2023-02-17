#include <stdio.h>
#include <stdlib.h>

// Stack implementation using Linked List
struct Stack
{
    int element;
    struct Stack *next;
};

void push(struct Stack **top, int item)
{
    // creating new node
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->element = item;

    // pushing new node into the stack
    newNode->next = *top;
    *top = newNode;
    // printf("Node succesfully inserted!!");
}

int pop(struct Stack **top)
{
    if (*top == NULL)
        printf("\nStack underflow!!\n");
    else
    {
        struct Stack *temp = *top;
        int tempVal = temp->element;
        *top = (*top)->next;
        free(temp);
        return tempVal;
    }
}

int display(struct Stack *top)
{
    if (top == NULL)
        printf("Empty stack!!\n");
    else
    {
        // printf("The stack is:\n");
        while (top != NULL)
        {
            printf("%d--->", top->element);
            top = top->next;
        }
        printf("NULL\n");
    }
}

//----------------------- Tower of Hanoi Algorithm (recursive) -----------------------

// Moves will not be displayed
// void toH(int disk, struct Stack **srcTop, struct Stack **auxTop, struct Stack **destTop)
// {
//     if (disk == 1)
//     {
//         // Moving the largest disk from source to destination
//         push(destTop, pop(srcTop));
//         return;
//     }

//     // Moving n-1 disks from source to aux using destination stack
//     toH(disk - 1, srcTop, destTop, auxTop);

//     // Moving the largest disk from source to destination
//     push(destTop, pop(srcTop));

//     // Moving n-1 disks from aux to destination using source stack
//     toH(disk - 1, auxTop, srcTop, destTop);
// }

// Moves will be diplayed 
void toH(int disk, struct Stack **srcTop, struct Stack **auxTop, struct Stack **destTop, char S, char A, char D)
{
    if (disk == 1)
    {
        // Moving the largest disk from source to destination
        printf("%c -> %c\n", S, D);
        push(destTop, pop(srcTop));
        return;
    }

    // Moving n-1 disks from source to aux using destination stack
    toH(disk - 1, srcTop, destTop, auxTop, S, D, A);

    printf("%c -> %c\n", S, D);
    // Moving the largest disk from source to destination
    push(destTop, pop(srcTop));

    // Moving n-1 disks from aux to destination using source stack
    toH(disk - 1, auxTop, srcTop, destTop, A, S, D);
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


    // Inserting n disk(s) in the source stack with value as their number
    int noOfDisk = 0;
    printf("Enter the number of disks: ");
    scanf("%d",&noOfDisk);
    for (int i = noOfDisk; i > 0 ; i--)
    {
        push(&srcTop,i);
    }

    // Displaying Stacks before implementing toH
    printf("\nBefore implementing tower of Hanoi\n");
    printf("\nSource Stack : \n");
    display(srcTop);

    printf("\nAux Stack : \n");
    display(auxTop);

    printf("\nDestination Stack : \n");
    display(destTop);

    // Applying Tower Of Hanoi Algorithm
    printf("\n.......................\nImplementing Tower of Hanoi\n.......................\n");
    printf("\nMoves:\n");
    toH(noOfDisk, &srcTop, &auxTop, &destTop, 'S', 'A', 'D'); // showing moves
    // toH(noOfDisk, &srcTop, &auxTop, &destTop); // not showing moves

    // Displaying Stacks after implementing toH
    printf("\nSource Stack : \n");
    display(srcTop);

    printf("\nAux Stack : \n");
    display(auxTop);

    printf("\nDestination Stack : \n");
    display(destTop);
    return 0;
}