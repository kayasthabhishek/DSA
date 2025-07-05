#include "DLL.h"

// Avoid multiple definition for these global variables
Node* head = NULL;  // Global: Good for single list, 
Node* tail = NULL;
Node* temp = NULL;

Node* create_node(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int getlen()
{
    int count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_at_beg(int value)
{
    Node *newNode = create_node(value);

    if (head == NULL)
        head = tail = newNode;
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d WAS SUCCESSFULLY INSERTED AT THE FRONT\n", head->data);
}

void insert_at_end(int value)
{
    Node *newNode = create_node(value);

    if (head == NULL)
        head = tail = newNode;
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        // newNode->next = NULL; // Not necessary, as it is already initialized to NULL
        tail = newNode;
    }
    printf("%d WAS SUCCESSFULLY INSERTED AT THE END\n", tail->data);
}

void insert_at_pos(int value, int pos)
{
    if (pos < 1)
    {
        printf("INVALID POSITION\n");
        return;
    }
    if (pos == 1 || head == NULL)
    {
        insert_at_beg(value);
        return;
    }

    Node *newNode = create_node(value);
    temp = head;
    int i;
    for (i = 1; i < pos - 1; ++i) {
        if (temp == NULL) {
            printf("POSITION OUT OF BOUNDS\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }


    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
    else
        tail = newNode;  // If inserted at the end, update tail

    printf("%d WAS SUCCESSFULLY INSERTED AT POSITION %d\n", value, pos);
}

void delete_node_from_beg()
{
    if (head == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = tail = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
    }
    printf("NODE SUCCESSFULLY DELETED FROM FRONT\n");
    free(temp);
}


void delete_node_from_end()
{
    if (head == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = tail = NULL;
    }
    else
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("NODE SUCCESSFULLY DELETED FROM END\n");
    free(temp);
}

void delete_node_from_pos(int pos)
{
    if (head == NULL) {
        printf("LIST IS EMPTY. NOTHING TO DELETE.\n");
        return;
    }

    if (pos < 1) {
        printf("INVALID POSITION\n");
        return;
    }
    
    if (pos == 1) {
        delete_node_from_beg();
        return;
    }

    temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; ++i) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("POSITION OUT OF BOUNDS (NO NODE AT POSITION %d)\n", pos);
        return;
    }
    
    Node* target = temp->next;

    temp->next = target->next;
    if (target->next)
        target->next->prev = temp;
    else
        tail = temp;

    printf("NODE WITH VALUE %d DELETED FROM POSITION %d\n", target->data, pos);
    free(target);
}

void linear_search(int key)
{
    int flag = 0;
    if (head == NULL)
        printf("LIST IS EMPTY\n");
    
    else
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                printf("FOUND %d\n", key);
                printf("POSITION: ");
                int pos = 1;
                Node *ptr = head;
                while (ptr != temp) {
                    pos++;
                    ptr = ptr->next;
                }
                printf("%d\n", pos);
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 0)
            printf("SEARCH UNSUCCESSFUL (%d NOT FOUND)\n", key);
    }
}

void display()
{
    temp = head;
    if (temp == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    printf("LIST CONTENTS: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display_reversed()
{
    temp = tail;
    if (head == NULL) {
        printf("LIST IS EMPTY\n");
        return;
    }
    printf("REVERSED LIST CONTENTS: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void release_memory() {
    Node* i = head;
    
    printf("RELEASING MEMORY...\n");
    while (i != NULL) {
        printf("DELETING: %d\n", i->data);
        temp = i;
        i = i->next;
        free(temp);
    }

    head = tail = NULL;
    printf("LIST SUCCESSFULLY FREED.\n");
}
