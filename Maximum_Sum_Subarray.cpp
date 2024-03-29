#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int crosssum(int *arr, int l, int m, int h)
{
    int left = INT_MIN, sum = 0;
    for (int i = m; i >= l; i--)
    {
        sum += arr[i];
        if (left < sum)
            left = sum;
    }

    int right = INT_MIN;
    sum = 0;
    for (int i = m + 1; i <= h; i++)
    {
        sum += arr[i];
        if (right < sum)
            right = sum;
    }
    
    return (left+right);
}

int maxsum(int *arr, int l, int h)
{
    if (l == h)
        return arr[l];

    int m = (l + h) / 2;

    int temp = max(maxsum(arr, l, m), maxsum(arr, m + 1, h));
    return max(temp, crosssum(arr, l, m, h));
}

int main()
{
    int n; // = 7;
    cout << "Enter the no. of elements in the array: ";
    cin >> n;
    
    int arr[n]; // = {3, -1, -1, 10, -3, -2, 4};
    cout << "Enter the elements of the array: \n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "The maximum Sum of subarray is: " << maxsum(arr, 0, n-1) << endl;

    return 0;
}