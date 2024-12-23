#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;

    vector<int> f(26, 0);
    for(int i = 0; i < s.length(); i++){
        f[s[i] - 'a'] += 1;
    }
    int flag = 0;
    for(int i = 0; i < f.size(); i++){
        if (f[i] % k != 0) {
            flag = 1;
        }
    }
    if(flag) {
        cout << -1 << endl;
    }
    else {
        string ans = "";
        for(int i = 0; i < f.size(); i++){
            for (int j = 0; j < f[i] / k; j++) {
                ans += (char)(i + (int)'a');
            }
        }
        for(int i = 0; i < k; i++){
            cout << ans;
        }
        cout << endl;
    }

    return 0;
}