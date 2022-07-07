    
#include<bits/stdc++.h>
using namespace std;

int findMin(int *dist, bool *visited, int num){
    int min_index, min=INT_MAX;

    for(int i=0; i<num; i++){
        if(visited[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}
    


void dijkstra(int cost[10][10], int src, int num){
    int *dist = new int[num];
    bool *visited = new bool[num];

    for(int i=0; i<num; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for(int i=0; i<num; i++){

        int u = findMin(dist, visited, num);
        visited[u] = true;

        for(int j=0; j<num; j++){
            if(!visited[j] && cost[u][j] && dist[u] != INT_MAX && (dist[j] > (dist[u] + cost[u][j]))){
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }
    for(int i=0; i<num; i++){
        cout<<src<<" -> "<<i<<": "<<dist[i]<<endl;
    }
}

int main(){
    int num, cost[10][10];

    cout<<"Enter number of vertices: ";
    cin>>num;

    cout<<"Enter adjacency matrix (represent INF with 999):\n";
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            cin>>cost[i][j];
        }
    }

    dijkstra(cost, 0, num);

    return 0;
}
