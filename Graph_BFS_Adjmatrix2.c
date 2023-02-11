#include <stdio.h>
#define SIZE 20

int queue[SIZE], adj[SIZE][SIZE], visited[SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if(rear == SIZE-1)
        return;
    if(front == 0)
        front++;
    rear++;
    queue[rear] = data;
    //printf("Entered %d at %d\n", data, rear);
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
    return queue[front++];
}

void display()
{
    printf("\nQueue: ");
    for(int i = front; i<= rear; i++)
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
    //display();
    //int curr = dequeue();
    visited[v-1] = 1;
    printf("%c ", convert_int(v));
    enqueue(v);
    int curr;
    //display();
    while(1)
    {
        curr = dequeue();
        //printf("%d ", curr);
        for(int i = 1; i<=n; i++)
        {
            if(adj[curr][i] == 1 && visited[i-1] == 0)
            {
                visited[i-1] = 1;
                enqueue(i);
                printf("%c ", convert_int(i));
                //display();
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

int main()
{
    int n = 8;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            adj[i][j] = 0;
        }
    }

    int edges;
    char src, des;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    fflush(stdin);

    for(int i = 0; i<edges; i++)
    {
        printf("Enter src des: ");
        scanf("%c %c", &src, &des);
        fflush(stdin);
        // scanf("%c", &des);
        // fflush(stdin);
        //printf("%d->%d ", convert_ch(src), convert_ch(des));
        addEdge(convert_ch(src), convert_ch(des));
    }

    // for(int i = 1; i<=n; i++)
    // {
    //     for(int j = 1; j<=n; j++)
    //     {
    //         printf("%d", adj[i][j]);
    //     }
    //     printf("\n");
    // }

    bfs(4, 8);

    return 0;
}
