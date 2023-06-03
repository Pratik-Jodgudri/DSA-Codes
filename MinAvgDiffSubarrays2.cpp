// Efficient C++ program for
// dividing array to make
// average equal
#include<bits/stdc++.h>
using namespace std;

void findSubarrays(int arr[], int n)
{
	// Find array sum
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	bool found = false;
	int lsum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		lsum += arr[i];
		int rsum = sum - lsum;
    
        float lavg = (float)lsum / (float) (i+1);
        float ravg = (float)rsum / (float) (n-i+1);
        
		// If averages of arr[0...i]
		// and arr[i+1..n-1] are same.
		// To avoid floating point problems
		// we compare "lsum*(n-i+1)"
		// and "rsum*(i+1)" instead of
		// "lsum/(i+1)" and "rsum/(n-i+1)"
// 		if (lsum * (n - i - 1) == rsum * (i + 1))
// 		{
// 			printf("From (%d %d) to (%d %d)\n",
// 							0, i, i+1, n-1);
// 			found = true;
// 		}
	}

	// If no subarrays found
	if (found == false)
		cout << "Subarrays not found"
			<< endl;
}

// Driver code
int main()
{
	int arr[] = {48, 32, 80, 2, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	findSubarrays(arr, n);
	return 0;
}
