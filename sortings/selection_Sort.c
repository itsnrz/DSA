#include<stdio.h>
#include<stdlib.h>

void selection_sort(int *arr,int size){
    for(int i=0;i<size-1;i++){// assume last element to be sorted;
        int smallest=i;
        for(int j=i+1;j<size;j++){ // compare with all 
            smallest=arr[j]<arr[smallest]?j:smallest;
        }
        if(i!=smallest){
            int temp= arr[i]; arr[i]=arr[smallest];
            arr[smallest]=temp;
        }
    }
}
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
    selection_sort(arr,size);
    printf("\nArray after sorting : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}