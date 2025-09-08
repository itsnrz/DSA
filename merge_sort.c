/*Merge Sort is a “divide and conquer” algorithm that sorts an array by:

Dividing the array into two halves.

Sorting each half recursively.

Merging the two sorted halves into one sorted array.*/


/*| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(n log n)      |
| Average | O(n log n)      |
| Worst   | O(n log n)      |
*/

#include<stdio.h> // Standard input-output library for functions like printf and scanf

// Function prototypes for merge_sort and merge
// These declare the functions before they are defined, so the compiler knows they exist
void merge_sort(int*a,int l,int r);
void merge(int *a,int l,int r,int mid);

int main(){
    int n,l=0; // Declare an integer n for array size and l for the left boundary, initialized to 0
    printf("enter array size : "); // Prompt the user to enter the size of the array
    scanf("%d",&n); // Read the integer input from the user and store it in n
    int arr[n]; // Declare a variable-length array (VLA) of size n
    printf("enter elements of array  : "); // Prompt the user to enter array elements
    
    // Loop to read n elements from the user and store them in the array
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("before swapping array is : "); // Print a message indicating the unsorted array
    // Loop to print the elements of the unsorted array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    merge_sort(arr,l,n-1); // Call the merge_sort function to sort the array.
                           // The parameters are the array itself, the starting index (0), and the ending index (n-1).
    
    printf("\nafter swapping array is : "); // Print a message for the sorted array
    // Loop to print the elements of the sorted array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0; // Return 0 to indicate successful program execution
}

// Recursive function to perform merge sort on a subarray
void merge_sort(int*a,int l,int r){
    // Base case: The recursion stops when the left index is no longer less than the right index,
    // which means the subarray has one or zero elements and is already sorted.
    if(l<r){
        // Calculate the middle index to divide the array into two halves
        int mid=l+(r-l)/2;
        
        // Recursively call merge_sort for the left half of the array
        merge_sort(a,l,mid);
        
        // Recursively call merge_sort for the right half of the array
        merge_sort(a,mid+1,r);
        
        // After the two halves are sorted, merge them back together
        merge(a,l,r,mid);
    }
}

// Function to merge two sorted subarrays into a single sorted array
void merge(int *a,int l,int r,int mid){
    // Calculate the lengths of the two subarrays
    int l1=mid-l+1,l2=r-mid;
    
    // Create temporary arrays to hold the elements of the left and right subarrays
    int left[l1];
    int right[l2];
    
    // Copy data from the original array into the temporary left array
    for(int i=0;i<l1;i++){
        left[i]=a[l+i];
    }
    
    // Copy data from the original array into the temporary right array
    for(int i=0;i<l2;i++){
        right[i]=a[mid+i+1];
    }
    
    // Initialize pointers for iterating through the arrays
    int k=l,i=0,j=0; // k for the main array, i for the left temp array, j for the right temp array
    
    // Merge the temporary arrays back into the main array 'a' in a sorted order
    // This loop compares elements from both subarrays and places the smaller one into the main array
    while(i<l1&&j<l2){
        if(left[i]<=right[j]){ // If the element in the left array is smaller or equal
            a[k++]=left[i];    // Place it in the main array and increment the pointers
            i++;
        }else{                // If the element in the right array is smaller
            a[k++]=right[j];   // Place it in the main array and increment the pointers
            j++;
        }
    }
    
    // If there are any remaining elements in the left subarray, copy them to the main array
    while(i<l1){
        a[k++]=left[i]; i++;
    }
    
    // If there are any remaining elements in the right subarray, copy them to the main array
    while(j<l2){
        a[k++]=right[j]; j++;
    }
}