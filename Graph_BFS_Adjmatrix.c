#include <stdio.h>
#define SIZE 9

int queue[SIZE], adj[SIZE][SIZE], visited[SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if(rear == SIZE-1)
        return;
    if(front == -1)
        front++;
    rear++;
    queue[rear] = data;
    //printf("%d enqueued\n", data);
}

int isempty()
{
    if(rear == -1)
        return 1;
    return 0;
}

int dequeue()
{
    int data;
    if(isempty())
        return -1;
    data = queue[front++];
    if(front>rear)
        front = rear = -1;
    return data;
}

void display()
{
    printf("\nQueue: ");
    printf("f%d r%d q", front, rear);
    for(int i = front; i<=rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void addEdge(int src, int des)
{
    adj[src][des] = 1;
}

int convert_ch(char ch);
char convert_int(int n);

void bfs(int v, int n)
{
    visited[v-1] = 1;
    printf("%c ", convert_int(v));
    enqueue(v);
    int curr;
    while(!isempty())
    {
        curr = dequeue();
        //display();
        //printf("%c ", convert_ch(curr));
        for(int i = 1; i<=n; i++)
        {
            if(adj[curr][i] == 1 && visited[i-1] == 0)
            {
                visited[i-1] = 1;
                enqueue(i);
                printf("%c ", convert_int(i));
            }
        }
        if(isempty() == 1)
            break;
    }
}

int convert_ch(char ch)
{
    return ch + 1 - 'A';
}

char convert_int(int n)
{
    return n + 'A' - 1;
}

void initiliseAdj(int n)
{
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            adj[i][j] = 0;
        }
    }
}

int main()
{
    int n = 8;

    initiliseAdj(n);

    addEdge(convert_ch('D'), convert_ch('C'));
    addEdge(convert_ch('D'), convert_ch('F'));
    addEdge(convert_ch('D'), convert_ch('E'));
    addEdge(convert_ch('F'), convert_ch('C'));
    addEdge(convert_ch('E'), convert_ch('G'));
    addEdge(convert_ch('G'), convert_ch('D'));
    addEdge(convert_ch('G'), convert_ch('H'));
    addEdge(convert_ch('H'), convert_ch('B'));
    addEdge(convert_ch('A'), convert_ch('B'));
    addEdge(convert_ch('H'), convert_ch('A'));
    
    bfs(convert_ch('D'), 8);

    return 0;
}
