#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* rear;
} Queue;

Queue* initList();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int val);
int dequeue(Queue* q);
int frontVal(Queue* q);
void display(Queue* q);

int main()  {
    Queue* q = initList();

    enqueue(q, 1);
    enqueue(q, 3);
    enqueue(q, 5);
    display(q);

    int val = dequeue(q);
    display(q);
    
    return 0;
}

Queue* initList() {
    Queue* q = (Queue*)malloc(sizeof(Queue));

    q->front = NULL;
    q->rear = NULL;

    return q;
}

bool isFull(Queue* q) {
    return false;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;

    if(isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {

    if(isEmpty(q)) {
        printf("Queue Empty. Nothing to Dequeue.\n");
        return -1;
    }
    
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if(q->front == NULL) {
        q->rear = NULL;
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
        printf("Queue Empty! Nothing to Display.\n");
        return;
    }

    Node* trav = q->front;
    printf("[ ");

    while(trav != NULL) {
        printf("%d", trav->data);

        if(trav->next != NULL) printf(" -> ");
        trav = trav->next;
    }
    printf(" ]\n");
}