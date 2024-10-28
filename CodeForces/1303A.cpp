#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    string s;
    int flag, ans, len;

    while (t)
    {
        cin >> s;
        flag = 0;
        ans = 0;
        len = 0;

        for (int i = 0; i < s.length(); i++){
            if (s[i] == '0' && flag == 1){
                len++;
            }
            else if (s[i] == '1')
            {
                flag = 1;
                ans += len;
                len = 0;
            }
            
        }
        
        cout << ans << endl;

        t--;
    }
    

    return 0;
}