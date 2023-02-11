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

// Insertion -> Insert an element in arr.
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
	if(size >= capacity)
	{
		return -1;
	}
	for (int i = size-1; i >= index; i--)
	{
		arr[i+1] = arr[i];
	}
	arr[index] = element;
	return 1;
}

int main()
{
	int arr[100] = {7, 8, 12, 27, 88};
	int size = 5, element = 45, index = 4;
	
	display(arr, size);
	indInsertion(arr, size, element, 100, index);
	size += 1;
	
	// Display if inserted else errror.
	if(arr[index] == element)
	{
		display(arr, size);	
	}
	else
	{
		cout << "Error";
	}
	return 0;
}
