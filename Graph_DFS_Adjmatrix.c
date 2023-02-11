#include <stdio.h>

int stack[10], adj[10][10], visited[10];
int top=-1; 
int max=9;

void push(int data)
{
	top++;
	stack[top] = data;
}

int pop()
{
	int data;
	data = stack[top];
	top--;
	return data;
}

int isFull()
{
	if(top == max)
	{
	    return 1;
	}
    return 0;
}

int isEmpty()
{
	if(top == -1)
	{
		return 1;
	}
    return 0;
}

int peek()
{
	return stack[top];
}

int convert_ch(char ch);
char convert_int(int n);

void display()
{
	printf("Stack: ");
	for(int i=top; i>=0; i--)
	{
		printf("%c ", convert_int(stack[i]));
	}
	printf("\n");
}

void dfs(int v, int n)
{
	// visited[v-1] = 1;
	// printf("%d ", v);
	push(v);
	int curr, c;
	while(!isEmpty())
	{
		// printf("Inside While\n");
		curr = pop();
		// display();
		if(visited[curr-1] != 1)
		{
			visited[curr-1] = 1;
			printf("%c ", convert_int(curr));
		}
		for(int i = n; i>=1; i--)
		{
			if(adj[curr][i] == 1 && visited[i-1] == 0)
			{
				push(i);
				// display();
			}
		}
	}
}

void addEdge(int src, int des)
{
    adj[src][des] = 1;
}

int convert_ch(char ch)
{
    return ch + 1 - 'A';
}

char convert_int(int n)
{
    return n + 'A' - 1;
}


void initiliseAdj(int n)
{
	for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            adj[i][j] = 0;
        }
    }
}

int main()
{
    int n = 8;

    initiliseAdj(n);

    addEdge(convert_ch('D'), convert_ch('C'));
    addEdge(convert_ch('D'), convert_ch('F'));
    addEdge(convert_ch('D'), convert_ch('E'));
    addEdge(convert_ch('F'), convert_ch('C'));
    addEdge(convert_ch('E'), convert_ch('G'));
    addEdge(convert_ch('G'), convert_ch('D'));
    addEdge(convert_ch('G'), convert_ch('H'));
    addEdge(convert_ch('H'), convert_ch('B'));
    addEdge(convert_ch('A'), convert_ch('B'));
    addEdge(convert_ch('H'), convert_ch('A'));

    dfs(convert_ch('D'), n);

    return 0;
}