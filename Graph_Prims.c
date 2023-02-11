#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 8

int minDist(int dist[], bool visited[])
{
    int min_index, min = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int from[], int adj[V][V])
{
    int weight = 0;
    for(int i = 1; i<V; i++)
        weight += adj[i][from[i]];
    printf("Cost of Minimum Spanning Tree = %d\n", weight);
}

void PrimMST(int adj[V][V])
{
    int dist[V];
    bool visited[V];
    int from[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    dist[0] = 0;
    from[0] = -1;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minDist(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] && visited[v] == false && adj[u][v] < dist[v])
            {
                dist[v] = adj[u][v];
                from[v] = u;
            }
        }
    }

    printMST(from, adj);
}

int convert_ch(char ch)
{
    return ch - 'A';
}

char convert_int(int n)
{
    return n + 'A';
}

int main()
{
    int adj[V][V] = {{0, 8, 0, 0, 0, 10, 0, 4},
                     {8, 0, 4, 0, 10, 7, 0, 9},
                     {0, 4, 0, 3, 0, 3, 0, 0},
                     {0, 0, 3, 0, 25, 18, 2, 0},
                     {0, 10, 0, 25, 0, 2, 7, 0},
                     {10, 7, 3, 18, 2, 0, 0, 0},
                     {0, 0, 0, 2, 7, 0, 0, 3},
                     {4, 9, 0, 0, 0, 0, 3, 0}};

    PrimMST(adj);
    return 0;
}