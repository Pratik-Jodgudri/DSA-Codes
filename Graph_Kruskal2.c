#include <stdio.h>

int i, j, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);
int uni(int, int);

int main() 
{
    n = 8;
      
    int cost[8][8] = {{0, 8, 0, 0, 0, 10, 0, 4},
                     {8, 0, 4, 0, 10, 7, 0, 9},
                     {0, 4, 0, 3, 0, 3, 0, 0},
                     {0, 0, 3, 0, 25, 18, 2, 0},
                     {0, 10, 0, 25, 0, 2, 7, 0},
                     {10, 7, 3, 18, 2, 0, 0, 0},
                     {0, 0, 0, 2, 7, 0, 0, 3},
                     {4, 9, 0, 0, 0, 0, 3, 0}};

      
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
      
    while (ne < n) 
    {
        for (i = 0, min = 999; i < n; i++) 
        {
            for (j = 0; j < n; j++) 
            {
                if (cost[i][j] < min) 
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        
        if (uni(u, v)) 
        {
            ne++;
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    
    printf("Cost of Minimum Spanning Tree = %d\n", mincost);
    
    return 0;
}

int find(int i) 
{
    while (parent[i])
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