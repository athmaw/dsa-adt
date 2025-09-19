#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* rear;
    Node* front;
} Queue;

Queue* initList();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int val);
int dequeue(Queue* q);
int frontVal(Queue* q);
void display(Queue* q);

int main() {
    Queue* q = initList();

    enqueue(q, 1);
    enqueue(q, 3);
    enqueue(q, 5);
    display(q);

    return 0;
}

Queue* initList() {
    Queue* q = (Queue*)malloc(sizeof(Queue));

    q->rear = NULL;
    q->front = NULL;

    return q;
}

bool isFull(Queue* q) {
    return false;
}

bool isEmpty(Queue* q) {
    return q->rear == NULL;
}

void enqueue(Queue* q, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    newNode->data = val;
    newNode->next = q->rear;

    if(isEmpty(q)) {
        q->rear = newNode;
        q->front = newNode;
    } else{
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {

    if(isEmpty(q)) {
        printf("Queue Empty. Can't Dequeue.\n");
        return -1;
    }

    Node* temp = q->front;
    int val = temp->data;

    if(q->rear == q->front) {
        q->rear = NULL;
        q->front = NULL;
    } else{
        Node* trav = q->rear;

        while(trav->next != q->front) {
            trav = trav->next;
        }

        trav->next = NULL;
        q->front = trav;
    }

    free(temp);
    return val;
}

int frontVal(Queue* q) {
    
    if(isEmpty(q)) {
        printf("Queue Empty.\n");
        return -1;
    }

    return q->front->data;
}
void display(Queue* q) {

    if(isEmpty(q)) {
        printf("Queue Empty!\n");
        return;
    }

    Node* temp = q->rear;
    printf("items: [ ");

    while(temp != NULL) {
        printf("%d", temp->data);

        if(temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf(" ]\n");
}