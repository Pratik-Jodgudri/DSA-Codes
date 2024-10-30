#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    set<char> st = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};

    string ans = "";
    for(char ch : s){
        if (st.count(ch)){
            continue;
        }
        else {
            ans += ".";
            ans += (char) tolower(ch);
        }
    }

    cout << ans << endl;
    

    return 0;
}