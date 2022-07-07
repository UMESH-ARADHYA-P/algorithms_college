#include <iostream>
using namespace std;
int main()
{
    int i, j, k, n, c[50][50];

    cout<<"\n enter the value of n & k\n";
    cin>>n>>k;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= k; j++)
            c[i][j] = 0;

    for (i = 0; i <= n; i++)
    {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for (i = 2; i <= n; i++)
        for (j = 1; j <= i - 1; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];

    cout<<"\nThe table for valuation is\n";
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= k; j++)
            if (c[i][j] != 0)
                cout<< c[i][j];
        cout<<endl;
    }
    cout<<"The binomial coefficient of c ("<<n<<" "<<k<<") is"<<c[n][k];
    return 0;
}