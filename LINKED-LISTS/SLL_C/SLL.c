#include "SLL.h"

Node* createNode(int data)
{
    Node* newNode = malloc(sizeof(Node)); // Heap memory is reserved for one Node object.
    // Node* NewNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL)
    {
        perror("MEMORY ALLOCATION FAILED");
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


void insertAtBeg(SLL* list, int data)
{
    Node* newNode = createNode(data);

    // isEmpty check
    if (list->head == NULL)
        list->head = list->tail = newNode;

    else
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    printf("SUCCESSFULLY INSERTED %d AT THE BEGINNING\n", data);
}


void insertAtEnd(SLL* list, int data)
{
    Node* newNode = createNode(data);

    // isEmpty check
    if (list->head ==NULL)
        list->head = list->tail = newNode;
    
    else
    {
        list->tail->next = newNode;  // Links current last node to the new node
        list->tail = newNode;  // don't lose track of the last node
    }
    printf("SUCCESSFULLY INSERTED %d AT THE END\n", data);
}


void insertAtPos(SLL* list, int data, int pos)
{
    if (pos < 1)
    {
        printf("INVALID POSITION\n");
        return;
    }
    else if (pos == 1 || list->head == NULL)
    {
        insertAtBeg(list, data);
        return;
    }
    else
    {
        Node* newNode = createNode(data);
        Node* current = list->head;
        int i;

        for (i = 1; i < pos - 1; ++i)
        {
            if (current == NULL)
            {
                printf("POSITION OUT OF BOUNDS\n");
                free(newNode);
                return;
            }
            current = current->next;
        }
        // current is now pointing to pos-1 node
        // A -> B -> C
        // new -> C (next of B)
        // B -> new
        // A -> B -> new -> C
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == NULL) // If new node is inserted at the end update tail
            list->tail = newNode;
        printf("SUCCESSFULLY INSERTED %d AT POSITION %d\n", data, pos);
    }
}


void deleteAtBeg(SLL* list)
{
    if (list->head == NULL)
    {
        printf("EMPTY LIST\n");
        return;
    }

    Node* temp = list->head;

    if (list->head == list->tail) // Only one node
        list->head = list->tail = NULL;
    else
        list->head = list->head->next; // Move head to the next node

    printf("SUCCESSFULLY DELETED THE FIRST NODE - %d\n", temp->data);
    free(temp);
}


void deleteAtEnd(SLL* list)
{
    if (list->head == NULL)
    {
        printf("EMPTY LIST\n");
        return;
    }

    Node* temp = list->head;

    if (list->head == list->tail)
        list->head = list->tail = NULL;
    else
    {
        while(temp->next != list->tail)
            temp = temp->next;
        
        // temp is now pointing to the second last node
        list->tail = temp;
        temp = list->tail->next;
    }

    printf("SUCCESSFULLY DELETED THE LAST NODE - %d\n", temp->data);
    free(temp);
    list->tail->next = NULL;
}



void deleteAtPos(SLL* list, int pos)
{
    if (list->head == NULL)
    {
        printf("EMPTY LIST\n");
        return;
    }
    else if (pos < 1)
    {
        printf("INVALID POSITION\n");
        return;
    }
    else if (pos == 1)
    {
        deleteAtBeg(list);
        return;
    }
    else
    {
        Node* current = list->head;
        int i;
        for (i = 1; i < pos - 1; ++i)
        {
            if (current == NULL)
            {
                printf("POSITION OUT OF BOUNDS\n");
                return;
            }
            current = current->next;
        }

        // current is now pointing to pos-1 node
        if (current->next == NULL)
            deleteAtEnd(list);
        
        else
        {
            Node* temp = current->next; // Node to be deleted
            current->next = temp->next; // Bypass the node to be deleted
            printf("SUCCESSFULLY DELETED NODE AT POSITION %d - %d\n", pos, temp->data);
            free(temp);
        }
    }
}


void display(const SLL* list)
{
    if (list->head == NULL)
    {
        printf("EMPTY LIST\n");
        return;
    }

    Node* current = list->head;
    printf("LIST CONTENTS: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("HEAD: %d, TAIL: %d\n", list->head->data, list->tail->data);
}


void search(const SLL* list, int key)
{
    int flag = 0, index = 1;

    if (list->head == NULL)
    {
        printf("EMPTY LIST\n");
        return;
    }

    Node* current = list->head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            printf("ELEMENT %d FOUND AT POSITION %d\n", key, index);
            flag = 1;
            break;
        }
        current = current->next;
        index++;
    }

    if (!flag)
        printf("ELEMENT %d NOT FOUND\n", key);
}


void release(SLL* list)
{
    Node* temp;
    Node* i = list->head;

    while (i != NULL)
    {
        temp = i;
        i = i->next;
        free(temp);
    }

    list->head = list->tail = NULL;
    printf("LIST MEMORY RELEASED SUCCESSFULLY\n");
}

