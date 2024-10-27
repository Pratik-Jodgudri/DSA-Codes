#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int b = 0, i = 1;
    int sum = 0;

    while (true){
        sum = i * (i + 1) / 2;
        if (b + sum > n) break;
        b += sum;
        i++;
    }

    cout << i - 1 << endl;

    return 0;
}