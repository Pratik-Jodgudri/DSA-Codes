#include <bits/stdc++.h>
#include <stack>
using namespace std;

stack <int> stck;
bool found = false;

void print()
{
    cout << "Subset: ";
    stack <int> temp;
    
    while(!stck.empty())
    {
        temp.push(stck.top());
        stck.pop();
    }

    while(!temp.empty())
    {
        cout << temp.top() << " ";
        stck.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

void solve(int arr[], int n, int ind, int sum, int tar)
{
    if(sum > tar)
    {
        return;
    }
    else if(sum == tar)
    {
        found = true;
        print();
        return;
    }
    else
    {
        for(int i = ind; i < n; i++)
        {
            stck.push(arr[i]);
            solve(arr, n, i+1, sum+arr[i], tar);
            stck.pop();
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the Set: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the Set: \n";
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    int tar, sum;
    sum =  0;
    cout << "Enter the target value: ";
    cin >> tar;

    solve(arr, n, 0, sum, tar);

    if(found == false)
        cout << "No Solution";
}