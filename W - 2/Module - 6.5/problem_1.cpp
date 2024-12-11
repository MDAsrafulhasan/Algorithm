#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];

void dfs(int per)
{
    visited[per] = true;
    for (int child : adj[per])
    {
        if (visited[child]) continue;
        dfs(child);
    }
    
    cout << per << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    return 0;
}

/*
4 
4
1 2
4 3
3 2
2 4
*/