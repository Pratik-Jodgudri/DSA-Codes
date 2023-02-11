#include <stdio.h>
#include <stdlib.h>

int A[20], n = 0;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void minheapify(int A[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    while (left < n && A[left] < A[smallest])
        smallest = left;
    while (right < n && A[right] < A[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(&A[smallest], &A[i]);
        minheapify(A, n, smallest);
    }
}

void Heapsort(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minheapify(A, n, i);
    }
    for (int i = n; i >= 0; i--)
    {
        swap(&A[i], &A[0]);
        minheapify(A, i, 0);
    }
}

void insert(int p)
{
    A[n] = p;
    Heapsort(A, n);
    n += 1;
}

int main()
{
    for (int i = 0; i < 12; i++)
    {
        int a;
        scanf("%d", &a);
        insert(a);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", A[i]);
    }
}