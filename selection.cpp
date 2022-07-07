#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n)
{
    int i ,j,min,k;
    for(i = 0;i<n;i++)
    {
        min = i;
        for(j =i +1 ;j<n;j++)
        {
            if(arr[j]<arr[min])
            min = j;
        }
        swap(arr[min],arr[i]);
    }
}
int main()
{
    int arr[] = { 2,33,4,566,78,41};
    int  n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0;i<n;i++)
    cout<<arr[i]<<" ";
    selection_sort(arr,n);
    cout<<"\nAfter sorting\n";
    for(int i = 0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}