#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adj[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // ei line tar jonno undirected graph hbe
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (int j : adj[i])
        {
            cout << j << " ";
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