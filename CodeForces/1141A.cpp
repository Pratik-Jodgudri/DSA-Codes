#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (m % n != 0) {
        cout << -1 << endl;
    }
    else{
        int ans = 0;
        int d = m / n;
        while (d % 2 == 0){
            ans += 1;
            d /= 2;
        }
        while (d % 3 == 0){
            ans += 1;
            d /= 3;
        }
        if (d != 1) {
            cout << -1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }

    return 0;
}