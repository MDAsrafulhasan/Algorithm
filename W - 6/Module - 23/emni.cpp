#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 1;
    int s;
    cin >> s;

    int dp[n + 1][s + 1];

    dp[0][0] = 1;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = 0;
    }
    int i=1;
    while(i<=s)
    {
        for (int j = 0; j <= s; j++)
        {
            if (i * 2 <= j)
            {
                if (i * 2 == j)
                {
                    dp[i][j] = i * 2;
                    i*=2;
                }

                else if (i * 2 < j)
                {
                    dp[i][j] = i * 2;
                    i*=2;
                }
                else
                {
                    dp[i][j] = i * 2;
                    i*=2;
                }
            }
            else
            {
                if (i + 3 == j)
                {
                    dp[i][j] = i + 3;
                    i+=3;
                }
                else if (i + 3 < j)
                {
                    dp[i][j] = i + 3;
                    i+=3;
                }
                else
                {
                    dp[i][j] = i + 3;
                    i+=3;
                }
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout<<dp[i][s];

    // if (dp[n][s]==s)
    //     cout << "yes";
    // else
    //     cout << "no";

    return 0;
}
