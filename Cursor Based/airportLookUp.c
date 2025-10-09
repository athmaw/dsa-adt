#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20
#define PRIMARY_SIZE 10
#define CODE_LEN 4

typedef struct{
    char elem[CODE_LEN];
    int next;
} Node;

Node heap[SIZE];
int avail = PRIMARY_SIZE;

int hash(char code[]) {
    return ((code[0] - 'A') * 26 * 26 + code[1] - 'A' * 26 + 
    (code[2] - 'A')) % PRIMARY_SIZE;
}

void initHeap() {
    int i;

    for(i = 0; i < SIZE; i++) {
        strcpy(heap[i].elem, "");
        heap[i].next = -1;
    }

    for(i = PRIMARY_SIZE; i < SIZE - 1; i++) {
        heap[i].next = i + 1;
    }
    heap[SIZE - 1].next = -1;
}

int getAvail() {
    
    if(avail == -1) return -1;
    int temp = avail;
    avail = heap[avail].next;

    return temp;
}

void insert(char code[]) {
    int Ndx = hash(code);

    if(strcmp(heap[Ndx].elem, "") == 0) {
        strcmp(heap[Ndx].elem, code);
        heap[Ndx].next = -1;
    } else{
        int newNdx = getAvail();

        if(newNdx == -1) {
            printf("Heap Overflow!\n");
            return;
        }
        int curr = Ndx;

        while(heap[curr].next != -1) curr = heap[curr].next;
        heap[curr].next = newNdx;
        strcpy(heap[newNdx].elem, code);
        heap[newNdx].next = -1;
    }
}

void printHeap() {
    printf("Index | Elem | Next\n");
    printf("---------------------\n");
    int i;

    for(i = 0; i < SIZE; i++) {
        printf("  %2d  | %-4s |  %2d\n", i, heap[i].elem, heap[i].next);
    }
    printf("Available: %2d\n", avail);
}

void printHash(char *codes[], int n) {
    printf("\nHash Indices:\n");
    int i;

    for(i = 0; i < n; i++) {
        printf("%s -> %d\n", codes[i], hash(codes[i]));
    }
}

int main() {
    initHeap();

    char *codes[] = {"JFK", "LAX", "SFO", "CDG", "LHR", "NRT",
                     "ATL", "DXB", "PEK", "MIA", "SYD", "ORD"};
    
    int numOfElem = sizeof(codes) / sizeof(codes[0]);
    int i;

    for(i = 0; i < numOfElem; i++) {
        insert(codes[i]);
    }

    printHeap();
    printHash(codes, numOfElem);

    return 0;
}