#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
// vector<int> adj[N];
vector<pair<int, int>> adj[N];  // this for wighted graph;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({v, w}); // ei line tar jonno undirected graph hbe
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (auto j : adj[i])
        {
            cout << "(" << j.first << "," << j.second << ") ";
        }
        cout << endl;
    }
    return 0;
}

/*
4
5
1 2 10
1 3 20
2 4 30
4 3 40
3 2 50
*/