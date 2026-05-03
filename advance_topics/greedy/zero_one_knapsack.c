/*
NOTE:
This implementation uses a greedy approach (sorting by value/weight ratio).

⚠ For 0/1 Knapsack, this method is NOT always optimal.
It is only a heuristic (approximation), not the correct solution.

Greedy works correctly for Fractional Knapsack,
but for 0/1 Knapsack we must use Dynamic Programming (DP)
to guarantee the optimal (maximum profit) solution.

Example:
Greedy may give profit = 220,
but optimal (using DP) = 260.

Conclusion:
→ Current code = Greedy approximation
→ Optimal solution = DP (to be learned later)
*/

#include<stdio.h>
#include<stdlib.h>
void display(double m[][4],int size);
void quicSort(double m[][4],int low,int high);
int partition(double m[][4],int low,int high);
double fractionalKnapsack(double m[][4],int size,double k);
double fractionalKnapsack(double m[][4],int size,double k){
    printf("\nPerforming fractional knapsack maximizing profit \n\n");
    double profit=0;
    for(int i=0;i<size;i++){
        if(k<=0){
            printf("knapsack filled completely \n");
            return profit;
        }
        double weight=m[i][1];
        double itemNo=m[i][0];
        double ppu=m[i][3];
        if(weight<=k){
            printf("item no included is  %.2f\n",itemNo);
            profit+=weight*ppu;
            k-=weight;
        }
    }
    return profit;
}
void quicSort(double m[][4],int low,int high){
    if(low<high){
        int pivotIndx=partition(m,low,high);
        quicSort(m,low,pivotIndx-1);
        quicSort(m,pivotIndx+1,high);
    }
}
int partition(double m[][4],int low,int high){
    int pivot=high;
    int i=low;
    int j=low;
    while(j<high){
        if(m[j][3]>m[pivot][3]){
            for(int k=0;k<4;k++){
                double temp = m[i][k];
                m[i][k] = m[j][k];
                m[j][k] = temp;
            }
            i++;
        }
        j++;
    }
    for(int k=0;k<4;k++){
        double temp = m[i][k];
        m[i][k] = m[high][k];
        m[high][k] = temp;
    }
    return i;

}
void display(double m[][4],int size){
    printf("\n\t<<<<<< queries are >>>>>>\n");
    for(int i=0;i<size;i++){
        printf("Entered details  of %d item....... \n",i+1);
        for(int j=0;j<4;j++){
            if(j==0)printf("item no : ");
            if(j==1)printf("weight : ");
            if(j==2)printf("value : ");
            if(j==3)printf("price per unit : ");
            printf("%.2f     ",m[i][j]);
        }
        printf("\n\n");
    }
}
int main(){
    int size;
    double capacity;
    printf("\n\t\tWelcome to  a program demonstrating zero one  knapsack \n\n");
    printf("Enter the capacity of kanpsack : ");
    scanf("%lf",&capacity);
    printf("\n\nEnter the size of queries  : ");
    scanf("%d",&size);
    double arr[size][4];
    printf("Enter Details of items ( item no , weight , value)\n");
    for(int i=0;i<size;i++){
        printf("Enter details  of %d item....... \n",i+1);
        for(int j=0;j<3;j++){
            if(j==0)printf("item no : ");
            if(j==1)printf("weight : ");
            if(j==2)printf("value : ");
            scanf("%lf",&arr[i][j]);
        }
        // calculate price per unit
        double pricePerUnit=arr[i][2]/arr[i][1];
        arr[i][3]=pricePerUnit;
        printf("\n");
    }
    display(arr,size);
    quicSort(arr,0,size-1);
    display(arr,size);
    double profit=fractionalKnapsack(arr,size,capacity);
    printf("\n\n*****   MAX PROFIT IS   %.2f*****",profit);
    return 0;
}