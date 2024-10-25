#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    set<char> st;

    cin >> s;

    for(auto c : s){
        if (!st.count(c)){
            st.insert(c);
        }
    }

    if (st.size() % 2 == 0){
        cout << "CHAT WITH HER!" << endl;
    }
    else{
        cout << "IGNORE HIM!" << endl;
    }

    return 0;
}