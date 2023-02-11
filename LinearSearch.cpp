#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int element)
{
	for (int i=0; i< size; i++)
	{
		if(arr[i]==element)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int arr[] = {1, 2, 4, 56, 4, 3, 23, 5, 3, 54634, 56, 34};
	int size = sizeof(arr)/sizeof(int);
	int element = 4;
	int searchIndex = linearSearch(arr, size, 4);
	cout << "The element " << element << " was found at index: " << searchIndex << endl;
	return 0;
}
