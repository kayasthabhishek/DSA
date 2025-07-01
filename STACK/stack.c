#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int TOS;
    char data[MAX_SIZE];
} Stack;

void init(Stack* ps);
void push(Stack* ps, char item);
int pop(Stack* ps);
int peek(Stack* ps);
int isEmpty(Stack* ps);
int isFull(Stack* ps);
void display(Stack* ps);


int main()
{
    Stack s;
    init(&s);
    
    int choice;
    char value;
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek TOS\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf(" %c", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                printf("Popped value: %c\n", value);
                break;
            case 3:
                value = peek(&s);
                if (value != -1)
                    printf("Top of Stack: %c\n", value);
                break;
            case 4:
                display(&s);
                break;
                case 5:
                printf("Exiting program.\n");
                break;
                default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n(Press Enter)");
        getchar();
        getchar();
        system("clear");

    } while (choice != 5);

    return 0;
}


void init(Stack* ps) {
    ps->TOS = -1;
}

int isFull(Stack* ps) {
    return ps->TOS == MAX_SIZE-1;
}

int isEmpty(Stack* ps) {
    return ps->TOS == -1;
}

void push(Stack* ps, char obj)
{
    if (ps->TOS == MAX_SIZE-1) {
        printf("Stack Overflow. '%c' not pushed!\n", obj);
        return;
    }

    ps->data[++(ps->TOS)] = obj;
}

int pop(Stack* ps)
{
    if (ps->TOS == -1) {
        printf("%s", "Stack Underflowon p\n");
        return -1;
    }
    
    return ps->data[ps->TOS--];
}

int peek(Stack* ps)
{
    if (ps->TOS == -1) {
        printf("%s", "Stack empty\n");
        return -1;
    }
    else
        return ps->data[ps->TOS];
}

void display(Stack* ps) {
    if (ps->TOS == -1) {
        printf("Stack empty.\n");
        return;
    }

    printf("Stack Elements:\n");
    for (int i = ps->TOS; i >= 0; i--) {
        printf("->%c ", ps->data[i]);
    }
}