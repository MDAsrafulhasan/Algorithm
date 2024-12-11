#include <bits/stdc++.h>
using namespace std;

const int n = 1e3 + 5;
vector<int> adj[n];
bool visited[n];
int level[n];

void bfs(int per, int x)
{
    queue<int> q;
    q.push(per);
    visited[per] = true;
    level[per] = 0;
    while (!q.empty())
    {
        int f=q.front();
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
    cout << "Level of " << x << " = " << level[x];
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
        adj[u].push_back(v);
    }
    int x;
    cin >> x;

    bfs(1, x);
    return 0;
}

/*
1st one- 
7 
6
1 2
2 4
2 5
1 3
3 6
1 7
7

2nd one- 
8 
7
1 2
2 4
2 5
1 3
3 6
1 7
4 8
8

*/