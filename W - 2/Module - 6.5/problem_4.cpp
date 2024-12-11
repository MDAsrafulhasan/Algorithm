#include <bits/stdc++.h>
using namespace std;

const int n = 1e3 + 5;
vector<int> adj[n];
int depth[n];
bool visited[n];

void dfs(int per, int x)
{
    visited[per] = true;
    if (per == x)
        cout << "Depth of " << per << " = " << depth[per];
    else
        for (int child : adj[per])
        {
            if (visited[child])
                continue;
            depth[child] = depth[per] + 1;
            dfs(child, x);
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
    int x;
    cin >> x;

    dfs(1, x);

    return 0;
}

/*
7 
6
1 2
2 4
2 5
1 3
3 6
1 7
7
*/