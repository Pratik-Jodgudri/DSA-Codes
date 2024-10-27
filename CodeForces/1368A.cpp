#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    int a, b, n;
    
    while (T){
        cin >> a >> b >> n;
        int ans = 0;
        while (a <= n && b <= n){
            if (a < b){
                a += b;
            }
            else{
                b += a;
            }
            ans++;
        }

        cout << ans << endl;

        T--;
    }

    return 0;
}