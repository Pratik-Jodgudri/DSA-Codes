#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int a = 0, b = 0, c = 0;

    for (char ch : s){
        if (ch == '1'){
            a++;
        }
        else if (ch == '2'){
            b++;
        }
        else if (ch == '3'){
            c++;
        }
    }


    string sa = "", sb = "", sc = "";
    if (a > 0){
        for (int i = 0; i < a - 1; i++){
            sa += "1+";
        }
        sa += "1";
    }
    if (b > 0){
        for (int i = 0; i < b - 1; i++){
            sb += "2+";
        }
        sb += "2";
    }
    if (c > 0){
        for (int i = 0; i < c - 1; i++){
            sc += "3+";
        }
        sc += "3";
    }

    
    string ans = "";

    if (sa != "") ans += sa;
    if (sb != ""){
        if (ans != "") ans += "+" + sb;
        else ans += sb;
    }
    if (sc != "") {
        if (ans != "") ans += "+" + sc;
        else ans += sc;
    }
    
    cout << ans << endl;
    

    return 0;
}