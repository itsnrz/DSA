/*Insertion Sort is a simple comparison-based sorting algorithm that sorts
the array by building the final sorted list one element at a time.

It works by:
1. Taking the current element (key).
2. Comparing it with all elements on its left.
3. Shifting elements that are greater than the key to one position right.
4. Placing the key in its correct sorted position.
*/


/*| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(n)            |  // Already sorted array
| Average | O(n^2)          |
| Worst   | O(n^2)          |  // Reverse sorted array
*/


#include<stdio.h> // Standard input-output library for printf and scanf

// Function prototype for insertion_sort
void insertion_sort(int *a, int n);

int main(){
    int n;  // Integer to store array size
    printf("enter array size : "); // Prompt user for array size
    scanf("%d",&n); // Read size from the user

    int arr[n]; // Declare an array of size n (VLA)
    printf("enter elements of array  : "); // Prompt for array elements

    // Loop to read n integer inputs into arr
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("before sorting array is : "); // Print message
    // Print the unsorted array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    insertion_sort(arr,n); // Call insertion_sort function

    printf("\nafter sorting array is : "); // Print message
    // Print the sorted array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0; // Successful program termination
}

// Function to perform insertion sort on the array
void insertion_sort(int *a, int n){
    // Start loop from second element because the first element is already "sorted"
    for(int i=1;i<n;i++){
        int key = a[i]; // Store the current element as key
        int j = i - 1;  // Pointer to compare with elements on left side

        // Shift elements that are greater than key to one position right
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }

        // Insert key into its correct sorted position
        a[j+1] = key;
    }
}
