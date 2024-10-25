#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; 
    cin >> s;

    if (s[0] >= 'a'){
        cout << char(s[0] + 'A' - 'a'); 
    }
    else{
        cout << s[0];
    }

    cout << s.substr(1) << endl;

    return 0;
}