#include <stdio.h>

struct Queue
{
    int *arr;
    int front, rear, capacity, size;
};

struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    queue->arr = (int *)malloc(capacity * sizeof(int));
    return queue;
};

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int x)
{
    if (isFull(queue))
        printf("Queue is Full!");
    else if (isEmpty(queue))
    {
        queue->front = queue->rear = 0;
        queue->arr[queue->rear] = x;
        queue->size++;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->arr[queue->rear] = x;
        queue->size++;
    }
    printf("%d enqueued to queue\n", x);
}

void dequeue(struct Queue *queue)
{
    int x;
    if(isEmpty(queue))
        printf("Queue is Empty!\n");
    else
    {
        x = queue->front;
        queue->front = (queue->front+1) % queue->capacity;
        queue->size--;
        printf("%d was dequeued.\n", x);
    }
}

void Front(struct Queue *queue)
{
    if(isEmpty(queue))
        printf("Queue is Empty!\n");
    printf("%d\n", queue->arr[queue->front]);
}

void Rear(struct Queue *queue)
{
    if(isEmpty(queue))
        printf("Queue is Empty!");
    printf("%d\n", queue->arr[queue->rear]);
}   

int main()
{
    int size;
    printf("Enter the size of queue");
    scanf("%d", &size);

    struct Queue *queue = createQueue(size);

    int n;
    printf("Enter your choice\n 1.Enqueue \n 2.Dequeue \n 3.isFull \n 4.isEmpty \n 5.Front \n 6.Rear\n");
    scanf("%d", &n);
    if(n == 1)
    {
        int x;
        printf("Enter the Element to insert into the queue: ");
        scanf("%d", &x);
        Enqueue(queue);
    }
    return 0;
}