
#include<iostream>
using namespace std;
void ranksort(int *a,int n)
{
    int i,j,r[10],b[10];
    for(i=0;i<n;i++)
    {
        r[i]=0;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<=a[i])
            {
                r[i]=r[i]+1;
            }
            else
            {
                r[j]=r[j]+1;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        b[r[i]]=a[i];
    }
    cout<<"Solution  is"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}
int main()
{
    int a[10],i,n;
    cout<<"Enter number of array elements"<<endl;
    cin>>n;
    cout<<"Enter array elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ranksort(a,n);
    
}

