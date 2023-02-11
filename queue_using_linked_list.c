#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Queue
{
    struct Node *front, *rear;
};

struct Queue *createQueue()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enQueue(struct Queue* queue)
{
    int data;
    scanf("%d", &data);
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int deQueue(struct Queue *queue)
{
    int data;
    if(queue->front != NULL)
    {
        struct Node *temp = queue->front;
        queue->front = temp->next;
        data = temp->data;
        if(queue->front == NULL)
        {
            queue->rear = NULL;
        }
        free(temp);
    }
    
    return data;
}

void display(struct Queue *queue)
{
    struct Node *temp = queue->front;
    
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
    struct Queue *queue = createQueue();
    
    int choice;
    
    do
    {
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            enQueue(queue);
        }
        else if(choice == 2)
        {
            printf("The element deleted is %d\n", deQueue(queue));
        }
        else if(choice == 3)
        {
            printf("The elements in the Queue are ");
            display(queue);
        }
    }
    while(choice != 4);
    
    return 0;
}