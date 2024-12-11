#include <bits/stdc++.h>
using namespace std;

const int N = 20;
vector<int> adj[N];
bool visited[N];
int x = 0;

void bfs(int per)
{
    queue<int> q;
    q.push(per);
    visited[per] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int child : adj[f])
        {
            if (visited[child]) continue;
            x++;
            q.push(child);
            visited[child] = true;
        }
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
    }

    int k;
    cin >> k;
    bfs(k);
    cout << x;

    return 0;
}