#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, w;
    cin >> k >> n >> w;

    int req = w * (w + 1) * k / 2;

    if (req > n){
        cout << req - n << endl;
    }    
    else{
        cout << 0 << endl;
    }

    return 0;
}