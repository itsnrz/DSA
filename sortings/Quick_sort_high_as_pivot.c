#include<stdio.h>
#include<stdlib.h>

int partition(int low,int high,int *arr);
void quickSort(int low,int high ,int *arr);
void swap(int *a ,int *b);
int main(){
    int size=-1;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=(int *)calloc(size,sizeof(int));
    if(arr==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    printf("Enter elements of array : ");
    for(int i =0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nArray before sorting : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    quickSort(0,size-1,arr);
    printf("\nArray after sorting : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
void quickSort(int low,int high,int *arr){
    if(low<high){
        int pivotIndx=partition(low,high,arr);
        quickSort(low,pivotIndx-1,arr);
        quickSort(pivotIndx+1,high,arr);
    }
}
int partition(int low,int high,int *arr){
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[high],&arr[i]);
    return i;
}
void swap(int * a,int * b){
    int temp=*a;
    *a=*b;
    *b=temp;
}