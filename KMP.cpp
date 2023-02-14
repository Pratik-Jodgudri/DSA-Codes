#include <iostream>
using namespace std;

void calLPS(string p, int* LPS, int plen)
{
    LPS[0] = 0;
    int i = 0, j = 1;
    
    while(j<plen)
    {
        if(p.at(i) == p.at(j))
        {
            LPS[j] = i+1;
            i++; j++;
        }
        else
        {
            if(i==0)
            {
                LPS[j] = i;
                j++;
            }
            else
            {
                i = LPS[i-1];
            }
        }
    }
}

int main()
{
    string s = "abababaab";
    string p = "aba";
    
    int slen = s.length();
    int plen = p.length();
 
    int LPS[plen];
    int i = 0, j = 0;
    calLPS(p, LPS, plen);
    
    while(i < slen)
    {
        if (p.at(j) == s.at(i))
        {
            i++; j++;
        }
        if (j == plen)
        {
            cout << "Pattern matched at " << i - plen << endl;
            j = LPS[j-1];
        }
        else if (i < slen && p.at(j) != s.at(i))
        {
            if(j==0)
                i++;
            else
                j = LPS[j-1];
        }
    }
    
    return 0;
}
