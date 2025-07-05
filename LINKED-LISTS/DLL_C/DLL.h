#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* create_node(int value);
int getlen();
void insert_at_beg(int value);
void insert_at_end(int value);
void insert_at_pos(int value, int pos);
void delete_node_from_beg();
void delete_node_from_end();
void delete_node_from_pos(int pos);
void linear_search(int key);
void display();
void display_reversed();
void release_memory();

#endif