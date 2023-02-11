#include <stdio.h>

int parent[8];
int find(int i);
int uni(int i, int j);

void Kruskals(int n, int adj[8][8])
{
    int mincost = 0;
    int ne = 1;
    int min, a, u, b, v, parent[8];
    while(ne < n)
    {
        for(int i=0; i<n; i++)
        {
            min = 999;
            for(int j = 0; j<n; j++)
            {
                if(adj[i][j] < min)
                {
                    min = adj[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        
        u = find(u);
        v = find(v);
        
        if(uni(u, v))
        {
            ne++;
            mincost += min;
        }
        
        adj[a][b] = adj[b][a] = 999;
    }
    
    printf("Cost of Minimum Spanning Tree = %d", mincost);
}

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int n = 8;

    int adj[8][8] = {{0, 8, 0, 0, 0, 10, 0, 4},
                      {8, 0, 4, 0, 10, 7, 0, 9},
                      {0, 4, 0, 3, 0, 3, 0, 0},
                      {0, 0, 3, 0, 25, 18, 2, 0},
                      {0, 10, 0, 25, 0, 2, 7, 0},
                      {10, 7, 3, 18, 2, 0, 0, 0},
                      {0, 0, 0, 2, 7, 0, 0, 3},
                      {4, 9, 0, 0, 0, 0, 3, 0}};


    for(int i =0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if(adj[i][j] == 0)
                adj[i][j] = 999;
        }
    }
    
    Kruskals(n, adj);
    
    return 0;
}
