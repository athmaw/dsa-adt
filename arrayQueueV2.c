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
int front(Queue* q);
void display(Queue* q);

int main() {
    
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

bool isFull(Queue* q) {
    return q->front == (q->rear + 1) % MAX;
}

bool isEmpty(Queue* q) {
    return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue* q, int val) {

    if(isFull(q)) {
        printf("Queue Full. Can't enqueue.\n");
        return;
    }

    if(isEmpty(q)) {

    }
}

int dequeue(Queue* q) {

}

int front(Queue* q) {

}

void display(Queue* q) {

    if(isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    int i = q->front;
    int x;

    printf("items: [ ");
    for(x = 0; x < q->items[MAX]; x++) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("]");
}