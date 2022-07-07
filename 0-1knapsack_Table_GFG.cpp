#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{

    int i, j;
    int dp[n + 1][W + 1];

    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= W; j++)
        {
            if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
        }
    }

    cout << "\nThe most valuable subset is:{";
    j = W;
    for (i = n; i >= 1; i--)
        if (dp[i][j] != dp[i - 1][j])
        {
            cout << "  item  " << i;
            j = j - wt[i - 1];
        }
    cout << "}";
    cout << endl;

    return dp[n][W];
}

int main()
{

    cout << "Enter the number of element\n";
    int n;
    cin >> n;
    int val[n], wt[n];
    int W;
    cout << "Enter weight\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of the element " << i + 1 << "::";
        cin >> wt[i];
    }
    cout << "Enter value\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the weight of element " << i + 1 << "::";
        cin >> val[i];
    }
    cout << "Enetr the capacity of the knapsack ::";
    cin >> W;
    int max_profit = knapSack(W, wt, val, n);

    cout<<"The maximum profit is "<< max_profit;
    return 0;
}