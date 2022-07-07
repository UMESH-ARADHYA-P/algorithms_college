#include <bits/stdc++.h>
using namespace std;
#define edge pair<int, int>
class Graph
{
    vector<pair<int, edge>> g;
    vector<pair<int, edge>> t;

    int v;

public:
    int *parent, *rank;
    Graph(int ve)
    {
        v = ve;
        parent = new int[v];
        rank = new int[v];
        for (int i = 0; i < ve; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
        g.clear();
        t.clear();
    }
    void add_ege(int x, int y, int w)
    {
        g.push_back(make_pair(w, edge(x, y)));
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        else
            return find(parent[x]);
    }
    void uni(int u, int v)
    {

        if (rank[u] < rank[v])
        {
            parent[u] = v;
            rank[v] += rank[u];
        }
        else
        {
            parent[v] = u;
            rank[u] += rank[v];
        }
    }
    void kruskal()
    {
        int urep, vrep;
        sort(g.begin(), g.end());
        for (int i = 0; i < g.size(); i++)
        {
            urep = find(g[i].second.first);
            vrep = find(g[i].second.second);
            if (urep != vrep)
            {
                t.push_back(g[i]);
                uni(urep, vrep);
            }
        }
    }
    void pri()
    {
        int cost = 0;
        cout << "edge \t weight\n";
        for (int i = 0; i < t.size(); i++)
        {
            cout << t[i].second.first << "---" << t[i].second.second << "    " << t[i].first << endl;
            cost += t[i].first;
        }
        cout << "The minimum cost of spanning tree is " << cost << endl;
    }
};

int main()
{
    int v, e;
    cout << "Enter the number of vertex ::";
    cin >> v;
    cout << "Enter the number of edges ::";
    cin >> e;
    Graph G(v);
    int w, x, y;
    cout << "Enter the edges and weight\n";
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> w;
        G.add_ege(x, y, w);
    }
    G.kruskal();
    G.pri();

    delete[] G.parent;
    delete[] G.rank;
    return 0;
}