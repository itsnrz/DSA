#include<stdio.h>
#include<stdlib.h>
 
typedef struct node{
    int data;
    struct node *lchild,*rchild;
}tree;
tree*root=NULL;

void preorder(tree* ptr);
void inorder(tree* ptr);
void postorder(tree* ptr);
void find(tree**par,tree**loc, int item);
void insert(tree*par,tree * pos,int item);
void del(tree**par,tree**loc);
void remove0(tree*par,tree*loc);
void remove1(tree*par,tree*loc);
void remove2(tree*par,tree*loc);

int main(){
    int item=-1,c=-1;
    tree *par,*pos,*ptr;
    char ch;
    while(1){
        printf("press\n1 for inserting new element \npress 2 for find \n3 for traversal \n4 for deleting an element\n5 for exiting\nENTER  :  ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("enter element you wanna insert to BST : ");
            scanf("%d",&item);
            find(&par,&pos, item);
            if(pos) printf("element already exist in BST \n");
            else{
                insert(par,pos,item);
                printf("%d element added to tree\n",item);
            }
            break; 

        case 2:
            if(root==NULL){
                printf("TREE is empty \n"); break;
            }
            printf("enter element you wanna search : ");
            scanf("%d",&item);
            find(&par,&pos, item);
            if(pos)printf("element find at %d pos is %d \n",pos,pos->data);
            else printf("element does not exist \n");
            break; 
            
        case 3:
            if(root==NULL){
                printf("TREE is empty \n"); break;
            }
            ptr=root;
            printf("enter a for preorder traversal\nenter b for inorder traversal\nenter c for postorder traversal\n\n");
            scanf(" %c",&ch);       
            switch (ch)
            {
            case 'a':
               printf("Elements of bst in preorder traversal are : ");
               preorder(ptr); printf("\n");
               break;
            case 'b':
               printf("Elements of bst in inorder traversal are : ");
               inorder(ptr); printf("\n");
               break;
            case  'c':
               printf("Elements of bst in postorder traversal are : ");
               postorder(ptr); printf("\n");
               break;
            default:
               printf("*****INVALID CHOICE*****\n");
                break;
            }
            break;
        case 4:
            printf("enter element you wanna delete");
            scanf("%d",&item);
            find(&par,&pos,item);
            if(pos){
                del(&par,&pos);
            }else printf("element is not present in tree \n");
            break;
        case 5: 
           exit(1);
            
        default:
         printf("*****INVALID CHOICE*****\n");
            break;
        }
    }
    return 0;
}

void insert(tree*par,tree * pos,int item){
    tree * p=(tree*)malloc(sizeof(tree));
    p->data=item;
    p->lchild=p->rchild=NULL;
    if(root==NULL){
        root= p;
    }else if(item>par->data) par->rchild=p;
    else par->lchild=p;
}

void find(tree**par,tree**loc, int item) {
    tree*ptr, *parptr;

    if (root == NULL) {
        printf("Tree is empty(find func)\n\n");
        *par = *loc = NULL;
        return;
    }

    // if the root itself holds the item
    if (root->data == item) {
        *loc = root;
        *par = NULL;
        return;
    }

    // initialize search pointers
    if (item < root->data) {
        parptr = root;
        ptr = root->lchild;
    } else {
        parptr = root;
        ptr = root->rchild;
    }

    // search down the tree
    while (ptr != NULL) {
        if (item == ptr->data) {
            *loc = ptr;
            *par = parptr;
            return;
        }
        parptr = ptr;
        if (item < ptr->data)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }

    // if not found
    *loc = NULL;
    *par = parptr;
}

void preorder(tree* ptr){
    if(ptr==NULL) return;
    printf(" %d",ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(tree* ptr){
    if(ptr==NULL) return ;
    inorder(ptr->lchild);
    printf(" %d",ptr->data);
    inorder(ptr->rchild);
}

void postorder(tree* ptr){
    if(ptr==NULL) return ;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf(" %d",ptr->data);
}

void del(tree **par,tree** pos){
    if (*par == NULL) { // root node deletion
    if ((*pos)->lchild == NULL && (*pos)->rchild == NULL)
        root = NULL;
    else if ((*pos)->lchild == NULL)
        root = (*pos)->rchild;
    else if ((*pos)->rchild == NULL)
        root = (*pos)->lchild;
    else
        remove2(*par, *pos); // root has 2 children handled later
    free(*pos);
    return;
    } 
      if(root==NULL){ // empty tree
        printf("tree is empty \n");
        return;
      }else if(*pos==NULL){//element does not exist in tree
        printf("element is not present in tree\n"); return;
      }else if((*pos)->lchild==NULL&&(*pos)->rchild==NULL){// leaf node
         remove0(*par,*pos);
      }else if(((*pos)->lchild!=NULL&&(*pos)->rchild==NULL) || ((*pos)->rchild!=NULL&&(*pos)->lchild==NULL)){ // single child of node
        remove1(*par,*pos);
      }else{ // both child present
        remove2(*par,*pos);
      }
    free(*pos);
}

void remove0(tree * par, tree * pos){
    if(par->lchild==pos)par->lchild=NULL;
    else par->rchild=NULL;
}

void remove1(tree * par, tree * pos){
       tree * child;
       if(pos->lchild!=NULL)child=pos->lchild;
       else child=pos->rchild;
       if(par->lchild==pos)par->lchild=child;
       else par->rchild=child;
}

void remove2(tree * par, tree * pos){
    tree*parsuc,*suc;
    parsuc=pos;
    suc=pos->rchild;
    while(suc->lchild!=NULL){
        parsuc=suc;
        suc=suc->lchild;
    }
    if(par==NULL)root =suc;
    else if(suc->rchild==NULL){ // suc is a leaf node
        remove0(parsuc,suc);
    }else if(suc->rchild !=NULL){ // suc has one child 
        remove1(parsuc,suc);
    }
    if(par->rchild==pos) par->rchild=suc;
    else if(par->lchild==pos) par->lchild=suc;
    suc->lchild=pos->lchild;
    suc->rchild=pos->rchild;
}