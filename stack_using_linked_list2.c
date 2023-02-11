#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node *head = NULL;

struct Node* createNode(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void push()
{
    int data; 
    scanf("%d", &data);
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

int isEmpty()
{
    return !head;
}

int pop()
{
    if (!isEmpty())
    {
        struct Node *temp = head;
        int data = temp->data;
        head = temp->next;
        free(temp);
        return data;
    }
}

void display()
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    free(temp);
}

int main()
{
    int choice;
    
    do
    {
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            push();
        }
        else if(choice == 2)
        {
            printf("The element deleted is %d\n", pop());
        }
        else if(choice == 3)
        {
            printf("The elements in the stack are ");
            display();
        }
    }
    while(choice != 4);
    
    return 0;
}