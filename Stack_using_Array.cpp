#include <iostream>
using namespace std;

#define MAX 10

class Stack
{
	int top;
	
	public:
		int arr[MAX];
		
		Stack() { top = -1; }	
		void push(int data);
		int pop();
		int peek();
		void display();
		bool isEmpty();
};

void Stack::push(int data)
{
	if (top >= MAX)
	{
		cout << "Stack Overflow!" << endl;
	}
	else 
	{
		arr[++top] = data;
		cout << data << " was Pushed Successfully!\n";
	}
}

int Stack::pop()
{
	if (top<0)
	{
		cout << "Stack Underflow!\n";
	}
	else 
	{
		int data = arr[top--];
		return data;
	}
}

int Stack::peek()
{
	if(top < 0)
	{
		cout << "Stack Underflow!\n";
	}
	else 
	{
		int data = arr[top];
		return data;
	}
}

void Stack::display()
{
	for(int i=top; i>=0; i--)
	{
		cout << arr[i] << endl;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

int main()
{
	class Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	
	cout << s.pop() << " Poped from Stack\n";
	
	cout << "The Top Element is " << s.peek() << endl;
	
	cout << "The Elements in the stack are:\n";
	s.display();
	return 0;
}
