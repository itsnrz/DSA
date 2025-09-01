// top as global variable
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in the stack (which is a linked list)
typedef struct stack {
    int data;          // The data stored in the node
    struct stack *link;  // A pointer to the next node in the linked list
} st;

// A global pointer 'top' which always points to the top element of the stack.
// It is initialized to NULL to signify an empty stack.
st *top = NULL;

// Function prototypes for stack operations
void push(int item);
void pop();
void display(st *t);

int main() {
    int c, item;
    // An infinite loop to present a menu to the user for stack operations
    while (1) {
        printf("\n1 to push\n2 to pop\n3 to display\n4 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter item you want to add: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                display(top);
                break;

            case 4:
                // Exit the program
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Push operation: Adds an element to the top of the stack.
// This is done by creating a new node and making it the new 'top'.
void push(int item) {
    // Step 1: Dynamically allocate memory for a new stack node.
    // The new node will hold the item to be pushed.
    st *temp = (st *)malloc(sizeof(st));
    if (temp == NULL) {
        // Step 2 (Error Handling): Check if memory allocation was successful.
        // If not, the system is out of memory.
        printf("Memory allocation failed!\n");
        return;
    }
    // Step 3: Assign the given item to the 'data' field of the new node.
    temp->data = item;
    // Step 4: Link the new node to the current 'top' of the stack.
    // This makes the new node point to the previously top node.
    temp->link = top;
    // Step 5: Update the 'top' pointer to point to the newly created node.
    // This makes the new node the new top of the stack.
    top = temp;
    printf("%d pushed to stack\n", item);
}

// Pop operation: Removes and returns the top element from the stack.
void pop() {
    // Step 1 (Underflow Check): Check if the stack is empty (top is NULL).
    // If it is, no elements can be popped.
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    // Step 2: Create a temporary pointer to hold the current top node.
    st *temp = top;
    printf("Popped element: %d\n", temp->data);
    // Step 3: Move the 'top' pointer to the next node in the list.
    // This effectively "removes" the top node from the stack.
    top = top->link;
    // Step 4: Free the memory of the previously top node.
    // This is crucial to prevent memory leaks.
    free(temp);
}

// Display operation: Prints all elements of the stack from top to bottom.
void display(st *t) {
    // Step 1 (Empty Check): Check if the stack is empty by checking the temporary pointer 't'.
    if (t == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (top to bottom): ");
    // Step 2: Traverse the linked list from the 'top' (represented by 't').
    while (t != NULL) {
        // Step 3: Print the data of the current node.
        printf("%d ", t->data);
        // Step 4: Move to the next node by following the 'link' pointer.
        t = t->link;
    }
    printf("\n");
}