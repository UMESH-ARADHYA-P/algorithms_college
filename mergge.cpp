#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int h)
{
    int n1  = m-l+1;
    int n2 = h-m;
    int left[n1],right[n2];
    for(int i = 0;i<n1;i++)
    left[i] = arr[l+i];
    for(int i = 0;i<n2;i++)
    right[i] = arr[m+1+i];

    int i= 0,j = 0,k =l;
    while(i<n1 && j <n2)
    {
        if(left[i] <= right[j])
        arr[k++] = left[i++];
        else
        arr[k++] = right[j++];
    }
    while(i < n1)
    {
        arr[k++] = left[i++];
    }
    while(j<n2)
    {
        arr[k++] = right[j++];
    }

}
void merge_sort(int arr[],int l ,int h)
{

if(h>l)
{    int mid  = l+(h-l)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,h);
    merge(arr,l,mid,h);
}
}

int main()
{
    // int arr[] = { 13,45,23,1,3,35,33,23};
    // int n = sizeof(arr) / sizeof(arr[0]);
    int n;cout<<"Enter the number of elements :";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:\n";
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before sorting :";
    for(int i =0;i<n;i++)
    cout<<arr[i]<<" ";
    merge_sort(arr,0,n-1);
    cout<<"\nAfter sorting \n";
    for(int  i = 0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}