#include <bits/stdc++.h>
using namespace std;
int g[10][10];
int v;
void topo()
{
    int in[v];
    bool vi[v];
    for(int i  = 0;i<v;i++)
    {
        in[i] = 0;
        vi[i] = false;
    }
    for(int i =0;i<v;i++)
    {
        for(int j =0;j<v;j++)
        {
            if(g[i][j])
            {
                in[j]++;
            }
        }
    }
    
    queue<int> q;
    for(int i =0;i<v;i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
            vi[i] = true;
        }
    }
    
    while(!q.empty())
    {
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int i =0;i<v;i++)
        {
            if(g[u][i])
            {
                if(--in[i] == 0)
                    q.push(i);
            }
        }
    }
    


}
int main()
{   
    cout<<"Enter the number of vertex::";
    cin>>v;
    int i,j;
    cout<<"Enter the matrix \n";
	for(int i = 0;i<v;i++)
	{
		for(int  j =0;j<v;j++)
		{
			cin>>g[i][j];
		}
	}
    topo();
    cout << "Following is a Topological Sort of\n";
    
    return 0;
}
