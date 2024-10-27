#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 0, len = 1;
    for(int i = 1; i < n; i++){
        if (v[i] > v[i-1]){
            len++;
        }
        else{
            ans = max(ans, len);
            len = 1;
        }
    }
    ans = max(ans, len);

    cout << ans << endl;

    return 0;
}