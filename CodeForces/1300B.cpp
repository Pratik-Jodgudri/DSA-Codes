#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t)
    {
        int n;
        cin >> n;

        vector <int> v(2*n + 1);

        for (int i = 1; i <= 2*n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        cout << v[n + 1] - v[n] << endl;

        t--;
    }

    return 0;
}