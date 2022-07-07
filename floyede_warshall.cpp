#include <bits/stdc++.h>
using namespace std;

int min(int a ,int b)
{
    return (a>b)?b:a;
}
int main()
{
    int i, j,k, n;
    cout << "Enter the number of vertex:";
    cin >> n;
    cout<<"Enter the matrix\n";
    int a[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                a[i][j] = min(a[i][j] , a[i][k] + a[k][j]);
    
    for(i = 0;i<n;i++)
    {
        for(j =0;j<n;j++)
        {
            cout<<a[i][j]<<"\t ";
        }
        cout<<endl;
    }     
    return 0;
}