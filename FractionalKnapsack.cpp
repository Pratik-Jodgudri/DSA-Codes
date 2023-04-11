#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int w; 
    float val;
    float ratio;
}Item;

void init(Item a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        a[i].ratio = a[i].val/a[i].w;
    }

    for(int i = 0; i < n-1; i++)
    {
        int max = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j].ratio > a[max].ratio)
                max = j;
        }
        
        Item temp = a[max];
        a[max] = a[i];
        a[i] = temp;
    }
}

void change(Item a[], int n, int cap)
{
    float amt = 0;

    for(int i = 0; i<n; i++)
    {
        if(a[i].w <= cap)
        {
            amt += a[i].val;
            cap -= a[i].w;
            // cout << amt << " " << cap << endl;
        }
        else
        {
            amt += ((float)cap/(float)a[i].w)*a[i].val;
            break;
        }
    }
    cout << "The maximum amount: " << amt << endl;
}

int main()
{
    int n, cap;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity: ";
    cin >> cap;
    Item a[n];
    for(int i = 0; i<n; i++)
    {
        cout << "Enter the weight of Item " << i+1 << ": ";
        cin >> a[i].w;
        cout << "Enter the value of Item " << i+1 << ": ";
        cin >> a[i].val;
    }

    init(a, n);
    // for(int i = 0; i<n; i++)
    // {
    //     cout << a[i].w << " ";
    // }
    // cout << endl;
    change(a, n, cap);
    return 0;
}