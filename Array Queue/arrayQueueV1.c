#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int count;
} List;

typedef struct{
    List list;
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
    Queue* Q = initList();

    display(Q);
    return 0;
}

Queue* initList() {
    Queue* q = (Queue*)malloc(sizeof(Queue));

    if(q == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    q->list.count = 0;
    q->front = -1;
    q->rear = -1;
    
    return q;
}

bool isFull(Queue* q) {
    return q->list.count == MAX;
}

bool isEmpty(Queue* q) {
    return q->list.count == 0;
}

void enqueue(Queue* q, int val) {

    if(isFull(q)) {
        printf("Queue Full. Can't enqueue.\n");
        return;
    }

    if(isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else{
        q->rear = (q->rear + 1) % MAX;
    }

    q->list.items[q->rear] = val;
    q->list.count++;
}

int dequeue(Queue* q) {

    if(isEmpty(q)) {
        printf("Queue Empty. Can't dequeue.\n");
        return -1;
    }

    int val = q->list.items[q->front];

    if(q->list.count == 1) {
        q->front = -1;
        q->rear = -1;
    } else{
        q->front = (q->front + 1) % MAX;
    }

    q->list.count--;
    return val;
}

int front(Queue* q) {

    if(isEmpty(q)) {
        printf("Queue Empty.\n");
        return -1;
    }

    return q->list.items[q->front];
}

void display(Queue* q) {

    if(isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    int i = q->front;
    int x;

    printf("items: [ ");
    for(x = 0; x < q->list.count; x++) {
        printf("%d ", q->list.items[i]);
        i = (i + 1) % MAX;
    }
    printf("]");
}