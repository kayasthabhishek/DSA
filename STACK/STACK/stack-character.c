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
        printf("\n--- SINGLE CHARACTER STACK ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK TOS\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("ENTER CHARACTER TO PUSH: ");
                scanf(" %c", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                printf("POPPED CHARACTER: %c\n", value);
                break;
            case 3:
                value = peek(&s);
                if (value != -1)
                    printf("TOP OF STACK: %c\n", value);
                break;
            case 4:
                display(&s);
                break;
                case 5:
                printf("Exiting program.\n");
                break;
                default:
                printf("INVALID CHOICE.\n");
        }
        printf("\n(PRESS ENTER TO CONTINUE)");
        getchar(); getchar();
        if (system("clear") != 0) {
            system("cls");
        }

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
        printf("STACK OVERFLOW. '%c' NOT PUSHED!\n", obj);
        return;
    }

    ps->data[++(ps->TOS)] = obj;
}

int pop(Stack* ps)
{
    if (ps->TOS == -1) {
        printf("%s", "STACK UNDERFLOW ON POP\n");
        return -1;
    }
    
    return ps->data[ps->TOS--];
}

int peek(Stack* ps)
{
    if (ps->TOS == -1) {
        printf("%s", "STACK EMPTY\n");
        return -1;
    }
    else
        return ps->data[ps->TOS];
}

void display(Stack* ps) {
    if (ps->TOS == -1) {
        printf("STACK EMPTY.\n");
        return;
    }

    printf("STACK ELEMENTS:\n");
    for (int i = ps->TOS; i >= 0; i--) {
        printf("-> %c ", ps->data[i]);
    }
}
