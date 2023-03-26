#include <bits/stdc++.h>
using namespace std;

int n;
int adj[20][20]; // = {
//     {0, 1, 1, 0, 0},
//     {1, 0, 1, 0, 1},
//     {1, 1, 0, 1, 1},
//     {0, 0, 1, 0, 1},
//     {0, 1, 1, 1, 0}};

int color[20];
int m;

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
    cout << "Enter the number of vertices: ";
    cin >> n;
    
    cout << "Enter the elements in the adjacency matrix: \n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "[" << i << "][" << j << "]: ";
            cin >> adj[i][j];
        }
    }

    cout << "Enter the number of colors: ";
    cin >> m;
    for (int i = 0; i < n; i++)
        color[i] = 0;

    if (solve(0))
        print();
    else
        cout << "No Solution!";

    return 0;
}