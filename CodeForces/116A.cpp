#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a, b;
    int amt = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        
        amt = amt - a + b;

        if (ans < amt){
            ans = amt;
        }

    }

    cout << ans << endl;

    return 0;
}