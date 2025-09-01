#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the stack (a singly linked list).
typedef struct stack {
    int data;         // The data stored in the node.
    struct stack *link; // A pointer to the next node in the list.
} st;

// Function prototypes using a double pointer for pass-by-reference.
void push(st **t, int item);
void pop(st **t);
void display(st *t);

int main() {
    // The 'top' pointer of the stack, which is a local variable in main().
    // It's initialized to NULL, indicating an empty stack.
    st *t = NULL;
    int item, c;

    while (1) {
        printf("\n1 to push\n2 to pop\n3 to display\n4 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter item you want to add: ");
                scanf("%d", &item);
                // Call push, passing the address of the 'top' pointer (t).
                // This is how pass-by-reference is implemented in C.
                push(&t, item);
                break;

            case 2:
                // Call pop, again passing the address of the 'top' pointer.
                pop(&t);
                break;

            case 3:
                // For display, we only need to read the stack, not modify the pointer itself.
                // Therefore, we pass 't' by value.
                display(t);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// PUSH operation: Adds an element to the top of the stack.
// The double pointer 'st **t' allows us to modify the 'top' pointer in the main function.
void push(st **t, int item) {
    // Step 1: Allocate memory for a new node.
    st *temp = (st *)malloc(sizeof(st));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    // Step 2: Set the data of the new node.
    temp->data = item;
    // Step 3: Set the 'link' of the new node to point to the current 'top'.
    // We use '*t' to access the pointer that 't' is pointing to (i.e., the original 'top' pointer).
    temp->link = *t;
    // Step 4: Update the original 'top' pointer to point to the new node.
    // By doing this, the change is visible in the main function.
    *t = temp;
    printf("%d pushed to stack\n", item);
}

// POP operation: Removes the top element from the stack.
// The double pointer 'st **t' is necessary to update the 'top' pointer.
void pop(st **t) {
    // Step 1: Check for an empty stack (underflow).
    // We check if the pointer that 't' points to is NULL.
    if (*t == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    // Step 2: Create a temporary pointer to hold the current top node.
    st *temp = *t;
    printf("%d popped from stack\n", temp->data);
    // Step 3: Update the original 'top' pointer to the next node.
    // The stack's new top is the node that the old top was pointing to.
    *t = (*t)->link;
    // Step 4: Free the memory of the popped node to prevent memory leaks.
    free(temp);
}

// DISPLAY operation: Prints all elements of the stack.
// We pass 't' by value because we don't need to change the 'top' pointer,
// just traverse the list from that starting point.
void display(st *t) {
    // Step 1: Check if the stack is empty.
    if (t == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (top to bottom): ");
    // Step 2: Traverse the linked list until the end.
    while (t != NULL) {
        printf("%d ", t->data);
        // Step 3: Move to the next node.
        t = t->link;
    }
    printf("\n");
}