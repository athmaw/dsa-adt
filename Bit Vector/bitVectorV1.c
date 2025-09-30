#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void initList(unsigned char *set);
void insert(unsigned char *set, int elem);
void delete(unsigned char *set, int elem);
bool find(unsigned char set, int elem);
unsigned char set_union(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);

int main() {
    unsigned char A;
    initList(&A);

    return 0;
}

void initList(unsigned char *set) {
    *set = 0;
}

void insert(unsigned char *set, int elem) {
    
}

void delete(unsigned char *set, int elem) {

}

bool find(unsigned char set, int elem) {

}

unsigned char set_union(unsigned char A, unsigned char B) {

}  

unsigned char intersection(unsigned char A, unsigned char B) {

}

unsigned char difference(unsigned char A, unsigned char B) {

}

void display(unsigned char set) {

}