#include <stdio.h>
#include <stdlib.h>
//#define SIZE 40

struct Queue
{
    int arr[40];
    int front, rear; 
};

struct Queue* createQueue();
void enqueue(struct Queue *head, int data);
int dequeue(struct Queue *head);
int isempty(struct Queue *head);
//void display(struct Queue *head);
void printQueue(struct Queue* head);

struct Node 
{
    int vertex;
    struct Node *next;
};

struct Node *createNode(int data);

struct Graph 
{
    int numVertices;
    struct Node** adjLists;
    int *visited;
};

void bfs(struct Graph* graph, int startVertex)
{
    struct Queue *q = createQueue();
    
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while(!isempty(q))
    {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while(temp)
        {
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] == 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

struct Node* createNode(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = data;
    temp->next = NULL;
    return temp;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for(int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int des)
{
    struct Node *newNode = createNode(des);
    //edge src to des
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // struct Node *temp = graph->adjLists[src];
    // while(temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = newNode;

    //edge des to src
    // newNode = createNode(src);
    // newNode->next = graph->adjLists[des];
    // graph->adjLists[des] = newNode;
}

struct Queue* createQueue()
{
    struct Queue *temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->front = -1;
    temp->rear = -1;
    return temp;
}

int isempty(struct Queue *head)
{
    return (head->rear == -1);
}

void enqueue(struct Queue *head, int data)
{
    if(head->rear == 40 - 1)
        printf("Overflow!\n");
    else
    {
        if(head->front == -1)
            head->front = 0;
        head->rear++;
        head->arr[head->rear] = data;
    }
}

int dequeue(struct Queue *head)
{
    int data;
    if(!isempty(head))
    {
        data = head->arr[head->front];
        head->front++;
        if(head->front > head->rear)
        {
            //printf("Resetting Queue\n");
            head->front = head->rear = -1;
        }
    }
    return data;
}

void printQueue(struct Queue *head)
{
    if(isempty(head))
    {
        printf("Queue is Empty\n");
    }
    else 
    {
        printf("Queue: ");
        for(int i = head->front; i <= head->rear; i++)
        {
            printf("%d ", head->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Graph* graph = createGraph(8);
    addEdge(graph, 4, 3);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 3);
    addEdge(graph, 7, 4);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 1);
    addEdge(graph, 8, 2);
    addEdge(graph, 1, 2);

    bfs(graph, 4);
    return 0;
}