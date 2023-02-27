#include <bits/stdc++.h>
using namespace std;

#define n 5
int adj[n][n] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {0, 1, 1, 1, 0}};

int color[n];
int m = 3;

bool issafe(int v, int c)
{
    for (int i = 0; i < n; i++)
        if (adj[v][i] == 1 && color[i] == c)
            return false;
    return true;
}

bool solve(int v)
{
    if(v == n)
        return true;
    for(int i = 1; i <= m; i++)
    {
        if(issafe(v, i))
        {
            color[v] = i;
            if(solve(v+1))
                return true;
            color[v] = 0;
        }
    }

    return false;
}

void print()
{
    cout << "Assigned colors are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "vertex " << i << " -> " << color[i] << endl;
    }
}

int main()
{
    for (int i = 0; i < n; i++)
        color[i] = 0;

    if (solve(0))
        print();
    else
        cout << "No Solution!";

    return 0;
}