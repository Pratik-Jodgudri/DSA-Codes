#include <stdio.h>

int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	
	char a[n];
	char key; 	
	for(int i=0; i<n; i++)
	{
		printf("Enter the element %d ", i+1);
		scanf("%s", &a[i]);
	}
	
	for(int i=1; i<n; i++)
	{
		key = a[i];
		int j=i-1;
		
		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	
	printf("Sorted array:\n");
	for(int i=0; i<n; i++)
	{
		printf("%c ", a[i]);
	}
}