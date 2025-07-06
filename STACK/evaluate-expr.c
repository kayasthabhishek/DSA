#include <stdio.h>
#include <math.h>

#define MAXSIZE 50

struct Stack
{
    int TOS;
    int data[MAXSIZE];
};

void push(struct Stack* ps, int item);
int pop(struct Stack* ps);
int isOperator(char ch);
int eval(int symb, int op1, int op2);
int EvalPostfix(char* expr);
int EvalPrefix(char* expr);


int main()
{
    char expr[20];
    
    printf("ENTER AN INTEGER EXPRESSION TO EVALUATE (POSTFIX / PREFIX): ");
    scanf("%s", expr);
    printf("%s%s\n","ENTERED EXPRESSION: ",expr);

    // printf("RESULT: %d\n", !isOperator(expr[0])? EvalPostfix(expr): EvalPrefix(expr));

    if (isOperator(expr[0])) {
        printf("PREFIX DETECTED.\n");
        printf("RESULT = %d\n", EvalPrefix(expr));
	} else {
        printf("POSTFIX DETECTED.\n");
        printf("RESULT = %d\n", EvalPostfix(expr));
	}
	return 0;
}


void push(struct Stack* ps, int item)
{
    if (ps->TOS == MAXSIZE - 1) 
    {
        printf("STACK OVERFLOW. '%d' NOT PUSHED!\n", item);
        return;
    }
    ps->data[++(ps->TOS)] = item;
}

int pop(struct Stack* ps)
{
    if (ps->TOS == -1) 
    {
        printf("STACK UNDERFLOW ON POP!\n");
        return -1;
    }
    return ps->data[ps->TOS--];
}

int isOperator(char ch)
{
    return (ch == '+' || 
            ch == '-' ||
            ch == '/' ||
            ch == '*' ||
            ch == '^');
}

int eval(int symb, int op1, int op2)
{
    switch (symb)
    {
        case '+': 
        return (op1 + op2);
    
        case '-': 
        return (op1 - op2);
    
        case '*': 
        return (op1 * op2);
    
        case '/': 
        return (op1 / op2);
    
        case '^': 
        return pow(op1, op2);
        break;

        default: 
        printf("ILLEGAL OPERATION");
        return 0;
    }
}

int EvalPostfix(char* expr)
{
    struct Stack s = {.TOS = -1};

    int OP1, OP2, ch;

    for (int i = 0; (ch = expr[i]) != '\0'; i++) {
        if (expr[i] >= '0' && expr[i] <= '9')
            push(&s, expr[i] - '0'); 

        else if (isOperator(expr[i]))
        {
            OP1 = pop(&s);
            OP2 = pop(&s);

            push(&s, eval(ch, OP2, OP1));
        }
        else
        {
            printf("INVALID!");
            return 0;
        }
    }
    return pop(&s);
}

int EvalPrefix(char* expr)
{   
    struct Stack s = {.TOS = -1};

    int OP1, OP2;
    
    char *p = expr;
    while (*p != '\0') p++;
    p--;

    while (p >= expr) {
        if (*p >= '0' && *p <= '9')
            push(&s, *p - '0'); 

        else if (isOperator(*p))
        {
            OP1 = pop(&s);
            OP2 = pop(&s);

            push(&s, eval(*p, OP1, OP2));
        }
        else
        {
            printf("INVALID CHARACTER! '%c'\n", *p);
            return 0;
        }
        p--;
    }
    return pop(&s);
}
