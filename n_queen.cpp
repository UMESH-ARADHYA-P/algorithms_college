#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool is_safe(int row,int col,int n)
{
    for(int i = row -1;i>=0;i--)
    {
        if(board[i][col])
        return false;
    }
    for(int i = row -1,j = col -1;i>= 0 && j >= 0;i--,j--)
    {
        if(board[i][j])
        return false;
    }
    for(int i = row -1,j  =col+1; i>=0 && j<n;i--,j++)
    {
        if(board[i][j])
        return false;
    }
    return true;
}
void helper(int row,int n)
{
    if(n == row)
    {
        for(int i  = 0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<" *** \n";
    }
    else{
        for(int i = 0;i<n;i++)
        {
            if(is_safe(row,i,n))
            {
                board[row][i] = 1;
                helper(row+1,n);
                board[row][i] = 0;
            }
        }
    }
}

void nqueen(int n)
{
    helper(0 ,n);
}
int main()
{
    int n;
    cout<<"Enter the size of the board :";
    cin>>n;
    for(int i =0 ;i<n;i++)
    {
        for(int  j= 0;j<n;j++)
        board[i][j] = 0;
    }
    nqueen(n);
    return 0;
}


