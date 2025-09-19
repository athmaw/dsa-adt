#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* top;
} Stack;

Stack* initList();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int val);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main() {
    Stack* s = initList();

    push(s, 5);
    push(s, 3);
    push(s, 1);
    display(s);

    int val = pop(s);
    display(s);

    return 0;
}

Stack* initList() {
    Stack* s = (Stack*)malloc(sizeof(Stack));

    if(s == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    s->top = NULL;
    return s;
}

bool isFull(Stack* s) {
    return false;
}

bool isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) {
        printf("Memory Allocation Failed.\n");
        return;
    }

    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {

    if(isEmpty(s)) {
        printf("Stack Empty. Nothing to Pop.\n");
        return -1;
    }

    Node* temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);

    return val;
}

int peek(Stack* s) {

    if(isEmpty(s)) {
        printf("Stack Empty.\n");
        return -1;
    }

    return s->top->data;
}

void display(Stack* s) {

    if(isEmpty(s)) {
        printf("Stack Empty! Nothing to Display.\n");
        return;
    }
    
    Node* trav = s->top;
    int i;
    printf("items: [ ");

    while(trav != NULL) {
        printf("%d", trav->data);

        if(trav->next != NULL) printf(" -> ");
        trav = trav->next;
    }

    printf(" ]\n");
}