#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node according to priority
void enqueue(int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    if (head == NULL || priority > head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d with priority %d\n", data, priority);
}

// Function to remove the highest priority element
void dequeue() {
    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Removed element %d with priority %d\n", temp->data, temp->priority);
    free(temp);
}

// Function to display the priority queue
void display() {
    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Priority Queue: [Data(Priority)] ");
    while (temp != NULL) {
        printf("%d(%d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, data, priority;
    while (1) {
        printf("\n---- Priority Queue Menu ----\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove highest priority)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
