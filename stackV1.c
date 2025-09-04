#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int top;
} Stack;

Stack S;

Stack* initList();
void push(Stack* s, int val);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main() {
    Stack s;
    initList(s);

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

void push(Stack* s, int val) {
    
}

void display(Stack* s) {

}