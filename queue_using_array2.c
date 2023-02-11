#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *arr;
    int front, rear, capacity, size;
};

struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    queue->arr = (int*)malloc(capacity*sizeof(int));
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

void enqueue(struct Queue* queue)
{
    int data;
    scanf("%d", &data);
    if(!isFull(queue))
    {
        if(isEmpty(queue))
        {
            queue->front = queue->rear = 0;
        }
        else
        {
            queue->rear++;
        }
        queue->size++;
        queue->arr[queue->rear] = data;   
    }
}

int dequeue(struct Queue *queue)
{
    int data;
    if(!isEmpty(queue))
    {
        data = queue->arr[queue->front];
        queue->front++;
        queue->size--;
    }
    return data;
}

void display(struct Queue* queue)
{
    int temp = queue->front;
    while(temp != queue->rear+1)
    {
        printf("%d ", queue->arr[temp]);
        temp++;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Queue *queue = createQueue(n);
    printf("Size of the Queue is %d\n", n);
    
    int choice; 
    
    do
    {
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            enqueue(queue);
        }
        else if(choice == 2)
        {
            printf("The element deleted is %d\n", dequeue(queue));
        }
        else if(choice == 3)
        {
            printf("The elements in the queue are ");
            display(queue);
        }
    }
    while(choice != 4);
    
    return 0;
}