void QuickSort(int arr[], int l, int h)
{
    if(l < h)
    {
        int pi = Partition(arr, l, h);

        QuickSort(arr, l, pi-1);
        QuickSort(arr, pi+1, h);
    }
}

int Partition(int arr[], int l, int h)
{
    int pivot = arr[h];

    int i = l-1;
    for(int j = l; j<h; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[h], arr[i+1]);

    return i+1;
}

void BubbleSort(int arr[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void InsertionSort(int arr[], int n)
{
    int key;
    for(int i = 1; i<n; i++)
    {
        key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key)
        {   
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void SelectionSort(int arr[], int n)
{
    int min;
    for(int i=1; i<n-1; i++)
    {
        min = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            swap(arr[min], arr[i]);
        }
    }
}

void CountSort(int arr[], int n, int k)
{
    int count[k+1], temp[n];
    for(int i = 0; i<k+1; i++)
    {
        count[i] = 0;
    }
    for(int i = 0; i<n; i++)
    {
        count[arr[i]]++;
    }
    for(int i = 1; i<=k; i++)
    {
        count[i] = count[i] + count[i-1];
    }
    for(int i = n-1; i>=0; i--)
    {
        temp[--count[arr[i]]] = arr[i];
    }
    for(int i=0; i<n; i++)
    {
        arr[i] = temp[i];
    }
}