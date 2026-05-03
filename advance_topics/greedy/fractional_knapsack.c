#include<stdio.h>
#include<stdlib.h>
void display(double m[][4],int size);
void sort(double m[][4],int size);
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
        }else{
            printf("item no included is %.2f , only %.2f units\n", itemNo, k);
            profit+=k*ppu;
            k=0;
            return profit;
        }
    }
    return profit;
}
void sort(double m[][4],int size){
    // 3 is indx of pricePerUnit
    for(int i=0;i<size-1;i++){
        int big=i;
        for(int j=i+1;j<size;j++){
            if(m[big][3]<m[j][3])big=j;
        }
        if(i!=big){
            //swap
            double temp[4];
            for(int k=0;k<4;k++) temp[k]=m[i][k];
            for(int k=0;k<4;k++) m[i][k]=m[big][k];
            for(int k=0;k<4;k++) m[big][k]=temp[k];
        }
    }
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
    printf("\n\t\tWelcome to  a program demonstrating fractional knapsack \n\n");
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
    sort(arr,size);
    display(arr,size);
    double profit=fractionalKnapsack(arr,size,capacity);
    printf("\n\n*****   MAX PROFIT IS   %.2f*****",profit);
    return 0;
}