#include <stdio.h>

void Merge(int arr[], int p, int q, int r);

void MergeSort(int arr[], int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;

        //printf("MergeSort(arr, %d, %d)\n", p, q);
        MergeSort(arr, p, q);
        //printf("MergeSort(arr, %d, %d)\n", q+1, r);
        MergeSort(arr, q+1, r);
        
        //printf("Merge(arr, %d, %d, %d)\n", p, q, r);
        Merge(arr, p, q, r);
    }
}

void Merge(int arr[], int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;

    int L[n1], R[n2];

    for(int i=0; i<n1; i++)
    {
        L[i] = arr[p+i];
    }
    for(int j=0; j<n2; j++)
    {
        R[j] = arr[q+j+1];
    }

    int i=0, j=0, k=p;

    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}