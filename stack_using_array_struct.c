#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *arr;
    int top;
    int capacity;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack= (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (int*)malloc(capacity*sizeof(int));
    return stack;
}

void push(struct Stack* stack, int data)
{
    if(stack->top != ((stack->capacity)-1))
    {
        stack->top++;
        stack->arr[stack->top] = data;
    }
    else if(stack->top == ((stack->capacity)-1))
    {
        printf("Stack Overflow!\n");
    }
}

void pop(struct Stack* stack)
{
    if(stack->top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        int data = stack->arr[stack->top];
        stack->top--;
        printf("The element deleted is %d\n", data);
    }
}

void display(struct Stack *stack)
{
    printf("The elements in the stack are ");
    for(int i=stack->top; i>=0; i--)
    {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("Size of the stack is %d\n", n);
    struct Stack* stack = createStack(n);
    
    int choice, data;
    do
    {
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            scanf("%d", &data);
            push(stack, data);
        }
        else if(choice == 2)
        {
            pop(stack);
        }
        else if(choice == 3)
        {
            display(stack);
        }
    }
    while(choice != 4);
    
    return 0;
}