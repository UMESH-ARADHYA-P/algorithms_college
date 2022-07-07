#include <bits/stdc++.h>
using namespace std;

int mChain(int p[], int n) 
{ 
  
    int dp[n][n];
    for (int i=0; i<n-1; i++)
       dp[i][i+1] = 0;
       
    for (int gap = 2; gap < n; gap++)
    {
        for (int i=0; i+gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k=i+1; k<j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + p[i]*p[k]*p[j]);
            }
        }     
    }
    
    return dp[0][n-1];
}    

int main() {
    cout<<"Enter the number of elements in matrix array::";
    int n;cin>>n;
    int arr[n];
    cout<<"Enter the array elements: \n";
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cost = mChain(arr, n);
    cout<<"The minimum multiplication cost is :"<<cost;
    return 0;
}