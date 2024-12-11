#include <bits/stdc++.h>
using namespace std;

const int n = 1e3 + 5;
vector<int> adj[n];
bool visited[n];

bool dfs(int chi, int per)
{
    visited[chi] = true;
    bool iscycle = false;
    for (int child : adj[chi])
    {
        if (child == per)
            continue;
        if (visited[child])
            return true;
        iscycle = dfs(child, chi);
    }
    return iscycle;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        cycle = dfs(i, -1);
    }
    if (cycle)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
