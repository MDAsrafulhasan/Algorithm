#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
    int n, s;
    cin >> n >> s;
    int weight[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    int dp[n + 1][s + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (weight[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j-weight[i-1]]+val[i-1],dp[i-1][j]);
            }
            else
            dp[i][j]=dp[i-1][j];
            
        }
    }

    cout<<dp[n][s]<<endl;
    }
    return 0;
}