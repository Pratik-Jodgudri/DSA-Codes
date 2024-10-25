#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t){
        int n;
        cin >> n;
        
        vector <vector <int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        
        int ans = 0;
        
        // diagonal from each row header
        for (int i = 0; i < n; i++){
            int minm = INT_MAX;
            int p = i, q = 0;
            while (p < n && q < n){
                if (mat[p][q] < minm){
                    minm = mat[p][q];
                }
                p++;
                q++;
            }
            
            if (minm < 0){
                ans += -minm;
            }
        }
        
        // diagonal from each col header
        for(int j = 1; j < n; j++){
            int minm = INT_MAX;
            int p = 0, q = j;
            while (p < n && q < n){
                if (mat[p][q] < minm){
                    minm = mat[p][q];
                }
                
                p++;
                q++;
            }
            
            if (minm < 0){
                ans += -minm;
            }
        }
        
        
        cout << ans << endl;
        
        t--;
    }
    return 0;
}