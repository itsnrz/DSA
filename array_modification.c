#include<stdio.h>  // Standard input/output library
#include<conio.h>  // getch() for non-buffered character input
#include<stdlib.h> // exit(), malloc(), free()
#define max 20     // Macro for maximum array size

// Function prototypes
void input(int *a,int l);
void output(int *a,int l);
int insertArr(int *a,int l,int item,int pos);
int search(int *a,int item,int len);
int deleteElem(int *a,int pos,int len);
void selectSort(int*a,int len);
void mergeArr(int *a,int*b,int*c,int len1,int len2);
void quit();

int main(){
    printf("*** welcome to array modification program remember max len is 20 ***\n\n");
    // Declare variables for array operations
    int arr[max], pos=-1, item=-1, len=-1, sear=-1, indx=-1, len1=-1, len2=-1;
    
    // Main program loop
    while(1){
        printf("Press \"I\" for Input\n");
        printf("Press \"O\" for Output\n");
        printf("Press \"A\" for Insertion\n");
        printf("Press \"F\" for Searching\n");
        printf("Press \"D\" for Deleting\n");
        printf("Press \"S\" for Sorting\n");
        printf("Press \"M\" for Merging\n");
        printf("Press \"Q\" for quiting\n\n");
        
        char c=getch(); // Read a single character without waiting for Enter
        
        switch(c){
            case 'I':
            case 'i':
                printf("enter length : ");
                scanf("%d",&len);
                // Validate input length
                if (len < 0 || len > max) {
                    printf("Invalid length. Must be between 0 and %d.\n", max);
                    len = -1; // Reset length to indicate an empty array
                    break;
                }
                input(arr, len);
                break;

            case 'O':
            case 'o':
                // Check if an array has been initialized
                if(len==-1 || len==0){
                    printf("First input an array to output.\n");
                    break;
                }
                output(arr,len);
                break;

            case 'A':
            case 'a':
                // Check if the array is already at its maximum size
                if (len == max) {
                    printf("Array is full. Cannot insert more elements.\n");
                    break;
                }
                printf("enter the item you wanna insert : ");
                scanf("%d",&item);
                printf("enter the position where you wish to insert element (1 to %d): ", len + 1);
                scanf("%d",&pos);
                if(pos > len + 1 || pos < 1){
                    printf("Invalid position.\n");
                    break;
                }
                len = insertArr(arr, len, item, pos);
                if (len == -1) {
                    printf("Insertion failed.\n");
                } else {
                    printf("Element %d inserted successfully.\n", item);
                }
                break;

            case 'F':
            case 'f':
                // Check if an array exists to search
                if (len == -1 || len == 0) {
                    printf("First input an array to search.\n");
                    break;
                }
                printf("enter the item you wanna search : ");
                scanf("%d",&sear);
                indx = search(arr, sear, len);
                if(indx == -1) {
                    printf("Item does not exist in array.\n");
                } else {
                    printf("Item exists at index %d.\n", indx);
                }
                break;

            case 'D':
            case 'd':
                // Check if an array exists to delete from
                if (len == -1 || len == 0) {
                    printf("First input an array to delete from.\n");
                    break;
                }
                printf("enter the element you wanna delete: ");
                scanf("%d",&item);
                indx = search(arr, item, len); // Find the index of the item
                if(indx == -1) {
                    printf("Element is not present in the array.\n");
                } else {
                    len = deleteElem(arr, indx, len);
                    printf("Element deleted successfully.\n");
                }
                break;
                
            case 'S':
            case 's':
                if(len > max || len < 0) {
                    printf("Invalid array for sorting.\n");
                } else {
                    selectSort(arr, len);
                    printf("\nArray is sorted.\n");
                }
                break;
                
            case 'M':
            case 'm':
                printf("enter size of array a : ");
                scanf("%d",&len1);
                printf("enter size of array b : ");
                scanf("%d",&len2);
                
                // Allocate memory dynamically for the arrays
                int* a = (int*)malloc(len1 * sizeof(int));
                int* b = (int*)malloc(len2 * sizeof(int));
                int* c = (int*)malloc((len1 + len2) * sizeof(int));
                
                if(a == NULL || b == NULL || c == NULL){
                    printf("Memory allocation failed.\n");
                    // Free any successfully allocated memory before breaking
                    free(a); free(b); free(c);
                    break;
                }
                
                printf("enter first array: ");
                input(a, len1);
                printf("enter second array: ");
                input(b, len2);
                
                printf("Sorting arrays a & b for merging...\n");
                selectSort(a, len1);
                selectSort(b, len2);
                
                printf("Sorted array a: ");
                output(a, len1);
                printf("Sorted array b: ");
                output(b, len2);
                
                mergeArr(a, b, c, len1, len2);
                
                printf("Array c after merging a & b: ");
                output(c, len1 + len2);
                
                printf("Memory allocated is now freed.\n");
                // Free the dynamically allocated memory
                free(a);
                free(b);
                free(c);
                break;

            case 'Q':
            case 'q':
                quit();
                break;
            
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        // Consume any remaining newline characters from previous input
        fflush(stdin);
    }
    return 0;
}

// Function to input elements into an array
void input(int* a, int l){
    printf("enter %d elements of array: ", l);
    for(int i = 0; i < l; i++){
        scanf("%d", &a[i]);
    }
}

// Function to display the elements of an array
void output(int *a, int l){
    printf("elements of array: ");
    for(int i = 0; i < l; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to insert an item at a specified position in an array
int insertArr(int *a, int l, int item, int pos){
    if(l >= max){ // Check if the array is already full
        printf("Size greater than max.");
        return -1;
    }
    // Shift elements to the right to make space for the new item
    for(int i = l; i >= pos; i--){
        a[i] = a[i-1];
    }
    a[pos-1] = item; // Insert the new item
    return l + 1;    // Return the new length
}

// Function to search for an item in an array and return its index
int search(int *a, int item, int len){
    for(int i = 0; i < len; i++){
        if(a[i] == item){
            return i; // Return the index if the item is found
        }
    }
    return -1; // Return -1 if the item is not found
}

// Function to delete an element from an array at a given position
int deleteElem(int *a, int pos, int len){
    // Shift elements to the left to overwrite the element at 'pos'
    for(int i = pos; i < len - 1; i++){
        a[i] = a[i+1];
    }
    return len - 1; // Return the new length
}

// Function to sort an array using the Selection Sort algorithm
void selectSort(int* a, int len){
    for(int i = 0; i < len - 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < len; j++){
            if(a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

// Function to merge two sorted arrays into a third one
void mergeArr(int* a, int* b, int* c, int len1, int len2){
    int i = 0, j = 0, k = 0;
    // Compare elements from both arrays and add the smaller one to the merged array
    while(i < len1 && j < len2){
        if(a[i] < b[j]){
            c[k++] = a[i++];
        } else if(a[i] > b[j]){
            c[k++] = b[j++];
        } else { // Handle duplicate elements by adding both
            c[k++] = a[i++];
            c[k++] = b[j++];
        }
    }
    // Add any remaining elements from the first array
    while(i < len1){
        c[k++] = a[i++];
    }
    // Add any remaining elements from the second array
    while(j < len2){
        c[k++] = b[j++];
    }
}

// Function to handle the quit option
void quit(){
    printf("\nDo you really want to quit (y/n)? ");
    char c = getch();
    if(c == 'y' || c == 'Y'){
        printf("\nExiting program.\n");
        exit(0);
    }
    printf("\nReturning to menu.\n");
}