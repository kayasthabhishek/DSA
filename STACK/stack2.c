#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct {
    int TOS;
    int data[MAX_SIZE];
} Stack;

void init(Stack* ps);
void push(Stack* ps, int item);
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
    int value;
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. isEmpty\n");
        printf("4. isFull\n");
        printf("5. Peek TOS\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                isEmpty(&s) ? printf("Stack is empty.\n") : printf("Stack is not empty.\n");
                break;
            case 4:
                isFull(&s) ? printf("Stack is full.\n") : printf("Stack is not full.\n");
                break;
            case 5:
                value = peek(&s);
                if (value != -1)
                    printf("Top of Stack: %d\n", value);
                break;
            case 6:
                display(&s);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n(Press Enter)");
        getchar();
        getchar();
        system("clear");

    } while (choice != 7);

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

void push(Stack* ps, int obj)
{
    if (ps->TOS == MAX_SIZE-1) {
        printf("Stack Overflow. '%d' not pushed!\n", obj);
        return;
    }
    ps->data[++(ps->TOS)] = obj;
}

int pop(Stack* ps)
{
    if (ps->TOS == -1) {
        printf("%s", "Underflow on pop\n");
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
        printf("-> %d ", ps->data[i]);
    }
}
