#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int c)
{
    visited[c] = true;
    for (int v : adj[c])
    {
        if (visited[v]) continue;
        dfs(v);
    }
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

    int cc=0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        cc++;
    }
    cout<<cc;

    return 0;
}

/*
7
4
1 2
2 3
3 4
5 6
*/