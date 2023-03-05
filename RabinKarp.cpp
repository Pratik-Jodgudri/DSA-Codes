#include <bits/stdc++.h>
using namespace std;

#define prime 13

int main()
{
    //string p, s;
    string s="ABCCDDAEFGCDDF"; //    "ABAAABCDBBABCDDEBCABC";
    string p=  "CDD"; //ABC
    
    int plen = p.length();
    int slen = s.length();

    int ph = 0, sh = 0, h = 1, maxchar = 10;

    for (int i = 0; i < plen; i++) // cal pow(maxchar, plen-1)%prime
    {
        h = (h * maxchar) % prime;
    }

    for (int i = 0; i < plen; i++) // cal p-hash and s-hash
    {
        ph = (ph * maxchar + p[i] - 65 + 1) % prime;
        sh = (sh * maxchar + s[i] - 65 + 1) % prime;
    }

    cout << "hash value of the pattern " << p << " is " << ph << endl;
        cout << "hash value of the window " << s.substr(0, plen) << " is " << sh << endl;

    for (int i = 0; i < slen - plen; i++)
    {
        if (ph == sh)
        {
            int flag = 0, count = 0;

            for (int j = 0; j < plen; j++)
            {
                if (s[i + j] == p[j])
                    count++;
                else
                    break;
            }
            if (count == plen)
            {
                cout << "Position: " << i;
                flag = 1;
            }
        }

        if (i < slen - plen)
        {
            sh = (((sh - (s[i] - 65 + 1)) * h) * maxchar + ((s[i + plen] - 65 + 1) * h)) % prime;

            while (sh < 0)
                sh += prime;

            cout << "hash value of the window " << s.substr(i + 1, plen) << " is " << sh << endl;
        }
    }

    return 0;
}