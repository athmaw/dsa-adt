#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 4

typedef struct{
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initList(VHeap* V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int Ndx);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertPos(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main() {

    return 0;
}

void initList(VHeap* V) {
    int i;

    for(i = 0; i < MAX - 1; i++) {
        V->H[i].next = i + 1;
    }

    V->H[MAX - 1].next = -1;
    V->avail = 0;
}

int allocSpace(VHeap* V) {

}

void deallocSpace(VHeap* V, int Ndx) {

}

void insertFirst(int* L, VHeap* V, int elem) {

}

void insertLast(int* L, VHeap* V, int elem) {

}

void insertPos(int* L, VHeap* V, int elem) {

}

void insertSorted(int* L, VHeap* V, int elem) {

}

void delete(int* L, VHeap* V, int elem) {

}

void deleteAllOccurrence(int* L, VHeap* V, int elem) {

}

void display(int L, VHeap V) {

}