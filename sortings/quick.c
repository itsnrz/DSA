/*Quick Sort is a “divide and conquer” sorting algorithm that works by:

1. Choosing a pivot element.
2. Partitioning the array so that:
      - Elements smaller than pivot move to its left.
      - Elements greater than pivot move to its right.
3. Recursively applying Quick Sort on the left and right partitions.

It is one of the fastest comparison-based sorting algorithms in practice.
*/


/*| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(n log n)      |
| Average | O(n log n)      |
| Worst   | O(n^2)          |  // Happens when pivot is always smallest or largest
*/


#include<stdio.h> // Standard input-output library for printf and scanf

// Function prototypes for quick_sort and partition
void quick_sort(int *a, int l, int r);
int partition(int *a, int l, int r);

int main(){
    int n; // Declare integer for array size
    printf("enter array size : "); // Prompt for array size
    scanf("%d",&n); // Read array size

    int arr[n]; // Declare array of size n
    printf("enter elements of array  : "); // Prompt for array elements
    
    // Read n array elements
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("before sorting array is : "); // Message before sorting
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]); // Print unsorted array
    }

    quick_sort(arr, 0, n-1); // Call quick_sort on entire array

    printf("\nafter sorting array is : "); // Message for sorted array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]); // Print sorted array
    }

    return 0; // Successful execution
}

// Recursive Quick Sort function
void quick_sort(int *a, int l, int r){
    // Base condition: sort only if left index < right index
    if(l < r){
        // Partition the array and get pivot index
        int pi = partition(a, l, r);
        
        // Recursively sort left subarray (elements before pivot)
        quick_sort(a, l, pi - 1);
        
        // Recursively sort right subarray (elements after pivot)
        quick_sort(a, pi + 1, r);
    }
}

// Partition function: places pivot at correct location
int partition(int *a, int l, int r){
    int pivot = a[r]; // Choose last element as pivot
    int i = l - 1;    // i tracks correct position for smaller element

    // Loop from left to right - 1
    for(int j = l; j < r; j++){
        // If current element is smaller than or equal to pivot
        if(a[j] <= pivot){
            i++; // Move pointer to next position
            // Swap a[i] and a[j]
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // After loop, place pivot after the last smaller element
    int temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;

    return i + 1; // Return pivot index
}
