#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int w, val;
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
        for(int j = i; j < n; j++)
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
        if(a[i].val <= cap)
        {
            amt += a[i].w;
            cap -= a[i].val;
            // cout << amt << " " << cap << endl;
        }
        else
        {
            amt += ((float)cap/(float)a[i].w)*a[i].val;
            break;
        }
    }
    cout << amt;
}

int main()
{
    int n, cap;
    cin >> n >> cap;
    Item a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i].w >> a[i].val;
    }

    init(a, n);
    change(a, n, cap);
    return 0;
}