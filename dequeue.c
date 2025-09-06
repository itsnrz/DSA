#include <stdio.h>
#include <stdlib.h>

#define MAX 20

/*
 * C Program for a peculiar queue-like data structure where:
 * - Elements are added at the **front** (Add-Front)
 * - Elements are deleted from the **rear** (Delete-Rear)
 *
 * This structure is a specific type of **double-ended queue (deque)**, but
 * with limited operations. Unlike a standard queue (FIFO), which adds at the rear
 * and deletes from the front, this one does the opposite.
 *
 * ### Implementation Notes
 * - **Addition at the Front (using circular array)**:
 *   Instead of shifting all elements (inefficient O(n)),
 *   we use circular indexing. We simply move the `front` pointer backwards
 *   (wrapping around if necessary) and insert in O(1) time.
 *
 * - **Deletion from the Rear**:
 *   Deleting from the rear is simple: take the value at `rear`,
 *   then move the `rear` pointer backwards (also circular).
 *   This is also O(1).
 *
 * - **Advantages**: Both operations (Add-Front, Delete-Rear) are O(1).
 * - **Limitations**: Only supports these two operations, not a full deque.
 */

// Function Prototypes
void add_front(int *arr, int *front, int *rear, int item);
void delete_rear(int *arr, int *front, int *rear);
void display(int *arr, int front, int rear);
void exit_program();

int main() {
    int arr[MAX];
    int front = -1, rear = -1;  // Both set to -1 when empty
    int choice, item;

    while (1) {
        // Menu-driven interface
        printf("\n=== Menu ===\n");
        printf("1. Add element at Front\n");
        printf("2. Delete element from Rear\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add at front
                printf("Enter item to add: ");
                scanf("%d", &item);
                add_front(arr, &front, &rear, item);
                break;

            case 2: // Delete from rear
                delete_rear(arr, &front, &rear);
                break;

            case 3: // Display all elements
                display(arr, front, rear);
                break;

            case 4: // Exit
                exit_program();

            default: // Invalid input
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add element at the front in O(1) using circular array
void add_front(int *arr, int *front, int *rear, int item) {
    // Check if the array is full
    if ((*front == 0 && *rear == MAX - 1) || (*front == *rear + 1)) {
        printf("Array is full! Cannot add %d.\n", item);
        return;
    }

    // Case 1: Queue is empty
    if (*front == -1) {
        *front = *rear = 0;
    }
    // Case 2: Front is at position 0, wrap around to end
    else if (*front == 0) {
        *front = MAX - 1;
    }
    // Case 3: Normal case, just move front one step left
    else {
        (*front)--;
    }

    // Place the new element at the updated front position
    arr[*front] = item;
    printf("Added %d to the front.\n", item);
}

// Function to delete element from the rear in O(1)
void delete_rear(int *arr, int *front, int *rear) {
    // Empty check
    if (*front == -1) {
        printf("Array is empty! Nothing to delete.\n");
        return;
    }

    // Store and print the element being deleted
    int deleted_item = arr[*rear];
    printf("Deleted element from the rear: %d\n", deleted_item);

    // Case 1: Only one element was present
    if (*front == *rear) {
        *front = *rear = -1;  // Reset to empty
    }
    // Case 2: Rear is at 0, wrap around to end
    else if (*rear == 0) {
        *rear = MAX - 1;
    }
    // Case 3: Normal case, just move rear one step left
    else {
        (*rear)--;
    }
}

// Function to display elements from front to rear
void display(int *arr, int front, int rear) {
    // Empty check
    if (front == -1) {
        printf("Array is empty.\n");
        return;
    }

    printf("Elements: ");
    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear) break; // Stop when rear is reached
        i = (i + 1) % MAX;    // Move circularly
    }
    printf("\n");
}

// Function to exit the program
void exit_program() {
    printf("Exiting program. Goodbye!\n");
    exit(0);
}
