/*
    -------------------------------
    CIRCULAR LINKED LIST IN C
    -------------------------------

    🔹 A circular linked list is a variation of a linked list 
       where the last node points back to the first node, 
       forming a circle.

    🔹 Unlike singly linked lists (where the last node points to NULL),
       circular linked lists allow continuous traversal without 
       reaching the end.

    🔹 We usually maintain a 'last' pointer which helps to easily 
       access both the first node (last->next) and the last node itself.

    ✅ Applications:
       - Useful in CPU scheduling (Round Robin scheduling).
       - Implementing buffers (e.g., circular queues).
       - Multiplayer board games (turn rotation).
       - Repeatedly traversing a list without restarting.

    ✅ Advantages:
       - Efficient for problems where circular traversal is required.
       - Easy to insert at both ends if using a 'last' pointer.
       - Memory efficient compared to arrays (dynamic size).
*/

#include <stdio.h>  // Standard input/output library for functions like printf and scanf
#include <stdlib.h> // Standard library for dynamic memory allocation (malloc, free) and program termination (exit)

// Structure of each node in the circular linked list
struct node {
    int data;          // The data part of the node
    struct node* next; // Pointer to the next node in the circular list
};

// A global pointer 'last' to keep track of the last node.
// This single pointer allows easy access to both the last node and the first node
// (since the first node is last->next).
struct node* last = NULL;

// Function prototypes to declare the functions used
void add_front(int item);
void add_back(int item);
void delete_front();
void delete_back();
void display();

int main() {
    int choice, item;

    // Menu-driven program for user interaction
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Add at Front\n");
        printf("2. Add at Back\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Back\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert at front: ");
                scanf("%d", &item);
                add_front(item);
                break;

            case 2:
                printf("Enter item to insert at back: ");
                scanf("%d", &item);
                add_back(item);
                break;

            case 3:
                delete_front();
                break;

            case 4:
                delete_back();
                break;

            case 5:
                display();
                break;

            case 6:
                // Exit the program
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to add a new node at the front of the circular linked list
void add_front(int item) {
    // Allocate memory for the new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = item;

    // Case 1: The list is empty
    if (last == NULL) {
        last = temp;        // The new node is the only node in the list
        last->next = last;  // It points to itself to form a circle
    } else {
        // Case 2: The list is not empty
        temp->next = last->next; // New node's next points to the current first node
        last->next = temp;       // The last node's next is updated to point to the new node
    }
    printf("%d inserted at front.\n", item);
}

// Function to add a new node at the back of the circular linked list
void add_back(int item) {
    // Allocate memory for the new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = item;

    // Case 1: The list is empty
    if (last == NULL) {
        last = temp;        // The new node is the only node
        last->next = last;  // It points to itself
    } else {
        // Case 2: The list is not empty
        temp->next = last->next; // New node points to the current first node
        last->next = temp;       // The old last node's next points to the new node
        last = temp;             // Update 'last' to point to the new node
    }
    printf("%d inserted at back.\n", item);
}

// Function to delete a node from the front of the circular linked list
void delete_front() {
    // Check if the list is empty
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = last->next; // 'temp' points to the first node to be deleted

    // Case 1: Only one node in the list
    if (last == last->next) {
        last = NULL; // The list becomes empty
    } else {
        // Case 2: More than one node
        last->next = temp->next; // The last node now points to the second node
    }
    printf("%d deleted from front.\n", temp->data);
    free(temp); // Free the memory of the deleted node
}

// Function to delete a node from the back of the circular linked list
void delete_back() {
    // Check if the list is empty
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = last->next; // 'temp' starts at the first node

    // Case 1: Only one node in the list
    if (last == last->next) {
        printf("%d deleted from back.\n", last->data);
        free(last);
        last = NULL; // The list becomes empty
        return;
    }

    // Traverse the list to find the node right before the 'last' node
    while (temp->next != last) {
        temp = temp->next;
    }

    // 'temp' is now the second-to-last node
    temp->next = last->next; // The new last node's next points to the first node
    printf("%d deleted from back.\n", last->data);
    free(last);    // Free the old last node
    last = temp;   // Update the 'last' pointer to the new last node
}

// Function to display all elements of the circular linked list
void display() {
    // Check if the list is empty
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = last->next; // Start traversal from the first node

    printf("Circular Linked List: ");
    // Traverse the list using a do-while loop, which guarantees at least one iteration
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next); // The loop continues until we loop back to the first node

    printf("(back to start)\n");
}