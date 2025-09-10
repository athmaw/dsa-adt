#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int top;
} Stack;

Stack S;

Stack* initList();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int val);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack* s);
void display(Stack* s);

int main() {
    Stack* S = initList();

    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 5);
    display(S);

    int val = pop(S);
    printf("popped: %d\n", val);
    display(S);

    return 0;
}

Stack* initList() {
    Stack* s = (Stack*)malloc(sizeof(Stack));

    if(s == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    s->top = -1;
    return s;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int val) {
    if(isFull(s)) {
        printf("Stack Overflow! Unable to Push.\n");
        return;
    }
    s->top++;
    s->items[s->top] = val;
}

int pop(Stack* s) {
    
    if(isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop\n");
        return -1;
    }

    int val = s->items[s->top];
    s->top--;

    return val;
}

int peek(Stack* s) {

    if(isEmpty(s)) {
        printf("Nothing to Pop.\n");
        return -1;
    }

    return s->items[s->top];
}

int top(Stack* s) {

    return s->top;
}

void display(Stack* s) {

    if(isEmpty(s)) {
        printf("Stack is Empty!\n");
        return;
    }

    int i;
    printf("items: [ ");
    for(i = 0; i <= s->top; i++) {
        printf("%d", s->items[i]);
        if(i < s->top) printf(", ");
    }

    printf(" ]\n");
    printf("top: %d\n\n", s->top);
}