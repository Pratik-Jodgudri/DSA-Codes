#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int cost[MAX][MAX];
int n;

int main()
{
    int i, j, k, c, x, y;
    int max_edges, origin, destin;
    
    cout << "Enter number of nodes : ";
    cin >> n;
    
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cost[i][j] = 999999;
        }
    }
    
    max_edges = n * (n - 1);
    
    for (i = 1; i <= max_edges; i++)
    {
        cout << "Enter edge ( 0 0 to quit ) " << i << " : ";
        cin >> origin >> destin;
    
        if ((origin == 0) && (destin == 0))
            break;
    
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge!\n";
            i--;
        }
    
        else
        {
            cout << "Enter the cost: ";
            cin >> c;                 // only for a valid edge, read its cost 'c' and store it in the appropriate
            cost[origin][destin] = c; // index of cost[ ][ ]
        }
    }
    
    // display
    cout << "\nInitial Cost Matrix\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << cost[i][j] << " ";
        cout << "\n";
    }
    
    for (i = 1; i <= n; i++)     // 'i' index generates the 4 iterations needed for individually exploring routes via
    {                            // 'j' index generates the row number of the matrices
        for (j = 1; j <= n; j++) // 'j' index generates the row number of the matrices
        {
            for (k = 1; k <= n; k++) // 'k' index generates the 4 columns that are to be processed in each row
            {
                if (cost[j][k] > cost[j][i] + cost[i][k])
                    cost[j][k] = cost[j][i] + cost[i][k];
            }
        }
    }
    
    cout << "\nFinal Cost Matrix\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << cost[i][j] << "   ";
        cout << "\n";
    }

    return 0;
}
