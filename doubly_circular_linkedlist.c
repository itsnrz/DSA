#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }
    struct Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }
    struct Node* last = head->prev;
    newNode->next = head;
    head->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head) { // only one node
        head = NULL;
        free(temp);
        return;
    }
    struct Node* last = head->prev;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
    printf("Deleted from beginning.\n");
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* last = head->prev;
    if (head->next == head) { // only one node
        head = NULL;
        free(last);
        return;
    }
    struct Node* secondLast = last->prev;
    secondLast->next = head;
    head->prev = secondLast;
    free(last);
    printf("Deleted from end.\n");
}

// Display in forward direction
void displayForward() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("List (forward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Display in reverse direction
void displayReverse() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* last = head->prev;
    struct Node* temp = last;
    printf("List (reverse): ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("\n");
}

// Main menu
int main() {
    int choice, data;
    while (1) {
        printf("\n---- Doubly Circular Linked List Menu ----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Reverse\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayReverse();
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
