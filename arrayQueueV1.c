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

void display(Queue* q) {

    if(isEmpty(q)) {
        printf("Stack is Empty!\n");
        return;
    }

    int i;
    printf("items: [ ");
}