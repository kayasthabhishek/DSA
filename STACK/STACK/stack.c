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
        printf("\n--- STACK MENU ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. ISEMPTY\n");
        printf("4. ISFULL\n");
        printf("5. PEEK TOS\n");
        printf("6. DISPLAY\n");
        printf("7. EXIT\n");
        printf("ENTER CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ENTER VALUE TO PUSH: ");
                if (scanf("%d", &value) == 1) {
                    push(&s, value);
                } else {
                    printf("INVALID INPUT. PLEASE ENTER AN INTEGER.\n");
                    while(getchar() != '\n');
                }
                break;
            case 2:
                value = pop(&s);
                if (value != -1)
                    printf("POPPED VALUE: %d\n", value);
                break;
            case 3:
                isEmpty(&s) ? printf("STACK IS EMPTY.\n") : printf("STACK IS NOT EMPTY.\n");
                break;
            case 4:
                isFull(&s) ? printf("STACK IS FULL.\n") : printf("STACK IS NOT FULL.\n");
                break;
            case 5:
                value = peek(&s);
                if (value != -1)
                    printf("TOP OF STACK: %d\n", value);
                break;
            case 6:
                display(&s);
                break;
            case 7:
                printf("EXITING PROGRAM.\n");
                break;
            default:
                printf("INVALID CHOICE. PLEASE TRY AGAIN.\n");
        }
        printf("\n(PRESS ENTER TO CONTINUE)");
        getchar(); getchar();
        if (system("clear") != 0) {
            system("cls"); 
        }

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
        printf("STACK OVERFLOW. '%d' NOT PUSHED!\n", obj);
        return;
    }
    ps->data[++(ps->TOS)] = obj;
}

int pop(Stack* ps)
{
    if (ps->TOS == -1) {
        printf("%s", "UNDERFLOW ON POP\n");
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
        printf(" -> %d ", ps->data[i]);
    }
}
