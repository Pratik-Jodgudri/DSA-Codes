#include <iostream>
using namespace std;

// Traversal ->  Display elements in an array using for loop.
void display(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

// Deletion -> Delete an element in arr.
int indDeletion(int arr[], int size, int capacity, int index)
{
	if(index >= capacity-1)
	{
		return -1;
	}
	for (int i = index; i < size-1; i++)
	{
		arr[i] = arr[i+1];
	}
	return 1;
}

int main()
{
	int arr[100] = {7, 8, 12, 27, 88};
	int size = 5, index = 2;
	
	display(arr, size);
	indDeletion(arr, size, 100, index);
	size -= 1;

	display(arr, size);	
	return 0;
}
