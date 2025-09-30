#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    unsigned int field : 8;
} Set;

void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
Set set_union(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void display(unsigned char set);

int main() {

    return 0;
}

void initialize(Set *set) {
    set->field = 0;
}

void insert(Set *set, int element) {
    
    
}

void delete(Set *set, int element) {
    
}

bool find(Set set, int element) {

}

Set set_union(Set A, Set B) {

}

Set intersection(Set A, Set B) {

}

Set difference(Set A, Set B) {

}

void display(unsigned char set) {

}