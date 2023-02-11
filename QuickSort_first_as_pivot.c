#include <stdio.h>
#include <string.h>

int Partition(char arr[], int low, int high);

void QuickSort(char arr[], int low, int high)
{
    if(low < high)
    {
        int pi = Partition(arr, low, high);

        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
}

int Partition(char arr[], int low, int high)
{
    char pivot = arr[low];
    char temp;
    int i = high+1;
    for(int j=high; j>low; j--)
    {
        if(arr[j] > pivot)
        {
            i--;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i-1];
    arr[i-1] = arr[low];
    arr[low] = temp;
    
    return i-1;
}

int main()
{
    char temparr[100];
    scanf("%s", temparr);

    int length = strlen(temparr);
    char arr[length];
    for(int i=0; i<length; i++)
    {
        arr[i] = temparr[i];
    }
    
    QuickSort(arr, 0, length-1);

    for(int i=0; i<length; i++)
    {
        printf("%c", arr[i]);
    }
    
    return 0;
}