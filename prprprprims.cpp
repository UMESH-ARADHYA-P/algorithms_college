
//prims
#include<iostream>
using namespace std;

int min_index(int *key, bool *visited, int num){
    int min = 999, min_index;

    for(int i=0; i<num; i++){
        if(visited[i] == false && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

void printMST(int *parent, int arr[10][10], int num){
    for(int i=1; i<num; i++){
        cout<<parent[i]<<" - "<<i<<"\t"<<arr[i][parent[i]]<<endl;
    }
}

void prims(int arr[10][10], int num){
    int parent[10], key[10];
    bool visited[10];

    for(int i=0; i<num; i++){
        key[i] = 999;
        parent[i] = -1;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i=0; i<num-1; i++){
        int u = min_index(key, visited, num);
        visited[u] = true;

        for(int j=0; j<num; j++){
            if(arr[u][j] != 0 && visited[j] == false && arr[u][j] < key[j]){
                parent[j] = u;
                key[j] = arr[u][j];
            }
        }
    }
    int r = 0;
    for(int i = 0;i<num ;i++)
    {
        r += key[i];
    }
    cout<<"The minimum cost is "<<r<<" \n";
    cout<<"the minimunm spanning tree is\n";
    printMST(parent, arr, num);
}

int main(){
    int arr[10][10];
    int num;

    cout<<"Enter number of vertices: ";
    cin>>num;

    cout<<"Enter cost adjacency matrix: ";
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            cin>>arr[i][j];
        }
    }

    prims(arr, num);
}

