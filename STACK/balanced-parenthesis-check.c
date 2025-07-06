#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Stack
{
    int TOS;
    char data[MAX_SIZE];
}Stack;

void push(Stack* ps, char obj);
int pop(Stack* ps);
int isMatchingPair(char open, char close);
int isBalanced(const char* expr);


int main()
{
    char expr[MAX_SIZE];
    printf("%s", "Enter an expression: ");
	
	if (fgets(expr, MAX_SIZE, stdin) == NULL) {
		fprintf(stderr, "Error reading input.\n");
		exit(1);
	}
    
	(isBalanced(expr)? printf("---Balanced\n"): printf("---Not Balanced\n"));
    
    return 0;
}


int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(const char* expr)
{
    Stack s = {.TOS = -1};

    int i = 0;
    while (expr[i] != '\0')
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') 
            push(&s, expr[i]);
        
        else if(expr[i] == ')' || expr[i] == ']' || expr[i] == '}') 
        {
            if (s.TOS == -1) return 0;
            
            if (!isMatchingPair(pop(&s), expr[i])) return 0;
        }
        i++;
    }
    return (s.TOS == -1);
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
