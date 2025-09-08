/*Bubble Sort is a simple sorting algorithm that repeatedly compares two adjacent elements in an array and
swaps them if they are in the wrong order. This process continues until the array is completely sorted,
with the largest elements “bubbling up” to the end in each pass.*/

/*| Case             | Complexity | Explanation                                                            |
| ---------------- | ---------- | ---------------------------------------------------------------------- |
| **Best Case**    | O(n)       | Array already sorted → only 1 pass needed (due to optimization check). |
| **Average Case** | O(n²)      | About half of the elements need swapping in each pass.                 |
| **Worst Case**   | O(n²)      | Array is in reverse order → maximum number of comparisons and swaps.   |
*/

#include<stdio.h> // Standard input-output library for functions like printf and scanf

int main(){
    int n; // Declare an integer variable to store the size of the array
    
    printf("enter array size : "); // Prompt the user to enter the size
    scanf("%d",&n); // Read the user's input and store it in 'n'
    
    int arr[n]; // Declare a variable-length array (VLA) of size 'n'
    
    printf("enter elements of array  : "); // Prompt the user to enter array elements
    // Loop to read 'n' elements from the user and store them in the array
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("before swapping array is : "); // Print a message indicating the unsorted array
    // Loop to print the elements of the unsorted array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
    // Bubble Sort Algorithm
    // The outer loop runs 'n-1' times, with each pass moving the largest unsorted element to its correct position at the end
    for(int i=0;i<n-1;i++){
        // 'isSorted' is a flag for optimization. If no swaps occur in a pass, the array is already sorted, and we can break the loop.
        int isSorted = 0;
        
        // The inner loop iterates through the unsorted portion of the array
        // 'n-i-1' is the number of elements to compare in the current pass. With each outer loop iteration, the largest element "bubbles up" to the end, so we can ignore it in the next pass.
        for(int j=0;j<n-i-1;j++){
            // Compare adjacent elements
            if(arr[j]>arr[j+1]){
                // If the element on the left is greater than the one on the right, swap them
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                isSorted = 1; // A swap occurred, so the array is not yet sorted
            }
        }
        // If 'isSorted' is still 0 after a full pass of the inner loop, it means no swaps were made, so the array is sorted
        if(!isSorted) {
            break;
        }
    }
    
    printf("\nafter swapping array is : "); // Print a message for the sorted array
    // Loop to print the elements of the sorted array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
    return 0; // Return 0 to indicate successful program execution
}