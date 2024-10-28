#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int x, ans;

    while (t)
    {
        cin >> x;
        ans = 0;

        for(int i = 1; i < x%10; i++){
            ans += 10;
        }

        int len = to_string(x).length();
        ans += (len * (len + 1) / 2);

        cout << ans << endl;

        t--;
    }
    

    return 0;
}