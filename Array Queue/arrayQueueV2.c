#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue Q;

Queue* initList();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int val);
int dequeue(Queue* q);
int frontVal(Queue* q);
void display(Queue* q);

int main() {
    Queue* q = initList();

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    display(q);

    printf("\nDequeued: %d\n", dequeue(q));
    display(q);
    
    return 0;
}

Queue* initList() {
    Queue* q = (Queue*)malloc(sizeof(Queue));

    if(q == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    q->front = 1;
    q->rear = 0;

    return q;
}

bool isEmpty(Queue* q) {
    return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue* q) {
    return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue* q, int val) {

    if(isFull(q)) {
        printf("Queue Full. Can't enqueue.\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = val;
}

int dequeue(Queue* q) {

    if(isEmpty(q)) {
        printf("Queue Empty. Can't dequeue.\n");
        return -1;
    }
    
    int val = q->items[q->front];
    q->front = (q->front + 1) % MAX;

    return val;
}

int frontVal(Queue* q) {

    if(isEmpty(q)) {
        printf("Queue Empty.\n");
        return -1;
    }

    return q->items[q->front];
}

void display(Queue* q) {

    if(isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    int i = q->front;
    printf("items: [");

    while(i != q->rear) {
        printf("%d, ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d", q->items[q->rear]);
    printf("]");
}