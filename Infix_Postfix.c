#include <stdio.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top=-1;

void push(char x)
{
    if(top < SIZE)    
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if(top > -1)
    {
        top--;
    }
}

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
    else if(ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

int isOperand(char x)
{
    return ((x>= 'a' && x<= 'z') || (x >= 'A' && x <= 'Z') || (x>= '0' && x <= '9'));
}

void infix_to_postfix(char infix[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if(isOperand(infix[i]))
        {
            printf("%c ", infix[i]);
        }
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(stack[top] != '(')
            {
                printf("%c ", stack[top]);
                pop();
            }
            pop();
        }
        else
        {
            while(top > -1 && (precedence(stack[top]) >= precedence(infix[i])) && stack[top] != '(')
            {
                printf("%c ", stack[top]);
                pop();
            }
            push(infix[i]);
        }
    }
    while(top > -1)
    {
        printf("%c ", stack[top]);
        pop();
    }
}

int main()
{
    char infix[SIZE];
    scanf("%s", infix);
    int length = strlen(infix);
    
    infix_to_postfix(infix, length);
}