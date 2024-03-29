#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; // = 4;
    cout << "Enter the no. of nodes: ";
    cin >> n;
    int a[2][n]; //= {{4, 5, 3, 2}, {2, 10, 1, 4}};
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "Enter the element at a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
    int t[2][n-1]; //= {{7, 4, 5}, {9, 2, 8}};
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            cout << "Enter the element at t[" << i << "][" << j << "]: ";
            cin >> t[i][j];
        }
    }
    int e[2]; //= {10, 12};
    cout << "Enter the two entry values: ";
    cin >> e[0] >> e[1];
    int x[2]; //= {18, 7};
    cout << "Enter the two exit values: ";
    cin >> x[0] >> x[1];

    int dp[2][n], path[2][n];

    dp[0][0] = a[0][0] + e[0];
    path[0][0] = 0;
    dp[1][0] = a[1][0] + e[1];
    path[1][0] = 1;

    for (int j = 1; j < n; j++)
    {
        int first = dp[0][j - 1] + a[0][j];
        int second = dp[1][j - 1] + a[0][j] + t[1][j - 1];

        if (first <= second)
        {
            dp[0][j] = first;
            path[0][j] = 0;
        }
        else
        {
            dp[0][j] = second;
            path[0][j] = 1;
        }

        first = dp[1][j - 1] + a[1][j];
        second = dp[0][j - 1] + t[0][j - 1] + a[1][j];

        if(first <= second)
        {
            dp[1][j] = first;
            path[1][j] = 1;
        }
        else
        {
            dp[1][j] = second;
            path[1][j] = 0;
        }
    }

    int last, min;

    int first = dp[0][n-1] + x[0];
    int second = dp[1][n-1] + x[1];

    if(first <= second)
    {   
        min = first;
        last = 0;
    }
    else
    {
        min = second;
        last = 1;
    }
    
    cout << "min: " << min << endl;

    // for(int i = 0; i<2; i++)
    // {
    //     for(int j = 0; j<n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for(int i = 0; i<2; i++)
    // {
    //     for(int j = 0; j<n; j++)
    //     {
    //         cout << path[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << (first<=second?first:second) << endl;

    int i = last;
    cout << "Exit must be reached from station: " << i << endl;

    for(int j = n-1; j > 0; j--)
    {
        i = path[i][j];
        cout << "Station " << j << " should be reached from assembly line " << i << endl;
    }
    
    return 0;
}