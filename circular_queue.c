/*
 * C Program for Circular Queue Operations 🔄
 *
 * A **circular queue** is a linear data structure that's an enhanced version of a simple queue.
 * It operates in a circular fashion where the last position is connected to the first,
 * effectively allowing for efficient use of memory by reusing dequeued space. It follows the
 * **First-In, First-Out (FIFO)** principle, meaning the first element added is the first one to be removed.
 *
 * ---
 *
 * ### Real-World Applications
 *
 * Circular queues are useful in scenarios where a fixed amount of data needs to be processed continuously.
 *
 * - **CPU Scheduling**: In operating systems, a circular queue can manage processes in a **round-robin** fashion.
 * Each process gets a fixed time slice before the next process in the queue gets its turn.
 * - **Traffic Light Systems**: A circular queue can cycle through the states of a traffic light (red, yellow, green)
 * in a predetermined order.
 * - **Buffer Management**: In streaming data or multimedia applications, a circular buffer (a type of circular queue)
 * is used to store incoming data temporarily. This ensures smooth playback without interruptions by
 * continuously filling and emptying the buffer.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20    // Maximum size of Circular Queue

// Function Prototypes
void enqueue(int *cq, int *front, int *rear, int item);
void dequeue(int *cq, int *front, int *rear);
void display(int *cq, int front, int rear);
void exit_program();

int main() {
    int front = -1, rear = -1;
    int cqueue[MAX];
    int choice, item;

    while (1) {
        printf("\n=== Circular Queue Menu ===\n");
        printf("1. Enqueue (Add)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(cqueue, &front, &rear, item);
                break;

            case 2:
                dequeue(cqueue, &front, &rear);
                break;

            case 3:
                display(cqueue, front, rear);
                break;

            case 4:
                exit_program();

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add an item to the Circular Queue
void enqueue(int *cq, int *front, int *rear, int item) {
    // Check for overflow. The queue is full if front is 0 and rear is MAX-1,
    // or if front is one position ahead of rear (e.g., front=5, rear=4).
    if ((*front == 0 && *rear == MAX - 1) || (*front == *rear + 1)) {
        printf("Queue Overflow! Cannot insert %d\n", item);
        return;
    }

    // If the queue is initially empty, set both front and rear to 0.
    if (*front == -1) {
        *front = *rear = 0;
    } 
    // If rear is at the last index and the queue is not full, wrap around to the beginning.
    else if (*rear == MAX - 1) {
        *rear = 0;
    } 
    // Otherwise, simply increment the rear pointer.
    else {
        (*rear)++;
    }

    cq[*rear] = item;
    printf("Inserted %d into the queue.\n", item);
}

// Function to remove an item from the Circular Queue
void dequeue(int *cq, int *front, int *rear) {
    // Check for underflow. The queue is empty if front is -1.
    if (*front == -1) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    int deleted = cq[*front];

    // If there is only one element, set both front and rear to -1 after deletion.
    if (*front == *rear) {
        *front = *rear = -1;
    } 
    // If front is at the last index, wrap around to the beginning.
    else if (*front == MAX - 1) {
        *front = 0;
    } 
    // Otherwise, simply increment the front pointer.
    else {
        (*front)++;
    }

    printf("Deleted %d from the queue.\n", deleted);
}

// Function to display the Circular Queue
void display(int *cq, int front, int rear) {
    // Check if the queue is empty.
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    // Case 1: The queue is not wrapped around (front <= rear).
    if (front <= rear) {
        for (int i = front; i <= rear; i++)
            printf("%d ", cq[i]);
    } 
    // Case 2: The queue is wrapped around (front > rear).
    else {
        // Print elements from the front to the end of the array.
        for (int i = front; i < MAX; i++)
            printf("%d ", cq[i]);
        // Print elements from the beginning of the array to the rear.
        for (int i = 0; i <= rear; i++)
            printf("%d ", cq[i]);
    }
    printf("\n");
}

// Function to exit program
void exit_program() {
    printf("Exiting program. Goodbye!\n");
    exit(0);
}