// circular queue implementation in linked list 
//  front and rear as GLOBAL VARIABLE

#include<stdio.h> // Standard input/output library for functions like printf and scanf
#include<stdlib.h> // Standard library for dynamic memory allocation (malloc, free) and program termination (exit)

// Define the structure for a node in the circular queue
// It contains an integer data field and a pointer to the next node
typedef struct circularQueue {
    int data;
    struct circularQueue* link;
} cq;

// Global pointers to the front and rear of the circular queue
// These pointers are initialized to NULL, indicating an empty queue
cq* front = NULL;
cq* rear = NULL;

// Function prototypes to declare the functions used in the program
void add(int item);
void delete();
void display();
void quit();

int main() {
    int item = -1, choice = -1;
    // The main program loop that runs indefinitely until the user chooses to quit
    while(1) {
        // Display a menu of options to the user
        printf("\npress 1 for adding element\n");
        printf("press 2 for deleting element\n");
        printf("press 3 for display element\n");
        printf("press 4 for quiting\n");
        printf("enter choice : ");
        scanf("%d", &choice); // Read the user's choice

        // Use a switch statement to perform an action based on the user's choice
        switch(choice) {
            case 1:
                printf("enter element you wanna add : ");
                scanf("%d", &item); // Read the item to be added
                add(item); // Call the add function
                break;

            case 2:
                delete(); // Call the delete function
                break;

            case 3:
                display(); // Call the display function
                break;

            case 4:
                quit(); // Call the quit function to terminate the program
                break;

            default:
                printf("Invalid choice!\n"); // Handle invalid input
        }
    }
    return 0;
}

// Function to add a new element to the circular queue
void add(int item) {
    // Dynamically allocate memory for a new node
    cq* temp = (cq*)malloc(sizeof(cq));
    // Check if memory allocation failed
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = item; // Store the item in the new node

    // Check if the queue is currently empty
    if(front == NULL) {
        temp->link = temp; // The new node points to itself, forming a circle
        front = rear = temp; // The new node is both the front and the rear
    } else {
        // If the queue is not empty, link the current rear to the new node
        rear->link = temp;
        // The new node's link points back to the front, maintaining the circular structure
        temp->link = front;
        rear = temp; // Update the rear pointer to the new node
    }
    printf("%d element added\n", temp->data);
}

// Function to delete an element from the front of the circular queue
void delete() {
    // Check if the queue is empty
    if(front == NULL) {
        printf("circular queue is empty\n");
        return;
    }
    cq* q = front; // Create a temporary pointer to the front node to be deleted

    // Check if there is only one node in the queue
    if(q->link == q) {
        front = rear = NULL; // Reset both front and rear to NULL
    } else {
        front = front->link; // Move the front pointer to the next node
        rear->link = front; // Update the rear's link to point to the new front
    }
    printf("%d element removed from circular queue\n", q->data);
    free(q); // Free the memory of the deleted node
}

// Function to display all elements of the circular queue
void display() {
    // Check if the queue is empty
    if(front == NULL) {
        printf("circular queue is empty\n");
        return;
    }
    printf("elements of circular queue are: ");
    cq* q = front; // Start traversing from the front of the queue

    // Traverse the queue using a do-while loop to ensure at least one node is printed
    // The loop continues until the pointer returns to the front
    do {
        printf("%d ", q->data); // Print the data of the current node
        q = q->link; // Move to the next node
    } while(q != front);
    printf("\n"); // Print a newline for better formatting
}

// Function to free all allocated memory and exit the program
void quit() {
    // Free all nodes before quitting (good practice to prevent memory leaks)
    if(front != NULL) {
        cq* q = front;
        do {
            cq* temp = q; // Store the current node to be freed
            q = q->link; // Move to the next node
            free(temp); // Free the memory
        } while(q != front);
    }
    printf("Exiting program...\n");
    exit(0); // Terminate the program with a success code
}