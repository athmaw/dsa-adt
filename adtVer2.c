#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

EPtr L;

void initList(EPtr L);
void insertPos(EPtr L, int data, int pos);
void deletePos(EPtr L, int pos);
int locate(EPtr L, int data);
int retrieve(EPtr L, int pos);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main() {
    EPtr L = (EPtr)malloc(sizeof(Etype));
    initList(L);

    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 5, 2);
    insertPos(L, 10, 3);
    display(L);

    insertSorted(L, 8);
    display(L);

    makeNULL(L);

    return 0;
}

void initList(EPtr L) {
    L->count = 0;
}

void insertPos(EPtr L, int data, int pos) {
    int i;

    if(pos <= L->count && L->count < MAX) {
        for(i = L->count; i > pos; i--) {
            L->elem[i] = L->elem[i - 1];
        }

        L->elem[pos] = data;
        L->count++;
    } else{
        printf("Invalid.\n");
    }
}

void deletePos(EPtr L, int pos) {
    int i;

    if(pos < L->count) {
        for(i = pos; i < L->count - 1; i++) {
            L->elem[i] = L->elem[i + 1];
        }

        L->count--;
    } else{
        printf("Invalid.\n");
    }
}

int locate(EPtr L, int data) {
    int i;

    for(i = 0; i < L->count; i++) {
        if(L->elem[i] == data) {
            return i;
        }
    }

    return -1;
}

int retrieve(EPtr L, int pos) {

    if(pos < L->count) {
        return L->elem[pos];
    }

    printf("Invalid.\n");
    return -1;
}

void insertSorted(EPtr L, int data) {

    if(L->count == MAX) {
        printf("Insert failed: list is full.\n");
        return;
    }

    int pos = 0;
    while(pos < L->count && L->elem[pos] < data) {
        pos++;
    }
    
    int i;
    for(i = L->count; i > pos; i--) {
        L->elem[i] = L->elem[i - 1];
    }

    L->elem[pos] = data;
    L->count++;
}

void display(EPtr L) {
    int i;

    printf("elem: ");
    for(i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(EPtr L) {
    free(L);
}
