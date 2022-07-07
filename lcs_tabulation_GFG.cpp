#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2)
{
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];
    for(int i = 0;i<=m;i++)
    dp[i][0] = 0;
    for(int i = 0;i<=n;i++)
    dp[0][i] = 0;
    for(int i=1;i<=m;i++)
    {
        for(int j= 1 ;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int index = dp[m][n];
	char lcs[index + 1];
	lcs[index] = '\0';
    int i = m, j = n;
	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			lcs[index - 1]= s1[i - 1]; 
			i--;
			j--;
			index--; 
            }

		else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}
cout<<"The longest common subsequence is :"<<lcs<<endl;

    return dp[m][n];
}
int main()
{
    string s1,s2;
    cout<<"Enter the s1 :";
    cin>>s1;
    cout<<"Enter the s2 :";
    cin>>s2;
    cout<<endl; 
    int match = lcs(s1,s2);

    cout<<"Length of longest subsequence is :"<<match;
}