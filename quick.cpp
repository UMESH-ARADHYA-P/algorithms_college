#include <bits/stdc++.h>
using namespace std;

int iPartition(int arr[], int l, int h)
{   
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

void qSort(int arr[],int l,int h){
    if(l<h){
        int p=iPartition(arr,l,h);
        qSort(arr,l,p-1);
        qSort(arr,p+1,h);
    }
}
 
int main() {
	
    int arr[]={8467,4,7232,9,3,10,5};
	
	int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"before sorting\n";
	for(int x: arr)
	    cout<<x<<" ";
	qSort(arr,0,n-1);
    cout<<"After sorting\n";
	
	for(int x: arr)
	    cout<<x<<" ";
}