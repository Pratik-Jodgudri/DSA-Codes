#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string t;
    cin >> n >> t;

    int p = 0;

    string s = "";
    for(int i = 0; p + i < n && i < 10; i++){
        p += i;
        s += t[p];
    }
    
    cout << s << endl;

    return 0;
}