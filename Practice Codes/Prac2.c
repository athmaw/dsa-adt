#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

//given the data type definition of a set
//implemented using computer word char: 

typedef unsigned char SET;

void initSet(SET *s);
void displaySet(SET s);
void insert(SET *s, int element);
int member(SET s, int element);
void delete(SET *s, int element);
SET union_set(SET s1, SET s2);
SET intersection(SET s1, SET s2);
SET difference(SET s1, SET s2);

int main() {
    SET set1, set2;

    initSet(&set1);
    initSet(&set2);
    displaySet(set1);
    
    insert(&set1, 0);
    insert(&set1, 2);
    insert(&set1, 5);
    printf("Set1 after inserts: ");
    displaySet(set1);
    
    insert(&set2, 2);
    insert(&set2, 3);
    insert(&set2, 5);
    printf("Set2 after inserts: ");
    displaySet(set2);
    
    printf("Union: ");
    displaySet(union_set(set1, set2));
    
    printf("Intersection: ");
    displaySet(intersection(set1, set2));
    
    printf("Difference (set1 - set2): ");
    displaySet(difference(set1, set2));
    
    return 0;
}

void initSet(SET *s) {
    *s = 0;
}

void displaySet(SET s) {
    int i;

    printf("{ ");
    for(i = 0; i < 8; i++) {
        if(s & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

void insert(SET *s, int elem) {

    if(elem >= 0 && elem < 8) {
        *s = *s | (1 << elem);
    }
}

int member(SET s, int elem) {

    if(elem >= 0 && elem < 8) {
        return (s & (1 << elem)) != 0;
    }
    return 0;
}

void delete(SET *s, int elem) {

    if(elem >= 0 && elem < 8) {
        *s = *s & ~(1 << elem);
    }
}

SET union_set(SET s1, SET s2) {
    return (s1 | s2);
}

SET intersection(SET s1, SET s2) {
    return (s1 & s2);
}

SET difference(SET s1, SET s2) {
    return (s1 & ~s2);
}