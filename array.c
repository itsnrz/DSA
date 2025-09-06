#include<stdio.h>
#include<conio.h>//getch()
#include<stdlib.h>//exit()
#define max 20
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
    int arr[max],pos=-1,item=-1,len=-1,sear=-1,indx=-1,len1=-1,len2=-1;
    while(1){
        printf("Press \"I\" for Input\n");
        printf("Press \"O\" for Output\n");
        printf("Press \"A\" for Insertion\n");
        printf("Press \"F\" for Searching\n");
        printf("Press \"D\" for Deleting\n");
        printf("Press \"S\" for Sorting\n");
        printf("Press \"M\" for Merging\n");
        printf("Press \"Q\" for quiting\n\n");
        // printf("enter choice : ");
        char c=getch();
        switch(c){
            case 'I':
            case 'i':
            printf("enter length : ");
            scanf("%d",&len);
            input(arr,len);
            break;

            case 'O':
            case 'o':
            if(len==-1){
                printf("first input an array for output\n");
                break;
            }
            output(arr,len);
            break;

            case 'A':
            case 'a':
            printf("enter the item you wanna insert : ");
            scanf("%d",&item);
            printf("enter the position where you wish to insert element : ");
            scanf("%d",&pos);
            if(pos>len+1||pos<1){
                printf("invalid pos\n");
                break;
            }
            len=insertArr(arr,len,item,pos);
            if(len==-1){
                printf("EXITING");
                exit(1);
            }
            break;

            case 'F':
            case 'f':
            printf("enter the item you wanna search : ");
            scanf("%d",&sear);
            indx=search(arr,sear,len);
            if(indx==-1) printf("item does not exist in array\n");
            else printf("item exist in %d index\n",indx);
            break;

            case 'D':
            case 'd':
            printf("enter the element you wanna deleteElem : ");
            scanf("%d",&item);
            indx=search(arr,item,len);
            if(indx<0||indx>=len) printf("element is not present in array\n");
            else len=deleteElem(arr,indx,len);
            break;
            
            case 'S':
            case 's':
            if(len>max||len<0) printf("invalid array for sorting\n");
            else{
                selectSort(arr,len);
                printf("\narray is sorted\n");
            }
            break;
            
            case 'M':
            case 'm':
            printf("enter size of array a : ");
            scanf("%d",&len1);
            printf("enter size of array b : ");
            scanf("%d",&len2);
            int*a=(int*)calloc(len1,sizeof(int));
            int*b=(int*)calloc(len2,sizeof(int));
            int*c=(int*)calloc(len1+len2,sizeof(int));
            if(a==NULL || b==NULL || c==NULL){
                printf("memory allocation failed\n");
                break;
            }
            printf("enter first array : ");
            input(a,len1);
            printf("enter second array : ");
            input(b,len2);
            printf("sorting arrays a & b  for merging\n");
            selectSort(a,len1);
            selectSort(b,len2);
            output(a,len1);
            output(b,len2);
            mergeArr(a,b,c,len1,len2);
            printf("array c after merging a & b : ");
            output(c,len1+len2);
            printf("memory allocated is now freed\n");
            free(a); free(b); free(c);
            break;

            case 'Q':
            case 'q':
            quit();
        }
    }
    return 0;
}

void input(int*a ,int l){
    printf("enter elements of array : ");
    for(int i=0;i<l;i++){
        scanf("%d",&a[i]);
    }
}

void output(int *a,int l){
    printf("elements of array : ");
    for(int i=0;i<l;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int insertArr(int *a,int l,int item,int pos){
    if(l==max){
        printf("size greater than max");
        return -1;
    }
    l=l+1;
    for(int i=l-1;i>=pos-1;i--){
        a[i]=a[i-1];
    }
    a[pos-1]=item;
    return l;
}

int search(int *a,int item,int len){
    int indx=-1;
    for(int i=0;i<len;i++){
        if(a[i]==item){
            indx=i;
            break;
        }
    }
    return indx;
}

int deleteElem(int *a,int pos,int len){
     int i=pos;
     for(;i<len-1;i++) a[i]=a[i+1];
     return len-1;
}

void selectSort(int*a,int len){
    for(int i=0;i<len;i++){
        int min=i;
        for(int j=i+1;j<len;j++){
            if(a[min]>a[j]){
                int t=a[min];
                a[min]=a[j];
                a[j]=t;
            }
        }
    }
}

void mergeArr(int*a,int*b,int*c,int len1,int len2){
    int i=0,j=0,k=0;
    while(i<len1&&j<len2){
        if(a[i]<b[j]){
            c[k++]=a[i];
            i++;
        }else if(a[i]>b[j]){
            c[k++]=b[j];
            j++;
        }else{
            c[k++]=a[i];
            c[k++]=b[j];
            i++; j++;
        }
    }
    while(i<len1) c[k++]=a[i++];
    while(j<len2) c[k++]=b[j++];
}

void quit(){
    printf("do you really wanna quit(y/n) ");
    char c=getch();
    if(c=='y'){
        printf("\nEXITING");
        exit(0);
    }
    return ;
}


