#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int N=1e18;
    long long int n, m;
    cin >> n >> m;
    long long int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = N;
        }
    }
    while (m--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        if (a[u][v] >= w)
        {
            a[u][v] = w;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (a[i][j] == INT_MAX)
    //             cout << "x"
    //                  << " ";
    //         else
    //             cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    long long int x;
    cin >> x;
    while (x--)
    {
        long long int s, d;
        cin >> s >> d;
        if (a[s][d] == N)
            cout << "-1" << endl;
        else
            cout << a[s][d] << endl;
    }

    return 0;
}