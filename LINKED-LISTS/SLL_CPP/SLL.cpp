#include "SLL.hpp"

using namespace std;

SLL::SLL() : head(nullptr), tail(nullptr)
{
    cout << "SINGLY LINKED LIST IMPLEMENTATION" << endl;
    cout << "SLL CREATED SUCCESSFULLY." << endl;
}

Node* SLL::createNode(int data)
{
    Node* newNode = new Node(data);
    if (!newNode) {
        cerr << "MEMORY ALLOCATION FAILED!" << endl;
        exit(EXIT_FAILURE);
    }
    return newNode;
}

void SLL::insertAtBeg(int data)
{
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    cout << "INSERTED " << data << " SUCCESSFULLY AT BEGINNING" << endl;
}

void SLL::insertAtEnd(int data)
{
    Node* newNode = createNode(data);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    cout << "INSERTED " << data << " SUCCESSFULLY AT END" << endl;
}

void SLL::insertAtPos(int data, int pos)
{
    if (pos < 1) {
        cerr << "INVALID POSITION!" << endl;
        return;
    }
    if (pos == 1 || head == nullptr) {
        insertAtBeg(data);
        return;
    }
    
    Node* newNode = createNode(data);
    Node* current = head;
    for (int i = 1; i < pos - 1; ++i) {
        if (current == nullptr) {
            cerr << "POSITION OUT OF BOUNDS!" << endl;
            delete newNode;
            return;
        }
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    if (newNode->next == nullptr) {
        tail = newNode; // Update tail if inserted at the end
    }
    cout << "INSERTED " << data << " SUCCESSFULLY AT POSITION " << pos << endl;
}

void SLL::deleteAtBeg()
{
    if (head == nullptr) {
        cout << "LIST IS EMPTY, NOTHING TO DELETE" << endl;
        return;
    }

    Node* temp = head;
    if (head == tail) {
        // delete head; // you will lose access to the rest of the list
        head = tail = nullptr;
        cout << "DELETED " << temp->data << " SUCCESSFULLY FROM BEGINNING" << endl;
    }
    else {
        head = head->next;
        cout << "DELETED " << temp->data << " SUCCESSFULLY FROM BEGINNING" << endl;
    }
    
    delete temp;
}

void SLL::deleteAtEnd()
{
    if (tail == nullptr) {
        cout << "LIST IS EMPTY, NOTHING TO DELETE" << endl;
        return;
    }

    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        while (temp->next != tail) {
            temp = temp->next;
        }
        
        tail = temp;
        temp = tail->next;
    }
    cout << "DELETED " << temp->data << " SUCCESSFULLY FROM END" << endl;
    delete temp;
    tail->next = nullptr;
}

void SLL::deleteAtPos(int pos)
{
    if (pos < 1) {
        cerr << "INVALID POSITION!" << endl;
        return;
    }
    else if (head == nullptr) {
        cout << "LIST IS EMPTY, NOTHING TO DELETE" << endl;
        return;
    }
    else if (pos == 1) {
        deleteAtBeg();
    }

    Node* current = head;
    for (int i = 1; i < pos - 1; ++i) {
        if (current == nullptr) {
            cerr << "POSITION OUT OF BOUNDS!" << endl;
            return;
        }
        current = current->next;
    }
    if (current->next == nullptr) {
        deleteAtEnd();
    }
    else {
        Node* temp = current->next;  // Node to be deleted
        current->next = temp->next;  // Bypass the node to be deleted
        cout << "DELETED " << temp->data << " SUCCESSFULLY FROM POSITION " << pos << endl;
        delete temp;
    }
}

void SLL::display() const
{
    if (head == nullptr) {
        cout << "LIST IS EMPTY" << endl;
        return;
    }

    Node* current = head;
    cout << "LIST CONTENTS: ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
    cout << "HEAD: " << to_string(head->data) << ", TAIL: " << to_string(tail->data) << endl;
}

void SLL::search(int key) const
{
    if (head == nullptr) {
        cout << "LIST IS EMPTY, NOTHING TO SEARCH" << endl;
        return;
    }

    Node* current = head;
    int pos = 1;
    while (current != nullptr) {
        if (current->data == key) {
            cout << "FOUND " << key << " AT POSITION " << pos << endl;
            return;
        }
        current = current->next;
        pos++;
    }
    cout << key << " NOT FOUND IN THE LIST" << endl;
}

SLL::~SLL()
{
    Node* temp;
    Node* i = head;
    cout << "RELEASING MEMORY..." << endl;
    while (i != nullptr) {
        cout << "RELEASE: " << i->data << endl;
        temp = i;
        i = i->next;
        delete temp;
    }
    head = tail = nullptr;
    cout << "LIST MEMORY RELEASED SUCCESSFULLY" << endl;
}