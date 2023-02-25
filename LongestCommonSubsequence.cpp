#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "speedy", s2 = "steady";
    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1], seq[m+1][n+1];

    for(int i = 0; i<m+1; i++)
    {
        for(int j = 0; j<n+1; j++)
        {
            dp[i][j] = seq[i][j] = 0;
        }
    }

    for(int i = 1; i < m+1; i++)
    {
        for(int j = 1; j<n+1; j++)
        {
            // cout << s1[i-1] << " " << s2[j-1] << endl;

            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
                seq[i][j] = 3;
            }
            else if(dp[i][j-1] > dp[i-1][j])
            {
                dp[i][j] = dp[i][j-1];
                seq[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
                seq[i][j] = 2;
            }
        }
    }

    int i = m, j = n;
    string ans = "";
    while(i != 0 && j != 0)
    {
        if(seq[i][j] == 3)
        {    
            ans = s1[i-1] + ans;
            i--; 
            j--;
        }
        
        else if(seq[i][j] == 2)
            i--;
        
        else
            j--;
    }

    cout << ans;

    // for(int i = 0; i<m+1; i++)
    // {
    //     for(int j = 0; j<n+1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for(int i = 0; i<m+1; i++)
    // {
    //     for(int j = 0; j<n+1; j++)
    //     {
    //         cout << seq[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}