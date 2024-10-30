#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, m;

    while (t)
    {
        cin >> n >> m;
        vector<vector<char>> p(n, vector<char> (m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> p[i][j];
            }
        }

        int ans = 0;
        for (int i = n - 1; i >= 0; i--){
            for (int j = m - 1; j >= 0; j--){
                if (j + 1 < m && p[i][j] == 'R' && p[i][j + 1] == 'C'){
                    p[i][j] = 'C';
                }
                else if (i + 1 < n && p[i][j] == 'D' && p[i+1][j] == 'C')
                {
                    p[i][j] = 'C';
                }
                else if (p[i][j] != 'C')
                {
                    ans++;
                    p[i][j] = 'C';
                }
                
                
            }
        }

        cout << ans << endl;

        t--;
    }
    

    return 0;
}