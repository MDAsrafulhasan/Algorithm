#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> adj[N];
bool visited[N];
int level[N];
int x = -1;

void bfs(int per, int l)
{
    vector<int> v;
    queue<int> q;
    q.push(per);
    visited[per] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        if (level[f] == l)
        {
            v.push_back(f);
            x++;
        }
        for (int child : adj[f])
        {
            if (visited[child])
                continue;
            q.push(child);
            visited[child] = true;
            level[child] = level[f] + 1;
        }
    }
    if (x >= 0)
    {

        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    else
        cout << x;
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

    int l;
    cin >> l;
    bfs(0, l);

    return 0;
}