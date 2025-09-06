/*
===============================================
   Singly Linked List in C - Implementation
===============================================

🔹 What is a Linked List?
   A linked list is a linear data structure where elements 
   (called "nodes") are connected using pointers. 
   Each node contains:
     1. Data (the value we want to store)
     2. Pointer (reference to the next node in the list)

   Unlike arrays, linked lists do not require contiguous 
   memory allocation, making insertions and deletions 
   more efficient in certain scenarios.

🔹 Types of Linked Lists:
   1. Singly Linked List (this program) → Each node points to the next.
   2. Doubly Linked List → Nodes have pointers to both previous and next.
   3. Circular Linked List → Last node connects back to the first.

🔹 Key Operations Implemented Here:
   ✅ Add node at front, back, or any position
   ✅ Delete node from front, back, or any position
   ✅ Display all nodes

🔹 Applications of Linked Lists:
   - Dynamic memory allocation (OS memory management)
   - Undo/Redo functionality in editors
   - Music playlists (next/previous song navigation)
   - Image viewers (next/previous image)
   - Implementation of stacks, queues, and graphs
   - Polynomial arithmetic (storing variable-sized terms)
   - Web browsers (back/forward history)

🔹 Real-World Analogy:
   Imagine a "chain of train coaches":
   - Each coach (node) stores passengers (data).
   - Each coach is connected to the next with a hook (pointer).
   - You can attach/detach coaches at any position without 
     shifting the entire train (unlike arrays).

This program demonstrates the creation and manipulation 
of a singly linked list in C.
===============================================
*/

#include <stdio.h>  // Standard input/output library for functions like printf and scanf
#include <stdlib.h> // Standard library for dynamic memory allocation (malloc, free) and program termination (exit)

// Defines the structure for a node in the singly linked list
struct node {
    int data;          // Data field to store the integer value
    struct node* next; // Pointer to the next node in the list
};

// Global pointer to the first node of the list
// It's initialized to NULL, indicating an empty list
struct node* start = NULL;

// Function prototypes to declare the functions used
void add_front(int item);
void add_back(int item);
void add_pos(int item, int pos);
void delete_front();
void delete_back();
void delete_pos(int pos);
void display();

int main() {
    int item = -1, choice = -1, pos = -1;
    // Main program loop that runs indefinitely until the user chooses to exit
    while (1) {
        // Display a menu of options to the user
        printf("\n--- Menu ---\n");
        printf("1. Add at Front\n");
        printf("2. Add at Back\n");
        printf("3. Add at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Back\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement to perform an action based on the user's choice
        switch (choice) {
            case 1:
                printf("Enter element to add at front: ");
                scanf("%d", &item);
                add_front(item);
                break;

            case 2:
                printf("Enter element to add at back: ");
                scanf("%d", &item);
                add_back(item);
                break;

            case 3:
                printf("Enter element to add: ");
                scanf("%d", &item);
                printf("Enter position: ");
                scanf("%d", &pos);
                add_pos(item, pos);
                break;

            case 4:
                delete_front();
                break;

            case 5:
                delete_back();
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0); // Exit the program

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to add a new node at the beginning of the list
void add_front(int item) {
    // Allocate memory for a new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = item;    // Set the data
    temp->next = start;   // Link the new node to the current start
    start = temp;         // Update the start pointer to the new node
    printf("%d added at front.\n", item);
}

// Function to add a new node at the end of the list
void add_back(int item) {
    // Allocate memory for a new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = item;
    temp->next = NULL; // The new node will be the last, so its next is NULL

    // Check if the list is empty
    if (start == NULL) {
        start = temp; // If empty, the new node becomes the start
    } else {
        // Traverse the list to find the last node
        struct node* p = start;
        while (p->next != NULL) {
            p = p->next;
        }
        // Link the last node to the new node
        p->next = temp;
    }
    printf("%d added at back.\n", item);
}

// Function to add a new node at a specific position
void add_pos(int item, int pos) {
    // Handle invalid position
    if (pos <= 0) {
        printf("Invalid position! Position must be greater than 0.\n");
        return;
    }
    // Allocate memory for the new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = item;

    // Special case: adding at the first position
    if (pos == 1) {
        temp->next = start;
        start = temp;
    } else {
        // Traverse to the node *before* the desired position
        struct node* p = start;
        for (int i = 1; i < pos - 1 && p != NULL; i++) {
            p = p->next;
        }
        // Check if the position is out of bounds
        if (p == NULL) {
            printf("Position out of range! Cannot add.\n");
            free(temp); // Free allocated memory since we can't add the node
            return;
        }
        // Insert the new node
        temp->next = p->next;
        p->next = temp;
    }
    printf("%d added at position %d.\n", item, pos);
}

// Function to delete the node at the front of the list
void delete_front() {
    // Check if the list is empty
    if (start == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    struct node* temp = start; // Store the first node to be deleted
    start = start->next;       // Update start to the second node
    printf("%d deleted from front.\n", temp->data);
    free(temp); // Free the memory of the deleted node
}

// Function to delete the node at the back of the list
void delete_back() {
    // Check if the list is empty
    if (start == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    // If there is only one node
    if (start->next == NULL) {
        printf("%d deleted from back.\n", start->data);
        free(start);
        start = NULL;
        return;
    }

    // Traverse to the second to last node
    struct node* temp = start;
    struct node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL; // The second to last node now becomes the last
    printf("%d deleted from back.\n", temp->data);
    free(temp); // Free the last node
}

// Function to delete a node from a specific position
void delete_pos(int pos) {
    // Handle empty list or invalid position
    if (start == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    if (pos <= 0) {
        printf("Invalid position! Position must be greater than 0.\n");
        return;
    }

    // Special case: deleting the first node
    if (pos == 1) {
        struct node* temp = start;
        start = start->next;
        printf("%d deleted from position %d.\n", temp->data, pos);
        free(temp);
        return;
    }

    // Traverse to the node *before* the desired position
    struct node* temp = start;
    struct node* prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    // Check if the position is out of bounds
    if (temp == NULL) {
        printf("Position out of range! Cannot delete.\n");
        return;
    }

    // Bypass and delete the node
    prev->next = temp->next;
    printf("%d deleted from position %d.\n", temp->data, pos);
    free(temp);
}

// Function to display the contents of the list
void display() {
    // Check if the list is empty
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = start;
    printf("Linked List: ");
    // Traverse the list and print each node's data
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
