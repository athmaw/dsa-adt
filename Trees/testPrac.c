#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *LC; //left child
    struct node *RC; //right child
} Node, *BST;

void insert(BST *B, int val) {
    BST *trav = B;

    while(*trav != NULL && (*trav)->data != val) {
        trav = val > (*trav)->data ? &(*trav)->RC : &(*trav)->LC; 
    }

    if(*trav == NULL) {
        *trav = (BST)calloc(1, sizeof(Node));
        (*trav)->data = val;
    }
}

void inorder(BST B) { //left - root - right

    if(B != NULL) {
        inorder(B->LC);
        printf("%d ", B->data);
        inorder(B->RC);
    }
}

void preorder(BST B) { //root - left - right

    if(B != NULL) {
        printf("%d ", B->data);
        preorder(B->LC);
        preorder(B->RC);
    }
}

void postorder(BST B) { //left - right - root

    if(B != NULL) {
        postorder(B->LC);
        postorder(B->RC);
        printf("%d ", B->data);
    }
}

int main() {
    BST B = NULL;

    insert(&B, 0);
    insert(&B, 3);
    insert(&B, 4);
    insert(&B, 6);
    insert(&B, 2);
    insert(&B, 1);
    insert(&B, 7);
    insert(&B, 8);

    printf("Inorder: ");
    inorder(B);
    printf("\n");

    printf("Preorder: ");
    preorder(B);
    printf("\n");

    printf("Postorder: ");
    postorder(B);
    printf("\n");

    return 0;
}