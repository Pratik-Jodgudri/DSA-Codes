#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int element)
{
	int mid, high, low;
	low = 0;
	high = size-1;
	
	// Keep searching untill low <= high.
	while(low <= high)	
	{
		mid = (low + high)/2;
		if (arr[mid] == element)
		{
			return mid;
		}
		if (arr[mid] < element)
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return -1;
}

int main()
{
	int arr[] = {1, 2, 4, 56, 64, 73, 123, 225, 444};
	int size = sizeof(arr)/sizeof(int);
	int element = 4;
	int searchIndex = binarySearch(arr, size, element);
	cout << "The element " << element << " was found at index: " << searchIndex << endl;
	return 0;
}


int BinarySearch(int arr[], int x, int l, int h)
{
	if(l>h)
		return -1;
	int mid = (l+h)/2;
	if(x == arr[mid])
		return mid;
	else if(x < arr[mid])
		return BinarySearch(arr, x, l, mid-1);
	else 
		return BinarySearch(arr, x, mid+1, h);
}