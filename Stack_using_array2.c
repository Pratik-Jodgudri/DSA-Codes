#include <stdio.h>

int stck[10];
int top=-1; 
int max=9;

void push()
{
	int data;
	printf("Enter the value of element: ");
	scanf("%d", &data);
	top++;
	stck[top] = data;
}

void pop()
{
	int data;
	data = stck[top];
	top--;
	printf("%d\n", data);
}

void isFull()
{
	if(top == max)
	{
		printf("Stack is Full.");
	}
}

void isEmpty()
{
	if(top == -1)
	{
		printf("Stack is Empty.\n");
	}
}

void display()
{
	for(int i=top; i>0; i--)
	{
		printf("%d\n", stck[i]);
	}
}

int main()
{
	int n;
	
	for(int i=0; i<5; i++)
	{
		printf("Enter your choice:\n 1.Push \n 2.Pop \n 3.isFull \n 4.isEmpty \n 5.Display\n");
		scanf("%d", &n);
		
		if(n==1)
		{
			push();
		}
		else if(n==2)
		{
			pop();
		}
		else if(n==3)
		{
			isFull();
		}
		else if(n==4)
		{
			isEmpty();
		}
		else if(n==5)
		{
			display();
		}
	}
	return 0;
}