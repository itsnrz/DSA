#include <stdio.h>
#include <stdlib.h>

#define MAX 20  // Maximum size of the queue

// Function prototypes
void add_queue(int *q, int *f, int *r, int item); // Add element to queue
void dell_queue(int *q, int *f, int *r);          // Delete element from queue
void display_queue(int *q, int f, int r);         // Display elements of queue
void exit1();                                     // Exit the program

/*
  A queue is a linear data structure that follows the First-In, First-Out (FIFO) principle.
  This means the first element added to the queue will be the first one to be removed.
  Think of it like a line of people waiting to buy tickets. The person who gets in line first
  is the first person to be served.

  Implementation:
  This program implements a queue using a **static array**.
  - **MAX**: A constant that defines the maximum capacity of the queue.
  - **front**: An integer index that points to the first element of the queue. It's used for deletion.
  - **rear**: An integer index that points to the last element of the queue. It's used for insertion.
  - **add_queue() (Enqueue)**: Adds an element to the rear of the queue. It checks for **overflow** (when the queue is full).
  - **dell_queue() (Dequeue)**: Deletes an element from the front of the queue. It checks for **underflow** (when the queue is empty).
  
  Real-world examples:
  - **Printer Spooling**: Documents sent to a printer are placed in a queue and printed in the order they were received.
  - **Call Center Phone Systems**: Callers are placed in a queue and connected to an agent in the order they called.
  - **Operating System Scheduling**: Processes are placed in a queue waiting for CPU time, handled on a FIFO basis.
*/

int main() {
    int c = -1, item = -1;    // c = menu choice, item = element to insert
    int front = -1, rear = -1;  // front and rear pointers for queue
    int queue[MAX];             // Array representing the queue

    while (1) {
        // Display menu
        printf("\nQueue Operations Menu:\n");
        printf("1. Add element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        // Handle menu choice
        switch (c) {
            case 1:
                // Add element to queue
                printf("Enter element: ");
                scanf("%d", &item);
                add_queue(queue, &front, &rear, item);
                break;

            case 2:
                // Delete element from queue
                dell_queue(queue, &front, &rear);
                break;

            case 3:
                // Display current elements of queue
                display_queue(queue, front, rear);
                break;

            case 4:
                // Quit the program
                exit1();

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add element to queue
void add_queue(int *q, int *f, int *r, int item) {
    if (*r == MAX - 1) { // Check for overflow
        printf("Queue Overflow! Cannot insert %d\n", item);
        return;
    }
    if (*f == -1) {      // Queue is empty
        *f = 0;          // Initialize front
        *r = 0;          // Initialize rear
    } else {
        (*r)++;          // Move rear forward
    }
    q[*r] = item;        // Insert item at rear
    printf("%d added to queue\n", item);
}

// Function to delete element from queue
void dell_queue(int *q, int *f, int *r) {
    if (*f == -1) { // Check for underflow
        printf("Queue Underflow! Nothing to delete\n");
        return;
    }
    printf("Deleted element: %d\n", q[*f]); // Show deleted element
    if (*f == *r) { // Queue has only one element, reset queue
        *f = -1;
        *r = -1;
    } else {
        (*f)++; // Move front forward
    }
}

// Function to display queue elements
void display_queue(int *q, int f, int r) {
    if (f == -1) { // Queue empty
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = f; i <= r; i++) {
        printf("%d ", q[i]); // Print all elements from front to rear
    }
    printf("\n");
}

// Function to exit program
void exit1() {
    printf("Exiting program.\n");
    exit(0); // Terminate program normally
}