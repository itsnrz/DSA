#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *lchild, *rchild;
} tree;

tree *root = NULL;

void preorder(tree *ptr);
void inorder(tree *ptr);
void postorder(tree *ptr);
void find(tree **par, tree **loc, int item);
// Removed 'pos' parameter from prototype for cleaner code
void insert(tree *par, int item); 
void del(tree **par, tree **pos);
void remove0(tree *par, tree *pos);
void remove1(tree *par, tree *pos);
void remove2(tree *par, tree *pos);

int main() {
    int item, c;
    tree *par, *pos, *ptr;
    char ch;

    while (1) {
        printf("\npress\n");
        printf("1 for inserting new element\n");
        printf("2 for find\n");
        printf("3 for traversal\n");
        printf("4 for deleting an element\n");
        printf("5 for exiting\n");
        printf("ENTER  :  ");
        if (scanf("%d", &c) != 1) {
            // Handle non-integer input to prevent infinite loop
            while(getchar() != '\n');
            printf("*****INVALID CHOICE*****\n");
            continue;
        }

        switch (c) {
            case 1:
                printf("enter element you wanna insert to BST : ");
                scanf("%d", &item);
                find(&par, &pos, item);
                if (pos)
                    printf("element already exists in BST\n");
                else {
                    // Passed NULL for removed 'pos' argument
                    insert(par, item); 
                    printf("%d element added to tree\n", item);
                }
                break;

            case 2:
                if (root == NULL) {
                    printf("TREE is empty\n");
                    break;
                }
                printf("enter element you wanna search : ");
                scanf("%d", &item);
                find(&par, &pos, item);
                if (pos)
                    printf("Element %d found in BST.\n", pos->data);
                else
                    printf("element does not exist\n");
                break;

            case 3:
                if (root == NULL) {
                    printf("TREE is empty\n");
                    break;
                }
                printf("enter a for preorder traversal\n");
                printf("enter b for inorder traversal\n");
                printf("enter c for postorder traversal\n\n");
                scanf(" %c", &ch); // Space to consume newline
                ptr = root;
                switch (ch) {
                    case 'a':
                        printf("Elements of BST in preorder traversal are : ");
                        preorder(ptr);
                        printf("\n");
                        break;
                    case 'b':
                        printf("Elements of BST in inorder traversal are : ");
                        inorder(ptr);
                        printf("\n");
                        break;
                    case 'c':
                        printf("Elements of BST in postorder traversal are : ");
                        postorder(ptr);
                        printf("\n");
                        break;
                    default:
                        printf("*****INVALID CHOICE*****\n");
                        break;
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("TREE is empty\n");
                    break;
                }
                printf("enter element you wanna delete: ");
                scanf("%d", &item);
                find(&par, &pos, item);
                if (pos)
                    del(&par, &pos);
                else
                    printf("element is not present in tree\n");
                break;

            case 5:
                printf("Exiting program...\n");
                // Note: In a production program, you would free all tree nodes here.
                exit(0);

            default:
                printf("*****INVALID CHOICE*****\n");
                break;
        }
    }
    return 0;
}

/*------------------------ Core Functions ------------------------*/

void find(tree **par, tree **loc, int item) {
    tree *ptr, *parptr;

    if (root == NULL) {
        *par = *loc = NULL;
        return;
    }

    if (root->data == item) {
        *loc = root;
        *par = NULL;
        return;
    }

    parptr = root;
    if (item < root->data)
        ptr = root->lchild;
    else
        ptr = root->rchild;

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

    *loc = NULL;
    *par = parptr;
}

// Updated function signature: removed unused 'pos' parameter
void insert(tree *par, int item) {
    tree *p = (tree *)malloc(sizeof(tree));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    p->data = item;
    p->lchild = p->rchild = NULL;

    if (root == NULL) {
        root = p;
    } else if (item < par->data) {
        par->lchild = p;
    } else {
        par->rchild = p;
    }
}

/*------------------------ Traversal ------------------------*/

void preorder(tree *ptr) {
    if (ptr == NULL) return;
    printf(" %d", ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(tree *ptr) {
    if (ptr == NULL) return;
    inorder(ptr->lchild);
    printf(" %d", ptr->data);
    inorder(ptr->rchild);
}

void postorder(tree *ptr) {
    if (ptr == NULL) return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf(" %d", ptr->data);
}

/*------------------------ Deletion ------------------------*/

void del(tree **par, tree **pos) {
    tree *parNode = *par;
    tree *locNode = *pos;
    int deleted_item = locNode->data;

    // Case 2 (Two Children) must be checked last, as it internally handles memory
    if (locNode->lchild != NULL && locNode->rchild != NULL) {
        remove2(parNode, locNode);
        printf("Element %d deleted successfully (Case 2)\n", deleted_item);
        // NO FREE HERE: remove2 frees the successor node's memory
    } 
    // Case 0 (Leaf Node)
    else if (locNode->lchild == NULL && locNode->rchild == NULL) {
        remove0(parNode, locNode);
        printf("Element %d deleted successfully (Case 0)\n", deleted_item);
        free(locNode); // Free the memory for the node
    } 
    // Case 1 (One Child)
    else { 
        remove1(parNode, locNode);
        printf("Element %d deleted successfully (Case 1)\n", deleted_item);
        free(locNode); // Free the memory for the node
    }
}

void remove0(tree *par, tree *pos) {
    // Deleting the root with 0 children
    if (par == NULL)
        root = NULL;
    // Deleting a non-root leaf node
    else if (par->lchild == pos)
        par->lchild = NULL;
    else
        par->rchild = NULL;
}

void remove1(tree *par, tree *pos) {
    tree *child;
    if (pos->lchild != NULL)
        child = pos->lchild;
    else
        child = pos->rchild;

    // Deleting the root with 1 child
    if (par == NULL)
        root = child;
    // Deleting a non-root node with 1 child
    else if (par->lchild == pos)
        par->lchild = child;
    else
        par->rchild = child;
}

void remove2(tree *pos, tree *loc) { // Renamed par to pos and pos to loc for clarity in this function
    tree *parsuc, *suc;
    parsuc = loc; // Parent of successor starts at the node being deleted
    suc = loc->rchild; // Successor starts at the right child

    // Find the inorder successor (leftmost node in the right subtree)
    while (suc->lchild != NULL) {
        parsuc = suc;
        suc = suc->lchild;
    }

    // 1. Copy the successor's data to the location of the node being deleted
    loc->data = suc->data;

    // 2. The successor node 'suc' is now the node to be physically removed.
    // The successor is guaranteed to have at most one right child (Case 0 or Case 1).
    if (suc->rchild == NULL) { // Successor is a leaf node (Case 0)
        remove0(parsuc, suc);
    } else { // Successor has one right child (Case 1)
        remove1(parsuc, suc);
    }
    
    // The successor is freed in del/remove2. We return to del to free 'suc' if we need to.
    // Since this is a recursive-like call, we must free 'suc' here.
    free(suc);
}