#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};	

void push(struct Node** top, int x)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = *top;
	*top = newNode;
	printf("%d Pushed into the stack.\n", x);
}

int isEmpty(struct Node *top)
{
	return top==NULL;
}

int pop(struct Node** top)
{
	if (isEmpty(*top))
	{
		printf("Stack Empty!");
	}
	struct Node* temp = *top;
	*top = temp->next;
	int poped = temp->data;
	free(temp);
	return poped;
}

int peek(struct Node* top)
{
	if(isEmpty(top))
		return 0;
	return top->data;
}

int main()
{
	struct Node* top = NULL;
	
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);
	
	printf("%d poped from the stack.\n", pop(&top));
	
	printf("Top element is %d\n", peek(top));
	
	return 0;
}
