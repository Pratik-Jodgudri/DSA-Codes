#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

struct Stack
{
    int *arr;
    int top;
    int capacity;
};

struct Stack* createStack(int x)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = x;
    stack->top = -1;
    stack->arr = (int*)malloc(x*sizeof(int));
    return stack;
}

int isFull(struct Stack *stack)
{
    return (stack->top == (stack->capacity-1));
}

int isEmpty(struct Stack *stack)
{
    return (stack->top == (-1));
}

void push(struct Stack *stack, int x)
{
    if(!isFull(stack))
    {
        stack->arr[++stack->top] = x;
    }
}

int peek(struct Stack* stack)
{
    return stack->arr[stack->top];
}

int pop(struct Stack *stack)
{
    if(!isEmpty(stack))    
    {
        return stack->arr[stack->top--];
    }
    return '$';
}

int evaluate(char* exp)
{ 
    struct Stack *stack = createStack(strlen(exp));
    
    for(int i=0; exp[i]; i++)
    {
        if(exp[i] == ' ') 
            continue;
        else if (isdigit(exp[i]))
            push(stack, exp[i] - '0'); // to change acsii into int
        else
        {
            int num1 = pop(stack);
            int num2 = pop(stack);
            
            switch(exp[i])
            {
                case '+':
                    push(stack, num1+num2);
                    break;
                
                case '-':
                    push(stack, num2-num1);
                    break;
                
                case '*':
                    push(stack, num2*num1);
                    break;
                
                case '/':
                    push(stack, num2/num1);
                    break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    char input[SIZE];
    scanf("%[^\n]s", input);
    
    printf("%d", evaluate(input));
    return 0;
}