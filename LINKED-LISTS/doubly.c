#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedListNode
{
    int data;
    struct DoublyLinkedListNode* next;
    struct DoublyLinkedListNode* prev;
}DLL;

DLL *first, *last = NULL;
DLL *temp = NULL;

void insert_at_first(int value)
{
    DLL *NewNode;
    NewNode = (DLL*)malloc(sizeof(DLL));
    NewNode->data = value;
    NewNode->prev = NULL;
    NewNode->next = NULL;

    if (first == NULL)
        first = last = NewNode;
    else
    {
        NewNode->next = first;
        first->prev = NewNode;
        first = NewNode;
    }
    printf("%d WAS INSERTED AT THE FRONT\n", first->data);
}

void insert_at_end(int value)
{
    DLL *NewNode;
    NewNode = (DLL*)malloc(sizeof(DLL));
    NewNode->data = value;
    NewNode->prev = NULL;
    NewNode->next = NULL;

    if (first == NULL)
        first = last = NewNode;
    else
    {
        NewNode->prev = last;
        last->next = NewNode;
        last = NewNode;
    }
    printf("%d WAS INSERTED AT THE END\n", last->data);
}

void delete_node_from_first()
{
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        printf("NODE DELETED FROM FRONT\n");
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        first->prev = NULL;
        printf("NODE DELETED FROM FRONT\n");
        free(temp);
    }
}


void delete_node_from_end()
{
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        printf("NODE DELETED FROM END\n");
        free(temp);
    }
    else
    {
        temp = last;
        last = last->prev;
        last->next = NULL;
        printf("NODE DELETED FROM END\n");
        free(temp);
    }
}

void linear_search(int key)
{
    int flag = 0;
    DLL *temp;
    if (first == NULL)
        printf("LIST IS EMPTY\n");
    
    else
    {
        temp = first;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                printf("FOUND %d\n", key);
                printf("POSITION: ");
                int pos = 1;
                DLL *ptr = first;
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
    temp = first;
    if (temp == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display_reversed()
{
    temp = last;
    if (first == NULL)
        printf("LIST IS EMPTY\n");
    
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void release_memory()
{
    DLL* i = first;

    printf("RELEASING MEMORY...\n");
    while (i != NULL)
    {
        printf("DELETING: %d\n", i->data);
        temp = i;
        i = i->next;
        free(temp);
    }

    first = last = NULL;
    printf("MEMORY RELEASED SUCCESSFULLY\n");
}

int main()
{
    first = last = NULL;
    int choice, value;

    insert_at_first(100);
    display();
    display_reversed();
    insert_at_first(200);
    display();
    display_reversed();
    insert_at_end(300);
    display();
    display_reversed(); 
    insert_at_end(400);
    display();
    display_reversed();
    linear_search(400);
    delete_node_from_first();
    display();
    display_reversed();
    delete_node_from_end();
    display();
    display_reversed();
    linear_search(200);

    release_memory();
    return 0;
}
