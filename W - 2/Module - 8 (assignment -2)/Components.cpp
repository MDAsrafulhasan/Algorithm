#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N];
bool visited[N];
int level[N];

int x = 1;

void dfs(int per)
{
    visited[per] = true;
    for (int child : adj[per])
    {
        if (visited[child])
            continue;
        x++;
        dfs(child);
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

    vector<int> v;

    for (int i = 0; i < 1001; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        if (x > 1)
        {
            v.push_back(x);
            x = 1;
        }
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}