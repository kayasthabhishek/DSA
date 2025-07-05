#ifndef SLL_HPP
#define SLL_HPP

#include <iostream>

struct Node 
{
    int data;
    Node* next;

    Node(int data)  // Constructor
    {
        this->data = data;
        this->next = nullptr;
    }
};

class SLL 
{
private:
    Node* head;
    Node* tail;

public:
    SLL();
    ~SLL();

    Node* createNode(int data);
    void insertAtBeg(int data);
    void insertAtEnd(int data);
    void insertAtPos(int data, int pos);
    void deleteAtBeg();
    void deleteAtEnd();
    void deleteAtPos(int pos);
    void display() const;
    void search(int key) const;
};

#endif