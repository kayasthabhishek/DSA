#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct SLL {
    Node* head;
    Node* tail;
} SLL;

// methods
Node* createNode(int data);
void insertAtBeg(SLL* list, int data);
void insertAtEnd(SLL* list, int data);
void insertAtPos(SLL* list, int data, int pos);
void deleteAtBeg(SLL* list);
void deleteAtEnd(SLL* list);
void deleteAtPos(SLL* list, int pos);
void display(const SLL* list);
void search(const SLL* list, int data);
void release(SLL* list);

#endif