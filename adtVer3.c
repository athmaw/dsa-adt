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


void display(List L) {
    int i;

    printf("elem: ");
    for(i = 0; i < L.count; i++) {
        printf("%d ", L.elemPtr[i]);
    }

    printf("\ncount: %d, max: %d\n", L.count, L.max);
}