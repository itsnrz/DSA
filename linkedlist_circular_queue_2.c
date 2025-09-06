// circular queue implementation in linked list 
//  front and rear as LOCAL VARIABLE *PASS BY REFERENCE*


#include<stdio.h> // Standard input/output library
#include<stdlib.h> // Standard library for dynamic memory allocation (malloc, free) and program termination (exit)

// Defines the structure for a node in the circular queue
// Each node contains integer data and a pointer to the next node
typedef struct circularQueue {
    int data;
    struct circularQueue* link;
} cq;

// Function prototypes to declare the functions
// They take double pointers to modify the original front and rear pointers
void add(cq **f, cq **r, int item);
void deleteNode(cq **f, cq **r);
void display(cq **f, cq **r);
void quit(cq **f, cq **r);

int main() {
    // Pointers to the front and rear of the queue, initialized to NULL
    cq *front = NULL, *rear = NULL;
    int item = -1, choice = -1;

    // Main program loop that runs until the user decides to quit
    while(1) {
        // Display a menu of operations
        printf("\npress 1 for adding element\n");
        printf("press 2 for deleting element\n");
        printf("press 3 for display element\n");
        printf("press 4 for quiting\n");
        printf("enter choice : ");
        scanf("%d", &choice); // Read the user's choice

        // Switch statement to handle different user choices
        switch(choice) {
            case 1:
                printf("enter element you wanna add : ");
                scanf("%d", &item); // Read the element to be added
                add(&front, &rear, item); // Pass addresses of front and rear pointers
                break;

            case 2:
                deleteNode(&front, &rear); // Pass addresses to delete a node
                break;

            case 3:
                display(&front, &rear); // Pass addresses to display the queue
                break;

            case 4:
                quit(&front, &rear); // Pass addresses to free memory and quit
                break;

            default:
                printf("Invalid choice!\n"); // Handle invalid input
        }
    }
    return 0; // The program exits here if quit() is not called
}

// Function to add a new element to the circular queue
// It takes double pointers to modify the global front and rear pointers
void add(cq **f, cq **r, int item) {
    // Dynamically allocate memory for a new node
    cq *temp = (cq*)malloc(sizeof(cq));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = item; // Store the data in the new node

    // Check if the queue is empty
    if(*f == NULL) {
        temp->link = temp; // The new node's link points to itself
        *f = *r = temp; // The new node is both the front and the rear
    } else {
        // Queue is not empty:
        (*r)->link = temp; // The current rear's link points to the new node
        temp->link = *f; // The new node's link points to the front
        *r = temp; // Update the rear pointer to the new node
    }
    printf("%d element added\n", temp->data);
}

// Function to delete an element from the front of the circular queue
void deleteNode(cq **f, cq **r) {
    // Check if the queue is empty
    if(*f == NULL) {
        printf("circular queue is empty\n");
        return;
    }
    cq *q = *f; // Create a temporary pointer to the node to be deleted

    // Check if there is only one node in the queue
    if(q->link == q) {
        *f = *r = NULL; // Reset front and rear to NULL
    } else {
        *f = (*f)->link; // Move front to the next node
        (*r)->link = *f; // Update rear's link to point to the new front
    }
    printf("%d element removed from circular queue\n", q->data);
    free(q); // Free the memory of the deleted node
}

// Function to display all elements of the circular queue
void display(cq **f, cq **r) {
    // Check if the queue is empty
    if(*f == NULL) {
        printf("circular queue is empty\n");
        return;
    }
    printf("elements of circular queue are: ");
    cq *q = *f; // Start traversal from the front

    // Use a do-while loop to print elements. It runs at least once.
    do {
        printf("%d ", q->data); // Print the data
        q = q->link; // Move to the next node
    } while(q != *f); // Continue until we return to the front
    printf("\n");
}

// Function to free all allocated memory and exit the program
void quit(cq **f, cq **r) {
    // Check if the queue is not empty to avoid a null pointer dereference
    if(*f != NULL) {
        cq *q = *f;
        // Traverse and free each node
        do {
            cq *temp = q; // Store current node to free it
            q = q->link; // Move to the next node first
            free(temp); // Free the stored node
        } while(q != *f); // Loop until all nodes are freed
    }
    printf("Exiting program...\n");
    exit(0); // Terminate the program
}