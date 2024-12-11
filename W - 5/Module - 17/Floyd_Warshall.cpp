#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = N;
            if (i == j)
                a[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(a[i][j]>a[i][k]+a[k][j])
                a[i][j]=a[i][k]+a[k][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i][j]==N) cout<<"X"<<" ";
            else cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}