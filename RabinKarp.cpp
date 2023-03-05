#include <bits/stdc++.h>
using namespace std;

#define prime 13

int main()
{
    string s, p;
    s = "ABCCDDAEFGCDDF";
    p = "CDD";
    int slen = s.length();
    int plen = p.length();

    int sh = 0, ph = 0, h = 1, maxchar = 10;

    for (int i = 0; i < plen-1; i++)
    {
        h = (h * maxchar) % prime;
    }

    for (int i = 0; i < plen; i++)
    {
        ph = (ph * maxchar + p[i] - 65 + 1) % prime;
        sh = (sh * maxchar + s[i] - 65 + 1) % prime;
    }

    cout << "Hash value of pattern " << p << " -> " << ph << endl;
    cout << "Hash value of window " << s.substr(0, plen) << " -> " << sh << endl;

    for (int i = 0; i <= slen - plen; i++)
    {
        if (ph == sh)
        {
            int count = 0;
            for (int j = 0; j < plen; j++)
            {
                if (p[j] == s[i + j])
                {
                    count++;
                }
                else
                    break;
            }
            if (count == plen)
            {
                cout << "Pattern matched at: " << i << endl;
            }
        }

        if (i < slen - plen)
        {
            sh = ((sh - (s[i] - 65 + 1) * h) * maxchar + (s[i + plen] - 65 + 1)) % prime;

            while (sh < 0)
                sh += prime;

            cout << "Hash value of window " << s.substr(i + 1, plen) << " -> " << sh << endl;
        }
        
    }

    return 0;
}