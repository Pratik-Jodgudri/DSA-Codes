#include <stdio.h>

void Merge(int arr[], int arr1[], int arr2[], int n1, int n2)
{
    int i=0, j=0, k=0;
    
    while(i<n1 && j<n2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }
    
    while (i<n1)
    {
        arr[k++] = arr1[i++];
    }
    
    while (j<n2)
    {
        arr[k++] = arr2[j++];
    }
}

int main()
{
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    int arr1[n1], arr2[n2];
    
    for(int i=0; i<n1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    
    for(int i=0; i<n2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    
    int arr[n1+n2];
    
    Merge(arr, arr1, arr2, n1, n2);
    
    for(int i=0; i < (n1+n2); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}