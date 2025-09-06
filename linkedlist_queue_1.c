// global front and top

#include<stdio.h>
#include<stdlib.h>

// A structure to represent a node in the queue (a linked list).
typedef struct queue {
    int data;            // The data stored in the node.
    struct queue* link;  // A pointer to the next node.
} q;

// Global pointers for the front and rear of the queue.
// They are initialized to NULL, indicating an empty queue.
q *f = NULL; // Front pointer
q *r = NULL; // Rear pointer

// Function prototypes. These functions directly use the global f and r pointers.
void push(int item);
void pop();
void display();

int main() {
    int c, item;
    while (1) {
        printf("1 to push\n2 to pop\n3 to display\n4 to exit\nenter choice : ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("enter item you wanna push : ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// PUSH operation (enqueue): Adds a new item to the rear of the queue.
void push(int item) {
    // Step 1: Allocate memory for a new queue node.
    q* temp = (q*)malloc(sizeof(q));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    // Step 2: Assign data to the new node and set its link to NULL.
    temp->data = item;
    temp->link = NULL;

    // Step 3: Handle the case for an empty queue.
    // If the queue is empty, both front and rear will point to the new node.
    if (f == NULL) {
        f = r = temp;
    } else {
        // Step 4: For a non-empty queue, link the current rear node to the new node.
        r->link = temp;
        // Step 5: Update the rear pointer to the new node.
        r = temp;
    }
    printf("%d pushed to queue\n", item);
}

// POP operation (dequeue): Removes the item from the front of the queue.
void pop() {
    // Step 1: Check for queue underflow (empty queue).
    if (f == NULL) {
        printf("Queue underflow\n");
        return;
    }
    // Step 2: Create a temporary pointer to hold the front node.
    q* temp = f;
    printf("Popped element: %d\n", temp->data);
    // Step 3: Move the front pointer to the next node in the queue.
    f = f->link;
    // Step 4: If the queue becomes empty after popping, reset the rear pointer to NULL.
    if (f == NULL) {
        r = NULL;
    }
    // Step 5: Free the memory of the original front node to prevent memory leaks.
    free(temp);
}

// DISPLAY operation: Prints all elements in the queue from front to rear.
void display() {
    // Step 1: Check if the queue is empty.
    if (f == NULL) {
        printf("Queue is empty\n");
        return;
    }
    // Step 2: Create a temporary pointer to traverse the queue without modifying the front.
    q* s = f;
    printf("Queue (front to rear): ");
    // Step 3: Traverse the linked list from front to rear.
    while (s != NULL) {
        printf("%d ", s->data);
        // Step 4: Move to the next node.
        s = s->link;
    }
    printf("\n");
}