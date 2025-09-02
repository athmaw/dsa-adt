#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct{
    Node *head;
    int count;
} List;

List* initList();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int Ndx);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int Ndx);
int retrieve(List *list, int Ndx);
int locate(List *list, int data);
void display(List *list);

int main() {
    List *list = initList();

    insertFirst(list, 5);
    insertFirst(list, 6);
    insertFirst(list, 2);
    display(list);

    insertLast(list, 7);
    display(list);

    insertPos(list, 7, 2);
    display(list);

    return 0;
}

List* initList() {
    List *list = (List*)malloc(sizeof(List));

    if(list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->count = 0;

    return list;
}

void empty(List *list) {
    Node *curr = list->head;
    Node *temp;

    while(!curr != NULL) {
        temp = curr;
        curr = curr->next;

        free(temp);
    }

    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) return;

    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL) return;

    newNode->data = data;
    newNode->next = NULL;

    if(list->head == NULL) {
        list->head == newNode;
    } else{
        Node *curr = list->head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    list->count++;
}

void insertPos(List *list, int data, int Ndx) {
    
    if(Ndx > list->count || Ndx < 0) {
        printf("Invalid.\n");
    }

    if(Ndx == 0) {
        insertFirst(list, data);
    } else if(Ndx == list->count) {
        insertLast(list, data);
    } else{
        Node *newNode = (Node*)malloc(sizeof(Node));

        if(newNode == NULL) return;

        newNode->data = data;

        Node* curr = list->head;
        int i;

        for(i = 0; i < Ndx; i++) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
        list->count++;
    }
}

void display(List *list) {
    Node *curr = list->head;

    printf("head: ");
    while(curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }

    printf("NULL\ncount: %d\n", list->count);
}