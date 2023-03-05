#include <bits/stdc++.h>
using namespace std;

int Knap(int **dp, int w[], float v[], int ind, int cap)
{
    if (ind == 0)
    {
        if (w[ind] <= cap)
            return dp[ind][cap] = v[ind];
        else
            return dp[ind][cap] = 0;
    }

    if (dp[ind][cap] != -1)
        return dp[ind][cap];

    int notinc = Knap(dp, w, v, ind - 1, cap);
    int inc = INT_MIN;
    if (w[ind] <= cap)
        inc = Knap(dp, w, v, ind - 1, cap - w[ind]) + v[ind];

    return dp[ind][cap] = inc > notinc ? inc : notinc;
}

int main()
{
    int n = 3;
    int cap = 4;

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[cap + 1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < cap + 1; j++)
            dp[i][j] = -1;
    }

    int w[n];
    float v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }

    int temp = Knap(dp, w, v, n - 1, cap);

    cout << "Ans: " << dp[n - 1][cap];

    return 0;
}