#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max
} List;

List initList(List L);
List insertPos(List L, int data, int pos);
List deletePos(List L, int pos);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main() {
    List L;
    L = initList(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 5, 2);
    L = insertPos(L, 10, 3);
    display(L);

    return 0;
}

List initList(List L) {
    L.elemPtr = (int*)malloc(LENGTH * sizeof(int));

    if(L.elemPtr == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    L.count = 0;
    L.max = LENGTH;

    return L;
}

List insertPos(List L, int data, int pos) {

    if(pos > L.count || pos < 0) {
        printf("Invalid.\n");

        return L;
    }

    if(L.count == L.max) {
        L = resize(L);
    }

    int i;
    for(i = L.count; i > pos; i--) {
        L.elemPtr[i] = L.elemPtr[i - 1];
    }

    L.elemPtr[pos] = data;
    L.count++;

    return L;
}

List deletePos(List L, int pos) {
    int i;

    if(pos > L.count || pos < 0) {
        printf("Invalid.\n");

        return L;
    }

    for(i = pos; i < L.count - 1; i++) {
        L.elemPtr[i] = L.elemPtr[i + 1];
    }

    L.count--;

    return L;
}

int locate(List L, int data) {
    int i;

    for(i = 0; i < L.count; i++) {
        if(L.elemPtr[i] == data) {
            return i;
        }
    }

    return -1;
}

List insertSorted(List L, int data) {

    if(L.count == L.max) {
        L = resize(L);
    }

    int pos = 0;
    while(pos < L.count && L.elemPtr[pos] < data) {
        pos++;
    }

    int i;

    for(i = L.count; i > pos; i--) {
        L.elemPtr[i] = L.elemPtr[i - 1];
    }

    L.elemPtr[pos] = data;
    L.count++;

    return L;
}

void display(List L) {
    int i;

    printf("elem: ");
    for(i = 0; i < L.count; i++) {
        printf("%d ", L.elemPtr[i]);
    }

    printf("\ncount: %d, max: %d\n", L.count, L.max);
}

List resize(List L) {
    int newMax = L.max * 2;
    int newArr = (int*)realloc(L.elemPtr, newMax * sizeof(int));

    if(newArr == NULL) {
        printf("Invalid.\n");
        exit(1);
    }

    L.elemPtr = newArr;
    L.max = newMax;

    return L;
}