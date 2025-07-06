#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 50

struct Stack
{
    int TOS;
    char data[MAXSIZE];
};

void push(struct Stack* ps, char item);
char pop(struct Stack* ps);
int precedence(char ch);
int isOperator(char);
char* infix_to_postfix(char[]);
void debug_stack(struct Stack* ps, char* postfix);

void display(struct Stack* ps) {
    if (ps->TOS == -1) {
        printf("STACK EMPTY.\n");
        return;
    }

    printf("STACK ELEMENTS:\n");
    for (int i = ps->TOS; i >= 0; i--) {
        printf("->%c ", ps->data[i]);
    }
}

int main()
{
    char infix[MAXSIZE];
    printf("(ENTER AN INFIX (WELL PARENTHESIZED AND WELL SPACED e.g. ( 2 + 3 ) * 5)\nINFIX: ");
    fgets(infix, MAXSIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    printf("\nINFIX: %s\n", infix);
    printf("POSTFIX: %s\n", infix_to_postfix(infix));
    // printf("Prefix: %s\n", infix_to_prefix(infix));
    return 0;
}

int precedence(char ch)
{
    switch (ch) 
    {
        case '^': return 5;
        case '*':
        case '/': return 4;
        case '+': 
        case '-': return 2;
        default: return 0;
    }
}

char* infix_to_postfix(char infix[])
{
    struct Stack stack = {.TOS = -1};
    static char postfix[MAXSIZE*2];
    postfix[0] = '\0';

    char* token = strtok(infix, " ");
    while (token != NULL) {
           
        if(token[0] == '(')
            push(&stack, token[0]);

        else if(atoi(token) || isalpha(token[0]))
        {
            strcat(postfix, token);
            strcat(postfix, " ");
        }
        
        
        else if ((isOperator(token[0])))
        {
            while (!(stack.TOS == -1) && (precedence(token[0]) <= precedence(stack.data[stack.TOS])))
            {
                char temp[2] = {pop(&stack), '\0'};
                strcat(postfix, temp);
                strcat(postfix, " ");
            }
            // printf("token : %c\n",token[0]);
            push(&stack, token[0]);
        }

        else if(token[0] == ')' && token[1] == '\0')
        {
            while (!(stack.TOS == -1) && stack.data[stack.TOS] != '(')
            {
                char temp[2] = {pop(&stack), '\0'};
                strcat(postfix, temp);
                strcat(postfix, " ");
            }
            pop(&stack);
        }
        else {
            printf("INVALID CHARACTER '%s' IN EXPRESSION!\n", token);
            return NULL;
        }
        debug_stack(&stack, postfix);
        token = strtok(NULL, " ");
    }
    while(!(stack.TOS == -1))
    {
        if (stack.data[stack.TOS] == '(') 
        {
            printf("MISMATCHED PARENTHESES IN EXPRESSION!\n");
            return NULL;
        }
        char temp[2] = {pop(&stack), '\0'};
        strcat(postfix, temp);
        strcat(postfix, " ");
    }

    return postfix;
}

int isOperator(char ch)
{
    return (ch == '+' || 
            ch == '-' ||
            ch == '/' ||
            ch == '*' ||
            ch == '^');
}

void push(struct Stack* ps, char item)
{
    if (ps->TOS == MAXSIZE - 1) 
    {
        printf("STACK OVERFLOW. '%c' NOT PUSHED!\n", item);
        return;
    }
    ps->data[++(ps->TOS)] = item;
}

char pop(struct Stack* ps)
{
    if (ps->TOS == -1) 
    {
        printf("STACK UNDERFLOW ON POP!\n");
        return '\0';
    }
    return ps->data[ps->TOS--];
}

void debug_stack(struct Stack* ps, char* postfix)
{
    printf("[STACK] ");
    for (int i = 0; i <= ps->TOS; ++i)
        printf("%c ", ps->data[i]);
    printf("\n");
    printf("[POSTFIX] %s\n\n", postfix);
}
