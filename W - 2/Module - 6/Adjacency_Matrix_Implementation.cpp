#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int arr[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1; // ei line tar jonno undirected graph hbe
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
4
5
1 2
1 3
2 4
4 3
3 2
*/