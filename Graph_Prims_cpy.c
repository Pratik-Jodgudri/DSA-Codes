#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 8

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    int count = 0;

	for (int i = 1; i < V; i++)
        count += graph[i][parent[i]];    
    
    printf("Cost of Minimum Spanning Tree = %d", count);
}

void primMST(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1; 

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = {{0, 8, 0, 0, 0, 10, 0, 4},
                       {8, 0, 4, 0, 10, 7, 0, 9},
                       {0, 4, 0, 3, 0, 3, 0, 0},
                       {0, 0, 3, 0, 25, 18, 2, 0},
                       {0, 10, 0, 25, 0, 2, 7, 0},
                       {10, 7, 3, 18, 2, 0, 0, 0},
                       {0, 0, 0, 2, 7, 0, 0, 3},
                       {4, 9, 0, 0, 0, 0, 3, 0}};

	primMST(graph);

	return 0;
}
