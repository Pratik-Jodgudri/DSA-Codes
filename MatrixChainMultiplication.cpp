#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r[] = {13, 5, 89, 3, 34};
    int n = 4;
    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;
    }

    for(int len = 2; len <= n; len++)
    {
        for(int i = 0; i < n-len+1; i++)
        {
            int min = INT_MAX;
            int j = i+len-1;

            // cout << "Cell: " << i << "x" << j << endl;

            for(int k = i; k <= j-1; k++)
            {
                // cout << dp[i][k] << " " << dp[k+1][j] << " " << r[i] << "x" << r[k+1] << "x" << r[j+1] << endl; 
                int cost = dp[i][k] + dp[k+1][j] + r[i]*r[k+1]*r[j+1];

                // cout << "cost: " << cost << endl;

                if(min > cost)
                    min = cost;
            }
            dp[i][j] = min;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    
    cout << dp[0][n-1];

    return 0;
}