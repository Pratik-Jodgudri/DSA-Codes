#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    int a[n]; // 1 2 3 4 5 
    for(int i = 0; i < n; i++)   
    {
        cin >> a[i];
    }

    float min = INT_MAX;
    int ind = 0;

    for(int k = 1; k <= n-1; k++)
    {
        cout << " k: " << k << endl;
        float left = 0;
        for(int i = 0; i < k; i++)
        {
            left += a[i];
        }
        left = (float)left/(float)k;
        cout << "left: " << left << " ";

        float right = 0;
        for(int j = k; j < n; j++)
        {
            right += a[j];
        }
        right = (float)right/(float)(n-k);
        cout << "right: " << right << " ";

        float diff = abs(left - right);
        cout << "diff: " << diff << "\n";

        if(diff < min)
        {
            min = diff;
            ind = k;
        }
    }

    cout << "1st Subarray: ";
    for(int i = 0; i < ind; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "2nd Subarray: ";
    for(int i = ind; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}