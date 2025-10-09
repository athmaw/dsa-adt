#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BITS (8 * sizeof(unsigned char))

void initList(unsigned char *set) {
    *set = 0;
}

void insert(unsigned char *set, int elem) {
    if(elem < 0 || elem >= MAX_BITS) return;

    *set |= (1 << elem);
}

void delete(unsigned char *set, int elem) {
    if(elem < 0 || elem >= MAX_BITS) return;

    *set &= (1 << elem);
}

bool find(unsigned char set, int elem) {
    if(elem < 0 || elem >= MAX_BITS) return false;

    return (set & (1 << elem) != 0);
}

unsigned char set_union(unsigned char A, unsigned char B) {
    return A | B;
}  

unsigned char intersection(unsigned char A, unsigned char B) {
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B) {
    return A & ~B;
}

void display(unsigned char set) {
    printf("{");
    int i, first = 1;

    for(i = 0; i < MAX_BITS; i++) {
        if(set & (1 << i)) {
            if(!first)
                printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("}\n");
}

int main() {
    unsigned char A, B, C;
    initList(&A);
    initList(&B);

    insert(&A, 1);
    insert(&A, 6);
    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 7);

    printf("A = ");
    display(A);
    printf("B = ");
    display(B);

    C = set_union(A, B);
    printf("Union: ");
    display(C);

    C = intersection(A, B);
    printf("Intersection: ");
    display(C);

    C = difference(A, B);
    printf("Difference: ");
    display(C);

    delete(&A, 6);
    printf("A after delete(6): ");
    display(A);

    return 0;
}