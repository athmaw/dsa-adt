#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct{
    int* elemPtr;
    int count;
    int max;
} List;

void initList(List* L);
void insertPos(List*L, int data, int pos);
void deletePos(List* L, int pos);
int locate(List *L, int data);
int retrieve(List* L, int pos);
void insertSorted(List* L, int data);
void display(List* L);
void resize(List* L);
void makeNULL(List* L);

int main() {
    List* L;
    initList(L);

    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 5, 2);
    insertPos(&L, 10, 3);
    display(&L);

    makeNULL(&L);
    return 0;
}

void initList(List* L) {
    L->elemPtr = (int*)malloc(LENGTH * sizeof(int));

    if(L->elemPtr == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    L->max = LENGTH;
    L->count = 0;
    return L;
}

void insertPos(List*L, int data, int pos) {

    if(pos > L->count || pos < 0) {
        printf("Invalid.\n");
        return L;
    }

    if(L->count == L->max) {
        resize(L);
    }

    int i;
    for(i = L->count; i > pos; i--) {
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    L->elemPtr[pos] = data;
    L->count++;
    return L;
}

void deletePos(List* L, int pos) {

    if(pos > L->count || pos < 0) {
        printf("Invalid.\n");

        return L;
    }

    int i;
    for(i = pos; i < L->count; i++) {
        L->elemPtr[i] = L->elemPtr[i + 1];
    }

    L->count--;
    return L;
}

int locate(List *L, int data) {
    int i;

    for(i = 0; i < L->count; i++) {
        if(L->elemPtr[i] == data) {
            return i;
        }
    }

    return -1;
}

int retrieve(List* L, int pos) {

    if(pos < L->count) {
        return L->elemPtr[pos];
    }

    printf("Invalid.\n");
    return -1;
}

void insertSorted(List* L, int data) {

    if(L->count == L->max) {
        resize(L);
    }

    int pos = 0;
    while(pos < L->count && L->elemPtr[pos] < data) {
        pos++;
    }

    int i;
    for(i = L->count; i > pos; i--) {
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    L->elemPtr[pos] = data;
    L->count++;
    return L;
}

void display(List* L) {
    int i;

    printf("elem: ");
    for(i = 0; i < L->count; i++) {
        printf("%d ", L->elemPtr[i]);
    }

    printf("\ncount: %d, max: %d\n", L->count, L->max);
}

void resize(List* L) {
    int newMax = L->max * 2;
    int newArr = (int*)realloc(L->elemPtr, newMax * sizeof(int));

    if(newArr == NULL) {
        printf("Invalid.\n");
        exit(1);
    }

    L->elemPtr = newArr;
    L->max = newMax;
    return L;
}

void makeNULL(List* L) {
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}