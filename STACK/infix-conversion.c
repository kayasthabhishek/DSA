#include <stdio.h>
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
char* infix_to_prefix(char[]);

int main()
{
    char infix[MAXSIZE];
    printf("EXPRESSION SHOULD BE WELL PARENTHESIZED AND NO WHITESPACES\nENTER AN INFIX: ");
    scanf("%s", infix);
    printf("INFIX: %s\n\n", infix);

    printf("POSTFIX: %s\n", infix_to_postfix(infix));
    printf("PREFIX: %s\n", infix_to_prefix(infix));
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
        case '-': return 3;
        default: return 0;  // ) or (
    }
}

char* infix_to_postfix(char infix[])
{
    struct Stack stack = {.TOS = -1};
    static char postfix[MAXSIZE], ch;
    int j = 0;

    for(int i = 0; (ch = infix[i])!='\0'; i++)
    {
        if(ch == '(')
            push(&stack, ch);

        else if(isalnum(ch))
            postfix[j++] = ch;

        else if (isOperator(ch))
        {
            while (!(stack.TOS == -1) && precedence(ch) <= precedence(stack.data[stack.TOS]))
                postfix[j++] = pop(&stack);
            push(&stack, ch);
        }

        // else if(precedence(ch) > precedence(stack.TOS) )
        // {
        //     push(&stack,ch);
        // }
        // else if(precedence(ch) < precedence(stack.TOS))
        // {
        //     while(!(precedence(ch) > precedence(stack.TOS)))
        //          output[j++] =pop(&stack);
        //     push(&stack,ch);
            
        // }

        else if(ch == ')')
        {
            while(!(stack.TOS == -1) && stack.data[stack.TOS] != '(' )
                postfix[j++] = pop(&stack);
            pop(&stack);
        }
    }
    while(!(stack.TOS == -1))
    {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
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

char* infix_to_prefix(char infix[])
{
    struct Stack stack = {.TOS = -1};
    char* postfix;
    static char prefix[MAXSIZE];
    int len = 0;

    // Reverse the infix expression
    for (len = 0; infix[len] != '\0'; len++);
    for (int i = 0; i < len / 2; i++) {
        char temp = infix[i];
        infix[i] = infix[len - i - 1];
        infix[len - i - 1] = temp;
    }

    // Reverse the parentheses
    for (int i = 0; i < len; i++) {
        if (infix[i] == '(') 
            infix[i] = ')';
        else if (infix[i] == ')') 
            infix[i] = '(';
    }

    postfix = infix_to_postfix(infix);

    // copy
    len = 0;
    while (postfix[len] != '\0') {
        prefix[len] = postfix[len];
        len++;
    }
    prefix[len] = '\0';
    
    // Reverse to get prefix
    for (int j = 0; j < len / 2; j++)
    {
        char temp = prefix[j];
        prefix[j] = prefix[len - j - 1];
        prefix[len - j - 1] = temp;
    }

    return prefix;
}
