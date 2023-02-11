#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct Stack
{
    char *arr;
    int top;
    int capacity;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (char *)malloc(capacity * sizeof(char));
    return stack;
}

void push(struct Stack *stack, char data)
{
    if (stack->top != ((stack->capacity) - 1))
    {
        stack->top++;
        stack->arr[stack->top] = data;
    }
    else if (stack->top == ((stack->capacity) - 1))
    {
        printf("Stack Overflow!\n");
    }
}

void pop(struct Stack *stack)
{
    if (stack->top != -1)
    {
        // char data = stack->arr[stack->top];
        stack->top--;
        // return data;
    }
}

void display(struct Stack *stack)
{
    printf("The elements in the stack are ");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
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
    return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'));
}

int evaluate(int num1, int num2, char op)
{
    if (op == '+')
    {
        return (num1 + num2);
    }
    else if (op == '-')
    {
        return (num1 - num2);
    }
    else if (op == '*')
    {
        return (num1 * num2);
    }
    else if (op == '/')
    {
        return (num1 / num2);
    }
}

void evaluate_postfix(struct Stack *operator_stack, struct Stack *operand_stack, char postfix[], int length)
{
    int num1, num2, x;
    char op;
    for (int i = 0; i < length; i++)
    {
        printf("%c\n", postfix[i]);
        if (isOperand(postfix[i]))
        {
            printf("Pushed %c", postfix[i]);
            push(operand_stack, postfix[i]);
        }
        else if (postfix[i] == '(')
        {
            printf("Pushed %c", postfix[i]);
            push(operator_stack, postfix[i]);
        }
        else if (postfix[i] == ')')
        {
            while (operator_stack->top != -1 || operator_stack->top == '(')
            {
                num2 = (int)operand_stack->arr[operand_stack->top];
                pop(operand_stack);
                num1 = (int)operand_stack->arr[operand_stack->top];
                pop(operand_stack);
                op = operator_stack->arr[operator_stack->top];
                printf("Poped %d", operator_stack->arr[operator_stack->top]);
                pop(operator_stack);
                push(operand_stack, evaluate(num1, num2, op));
            }
            printf("Poped %d", operator_stack->arr[operator_stack->top]);
            pop(operator_stack);
        }
        else
        {
            while (operator_stack->top != -1 && precedence(operator_stack->arr[operator_stack->top] >= precedence(postfix[i])))
            {
                num2 = (int)operand_stack->arr[operand_stack->top];
                pop(operand_stack);
                num1 = (int)operand_stack->arr[operand_stack->top];
                pop(operand_stack);
                op = operator_stack->arr[operator_stack->top];
                printf("Poped %d", operator_stack->arr[operator_stack->top]);
                pop(operator_stack);
                push(operand_stack, evaluate(num1, num2, op));
            }
            push(operator_stack, postfix[i]);
            printf("Pushed %c", postfix[i]);
        }
    }

    while (operator_stack->top != -1)
    {
        num2 = (int)operand_stack->arr[operand_stack->top];
        pop(operand_stack);
        num1 = (int)operand_stack->arr[operand_stack->top];
        pop(operand_stack);
        op = operator_stack->arr[operator_stack->top];
        pop(operator_stack);
        push(operand_stack, evaluate(num1, num2, op));
    }

    if (operator_stack->top == -1 && operand_stack->top == 0)
    {
        printf("Final answer: %d", operand_stack->arr[operand_stack->top]);
    }
}

int main()
{
    char exp[SIZE];
    char postfix[SIZE];
    scanf("%[^\n]s", exp);
    int capacity = 0;
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] != ' ')
        {
            postfix[capacity++] = exp[i];
        }
    }

    struct Stack *operator_stack = createStack(capacity);
    struct Stack *operand_stack = createStack(capacity);

    evaluate_postfix(operator_stack, operand_stack, postfix, capacity);

    return 0;
}