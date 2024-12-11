#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N];
bool visited[N];
int level[N];
int x = -1;

void bfs(int per, int d)
{
    queue<int> q;
    q.push(per);
    visited[per] = true;
    while (!q.empty())
    {
        int f = q.front();
        if (f == d)
            x = 1;
        q.pop();
        for (int child : adj[f])
        {
            if (visited[child])
                continue;
            q.push(child);
            visited[child] = true;
            level[child] = level[f] + 1;
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
        adj[v].push_back(u);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int s, d;
        cin >> s >> d;
        bfs(s, d);
        if (x == 1)
            cout << level[d] << endl;
        else
            cout << x << endl;
        for (int j = 0; j < N; j++)
        {
            visited[j] = false;
            level[j] = 0;
        }
        x=-1;
    }

    return 0;
}