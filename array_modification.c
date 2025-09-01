#include<stdio.h>
#include<stdlib.h>
#define MAX 20 // Macro to define the maximum size of the array

// Function prototypes - Declaring the functions before they are used in main()
void input(int *a, int l); // Function to input elements into the array
void display(int *a, int l); // Function to display the elements of the array
int insertArr(int *a, int l, int item, int pos); // Function to insert an element at a given position
int deleteArr(int *a, int l, int pos); // Function to delete an element from a given position
int searchArr(int *a, int l, int key); // Function to search for an element and return its position
void sortArr(int *a, int l); // Function to sort the array
void quit(); // Function to exit the program

int main() {
    printf("*** welcome to array modification program (max len=20) ***\n\n");
    int arr[MAX], pos = -1, item = -1, len = 0; // Declare array and variables. 'len' stores the current number of elements.
    while (1) { // Infinite loop to keep the program running until the user decides to quit
        printf("\nPress I for input\nPress D for display\nPress A for insertion\nPress X for deletion\nPress S for search\nPress O for sort\nPress Q for quit\nEnter choice : ");
        char c;
        scanf(" %c", &c); // Read the user's choice
        switch (c) { // Use a switch statement to handle different choices
            case 'I': case 'i': // Case for inputting array elements
                printf("Enter length (<=%d): ", MAX);
                scanf("%d", &len);
                if (len > MAX || len < 1) { // Check for valid length
                    printf("Invalid length!\n");
                    len = 0;
                    break;
                }
                input(arr, len); // Call the input function
                break;

            case 'D': case 'd': // Case for displaying the array
                if (len <= 0) printf("Array is empty, input first!\n");
                else display(arr, len); // Call the display function if the array is not empty
                break;

            case 'A': case 'a': // Case for inserting an element
                if (len <= 0) {
                    printf("Array is empty, input first!\n");
                    break;
                }
                printf("Enter item: ");
                scanf("%d", &item);
                printf("Enter position (1-%d): ", len + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > len + 1) { // Check for a valid position
                    printf("Invalid position!\n");
                    break;
                }
                len = insertArr(arr, len, item, pos); // Call the insert function and update the length
                break;

            case 'X': case 'x': // Case for deleting an element
                if (len <= 0) {
                    printf("Array is empty!\n");
                    break;
                }
                printf("Enter position to delete (1-%d): ", len);
                scanf("%d", &pos);
                if (pos < 1 || pos > len) { // Check for a valid position
                    printf("Invalid position!\n");
                    break;
                }
                len = deleteArr(arr, len, pos); // Call the delete function and update the length
                break;

            case 'S': case 's': // Case for searching for an element
                if (len <= 0) {
                    printf("Array is empty!\n");
                    break;
                }
                printf("Enter item to search: ");
                scanf("%d", &item);
                pos = searchArr(arr, len, item); // Call the search function
                if (pos == -1) printf("Item not found!\n");
                else printf("Item found at position %d\n", pos);
                break;

            case 'O': case 'o': // Case for sorting the array
                if (len <= 0) {
                    printf("Array is empty!\n");
                    break;
                }
                sortArr(arr, len); // Call the sort function
                printf("Array sorted.\n");
                break;

            case 'Q': case 'q':
                quit(); // Call the quit function to exit
                break;

            default:
                printf("Invalid choice!\n"); // Handle invalid input
        }
    }
    return 0; // Return 0 to indicate successful execution
}

// Function to get elements from the user
void input(int *a, int l) {
    printf("Enter %d elements: ", l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &a[i]); // Read each element into the array
    }
}

// Function to display the elements of the array
void display(int *a, int l) {
    printf("Array: ");
    for (int i = 0; i < l; i++) {
        printf("%d ", a[i]); // Print each element
    }
    printf("\n");
}

// Function to insert an element at a specified position
int insertArr(int *a, int l, int item, int pos) {
    if (l == MAX) { // Check if the array is already at its maximum capacity
        printf("Array full!\n");
        return l;
    }
    // Shift elements to the right to make space for the new element
    for (int i = l; i >= pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos - 1] = item; // Insert the new element at the specified position (adjusting for 0-based index)
    printf("Inserted.\n");
    return l + 1; // Return the new, increased length of the array
}

// Function to delete an element from a specified position
int deleteArr(int *a, int l, int pos) {
    printf("Deleted %d from position %d\n", a[pos - 1], pos);
    // Shift elements to the left to fill the gap created by the deletion
    for (int i = pos - 1; i < l - 1; i++) {
        a[i] = a[i + 1];
    }
    return l - 1; // Return the new, decreased length of the array
}

// Function to search for an element using linear search
int searchArr(int *a, int l, int key) {
    for (int i = 0; i < l; i++) {
        if (a[i] == key) {
            return i + 1; // Return the 1-based position if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to sort the array using Bubble Sort algorithm
void sortArr(int *a, int l) {
    // Outer loop for passes
    for (int i = 0; i < l - 1; i++) {
        // Inner loop for comparisons and swaps
        for (int j = 0; j < l - i - 1; j++) {
            if (a[j] > a[j + 1]) { // Compare adjacent elements
                // Swap if the element on the left is greater than the one on the right
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Function to handle program exit
void quit() {
    char c;
    printf("Quit (y/n)? ");
    scanf(" %c", &c);
    if (c == 'y' || c == 'Y') {
        exit(0); // Terminate the program with a status of 0
    }
}