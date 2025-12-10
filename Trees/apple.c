#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct apple{
    char name[20];
    char color[10];
    int hardness;       // 1 to 10 scale
    int size_cm;
    bool ripe;
} Apple;

typedef struct node{
    Apple *app;         // pointer to apple
    struct node *LC;    // left child
    struct node *RC;    // right child
} Node, *BST;           // node is the structure, BST is pointer to node

typedef struct box{
    Apple apples[50];   // array of apple sturctures
    int count;          // number of apples in the box
    int capacity;       // maximum capacity of the box
} Box;

void initBox(Box *box, int capacity);
BST createNode(Apple *a);
BST insertBST(BST root, Apple *a);
BST deleteNode(BST root, const char *key);
BST makeAppleTree(Apple apples[], int n);
void inorderTRaversal(BST root);
void preorderTraversal(BST root);
BST harvestRecursive(BST root, Box *box);
BST harvestRotten(BST root, Box *box);

int main() {
    Apple apples[5] = {
        {"Fuji", "Red", 7, 8, true},
        {"Granny Smith", "Green", 6, 7, false},
        {"Gala", "Yellow", 5, 6, true},
        {"Honeycrisp", "Red", 8, 9, true},
        {"Golden Delicious", "Yellow", 4, 7, false}
    };

    BST appleTree = makeAppleTree(apples, 5);

    printf("Inorder Traversal:\n");
    inorderTRaversal(appleTree);
    printf("\n");

    printf("Preorder Traversal:\n");
    preorderTraversal(appleTree);
    printf("\n");

    Box box;
    initBox(&box, 10);

    appleTree = harvestRecursive(appleTree, &box);
    printf("Harvested %d ripe apples.\n", box.count);

    appleTree = harvestRotten(appleTree, &box);
    printf("Harvested %d rotten apples.\n", box.count);

    return 0;
}

void initBox(Box *box, int capacity) {
    box->count = 0;
    box->capacity = capacity;
}

BST createNode(Apple *a) {
    BST newNode = (BST)malloc(sizeof(Node));
    newNode->app = a;
    newNode->LC = NULL;
    newNode->RC = NULL;

    return newNode;
}

BST insertBST(BST root, Apple *a) {

    if(root = NULL) {
        printf("Tree is empty.\n");
        return createNode(a);
    }

    if(strcmp(a->name, root->app->name) < 0) {
        root->LC = insertBST(root->LC, a);
    } else if(strcmp(a->name, root->app->name) > 0) {
        root->LC = insertBST(root->RC, a);
    } else{
        printf("Apple with name %s already exists.\n", a->name);
    }

    return root;
}

BST deleteNode(BST root, const char *key) {
    
    if(root = NULL) {
        return NULL;
    }

    if(strcmp(key, root->app->name) < 0) {
        root->LC = deleteNode(root->LC, key);
    } else if(strcmp(key, root->app->name) > 0) {
        root->RC = deleteNode(root->RC, key);
    } else{
        
    }
}

BST makeAppleTree(Apple apples[], int n) {
    BST root = NULL;
    int i;

    for(i = 0; i < n; i++) {
        insertBST(root, &apples[i]);
    }

    return root;
}

void inorderTraversal(BST root) {

    if(root != NULL) {
        inorderTraversal(root->LC);
        printf("Apple Name: %s, Color: %s, Hardness: %d, Size: %d cm, Ripe: %s\n",
               root->app->name, root->app->color, root->app->hardness,
               root->app->size_cm, root->app->ripe ? "Yes" : "No");
        inorderTraversal(root->RC);
    }
}

void preorderTraversal(BST root) {

    if(root != NULL) {
        printf("Apple Name: %s, Color: %s, Hardness: %d, Size: %d cm, Ripe: %s\n",
               root->app->name, root->app->color, root->app->hardness,
               root->app->size_cm, root->app->ripe ? "Yes" : "No");
        preorderTraversal(root->LC);
        preorderTraversal(root->RC);
    }
}

BST harvestRecursive(BST root, Box *box) {

}

BST harvestRotten(BST root, Box *box) {

}