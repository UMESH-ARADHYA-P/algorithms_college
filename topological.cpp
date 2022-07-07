#include <bits/stdc++.h>
using namespace std;

void topologicalSort(vector<int> adj[], int V)
{
    vector<int> in_degree(V, 0);

    for (int u = 0; u < V; u++)
    {
        for (int x : adj[u])
            in_degree[x]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int x : adj[u])
            if (--in_degree[x] == 0)
                q.push(x);
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V ;
    
    cout<<"Enter the number of vertex::";
    cin>>V;
    vector<int> adj[V];
    cout<<"Enter the number of edges::";
    int n;cin>>n;
    int x,y;
    cout<<"Enter the directed edge  :\n";
    cout<<" vertex A to vertex B respectively:\n";
    for(int i = 0;i<n;i++)
    {
        cin>>x>>y;
        addEdge(adj, x,y);

    }
    
    cout << "Following is a Topological Sort of\n";
    topologicalSort(adj, V);

    return 0;
}
