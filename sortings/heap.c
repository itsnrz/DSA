/*Heap Sort is an efficient comparison-based sorting algorithm that uses
a Binary Heap data structure.

It works in two main steps:

1. Build a Max-Heap from the array.
2. Repeatedly swap the root (maximum element) with the last element,
   reduce the heap size, and heapify the root to maintain heap property.

Since the largest element is placed at the end each time, the array becomes sorted.
*/


/*| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(n log n)      |
| Average | O(n log n)      |
| Worst   | O(n log n)      |
*/


#include<stdio.h> // Standard input-output library

// Function prototypes for heap_sort and heapify
void heap_sort(int *a, int n);
void heapify(int *a, int n, int i);

int main(){
    int n; // Array size
    printf("enter array size : "); 
    scanf("%d", &n);

    int arr[n]; // Declare array of size n
    printf("enter elements of array  : ");

    // Input array elements
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("before sorting array is : ");
    // Print unsorted array
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    heap_sort(arr, n); // Call heap sort function

    printf("\nafter sorting array is : ");
    // Print sorted array
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0; // End of program
}

// Function to perform Heap Sort
void heap_sort(int *a, int n){
    // Step 1: Build max heap from the array
    // Start from last non-leaf node: (n/2 - 1) and move upward
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }

    // Step 2: Swap root with last element and reduce heap size
    for(int i = n - 1; i > 0; i--){
        // Swap a[0] (max element) with a[i]
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Heapify reduced heap
        heapify(a, i, 0);
    }
}

// Function to maintain max-heap property
void heapify(int *a, int n, int i){
    int largest = i;     // Assume root is largest
    int left = 2*i + 1;  // Left child index
    int right = 2*i + 2; // Right child index

    // If left child exists and is greater than root
    if(left < n && a[left] > a[largest]){
        largest = left;
    }

    // If right child exists and is greater than current largest
    if(right < n && a[right] > a[largest]){
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if(largest != i){
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify affected subtree
        heapify(a, n, largest);
    }
}
