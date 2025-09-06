#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node*pre;
    int data;
    struct node*next;
};
struct node*start=NULL;
void push(int val){
    struct node*t=(struct node*)malloc(sizeof(struct node));
    t->data=val;
    if(start==NULL){
        t->pre=NULL;
    }else{ 
        struct node*q=start;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=t;
        t->pre=q;
    }  
    t->next=NULL;
}
int main(){

}