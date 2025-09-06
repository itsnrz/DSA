#include<stdio.h>
#include<stdlib.h>

// A stack is a linear data structure that follows the LIFO (Last-In, First-Out) principle.
// Think of a stack of plates: you can only add a new plate to the top, and you can only
// remove the plate that's currently on top.
// Real-world examples of stacks include:
// 1. Browser history (the 'back' button pops the last visited page).
// 2. The undo/redo function in a text editor (each action is pushed onto a stack).
// 3. The call stack in programming, which manages function calls.
// Stacks are commonly used in algorithms for things like expression evaluation,
// backtracking, and managing function calls in a program.

#define max 20

// Function prototypes
void display(int *s ,int t);
void push(int *s,int *t,int item);
void pop(int *s,int*t);
void quit();

int main(){
    // stack array and top pointer initialization
    int stack[max], top=-1, item=-1;
    char ch='\0';

    // The main program loop
    while(1){
        printf("\npress 'p' for pushing");
        printf("\npress 'r' for popping");
        printf("\npress 'd' for display");
        printf("\npress 'q' for quitting\n");
        
        // The space before %c in scanf is a fix to consume any leftover whitespace
        // (like newlines from previous inputs) so scanf correctly reads the character.
        scanf(" %c",&ch);

        // Switch statement to handle user input
        switch(ch){
            case 'p':
            case 'P':
                printf("enter item you wanna push : ");
                scanf("%d",&item);
                push(stack,&top,item);
                break;

            case 'R':
            case 'r':
                pop(stack,&top);
                break;

            case 'd':
            case 'D':
                display(stack,top);
                break;

            case 'Q':
            case 'q':
                quit();
                break;

            default:
                printf("invalid input ** try again\n");
        }
    }
    return 0;
}

// Function to display the elements of the stack
void display(int *s ,int t){
    // Check for an empty stack
    if(t == -1){
        printf("stack is empty\n");
        return;
    }
    printf("displaying elements of stack (top to bottom):\n");
    // Loop to print elements from top to bottom
    for(int i=t;i>=0;i--){
        printf("%d ",s[i]);
    }
    printf("\n");
}

// Function to push an item onto the stack
void push(int *s,int *t,int item){
    // Check for stack overflow (stack is full)
    if(*t == max-1){
        printf("stack overflow\n"); 
        return;
    }
    // Increment the top pointer and add the new item
    s[++(*t)] = item;
    printf("element pushed = %d\n", item);
}

// Function to pop an item from the stack
void pop(int *s,int*t){
    // Check for stack underflow (stack is empty)
    if((*t) == -1){
        printf("stack underflow\n");
        return;
    }
    // Print the item being popped and then decrement the top pointer
    printf("element popped = %d\n", s[*t]);
    (*t)--;
}

// Function to handle program termination
void quit(){
    char c;
    printf("Quit (y/n)? "); 
    scanf(" %c",&c);
    // If the user confirms, exit the program with a status code of 0
    if(c=='y'||c=='Y') exit(0);
}