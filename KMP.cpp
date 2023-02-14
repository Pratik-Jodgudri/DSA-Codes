#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int source, dest;
    float wt;
};

int main()
{
    int vert, e;
    cout << "Enter the no. of vertices and edges: ";
    cin >> vert >> e;
    
    struct edge edges[e];
    
    for(int i = 0; i<e; i++)
    {
        cout << "Enter the value of source, destination and weight of edge " << i+1 << " : ";
        cin >> edges[i].source >> edges[i].dest >> edges[i].wt;
    }
    
    float dist[vert];
    
    int start;
    cout << "Enter the starting node: ";
    cin >> start;
    
    for(int i = 0; i<vert; i++)
        dist[i] = INT_MAX;
    
    dist[start-1] = 0;
    
    for(int i = 0; i<vert-1; i++)
    {
        for(int j = 0; j<e; j++)
        {
            int u = edges[j].source;
            int v = edges[j].dest;
            int w = edges[j].wt;
            
            if(dist[v-1] > dist[u-1] + w)
                dist[v-1] = dist[u-1] + w;
        }
    }
    
    int flag = 0;
    
    for(int i = 0; i<e; i++)
    {
        int u = edges[i].source;
        int v = edges[i].dest;
        int w = edges[i].wt;
        
        if(dist[v-1] > dist[u-1] + w)
        {
            flag = 1;
            break;
        }
    }
    
    if(flag == 0)
    {
        for(int i = 0; i<vert; i++)
        {
            cout << dist[i] << " - " << i << endl;
        }
    }
    else
        cout << "No Solution";
    
    return 0;
}
