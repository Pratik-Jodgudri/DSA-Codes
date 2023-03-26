#include <bits/stdc++.h>
using namespace std;

int Karat(string a, string b)
{
    // cout << "---> a: " << a << " b: " << b << " <---"<< endl;
    int alen = a.length();
    int blen = b.length();
    // cout << alen << " " << blen << endl;

    if (alen == 1 && blen == 1)
    {
        int ai = stoi(a);
        int bi = stoi(b);
        // cout << "returning: " << ai << " * " << bi << endl;
        return (ai * bi);
    }
    else
    {
        int n = alen > blen ? alen : blen;

        while (alen != n)
        {
            a = "0" + a;
            alen = a.length();
        }
        // cout << a << endl;
        while (blen != n)
        {
            b = "0" + b;
            blen = b.length();
        }
        // cout << b << endl;

        string al = a.substr(0, n / 2);
        string ar = a.substr(n / 2, n - (n / 2));
        string bl = b.substr(0, n / 2);
        string br = b.substr(n / 2, n - (n / 2));

        // cout << "al: " << al << ", ar: " << ar << ", bl: " << bl << ", br: " << br << endl;

        int x1 = Karat(al, bl);
        // cout << "x1: " << x1 << endl;
        // cout << "x2: " << endl;
        // cout << "al: " << al << ", ar: " << ar << ", bl: " << bl << ", br: " << br << endl;

        int x2 = Karat(to_string(stoi(al) + stoi(ar)), to_string(stoi(bl) + stoi(br)));
        // cout << "x2: " << x2 << endl;
        int x3 = Karat(ar, br);
        // cout << "x3: " << x3 << endl;

        int m = (n + 1) / 2;

        int result = (x1 * pow(10, 2 * m) + (x2 - x1 - x3) * pow(10, m) + x3);

        // cout << "result = " << result << endl;

        return result;
    }
}

int main()
{
    int a, b;
    cout << "Enter the two numbers: \n";
    cin >> a >> b;

    // cout << "a = " << a << ", b = " << b << endl;

    cout << "Multiplication of the numbers " << a << " and " << b << " is: \n" << Karat(to_string(a), to_string(b)) << endl;
    return 0;
}
