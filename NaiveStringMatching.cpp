#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; // = "abaabaabbab";
    string p; // = "aab";
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the pattern to match: ";
    cin >> p;
    int slen = s.length();
    int plen = p.length();
    int flag = 0;

    for(int i = 0; i <= slen-plen; i++)
    {
        int j = 0; 
        while(j < plen && s[i+j] == p[j])
        {
            j++;
        }
        if(j == plen)
        {
            cout << "Pattern matched at: " << i << endl;
            flag = i;
        }
    }

    if(flag == 0)
    {
        cout << "Pattern doesn't exist";
    }
    
    return 0;
}