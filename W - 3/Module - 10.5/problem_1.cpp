#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pii> adj[N];
bool visited[N];
vector<int> dis(N, INF);

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dis[s] = 0;
    q.push({dis[s], s});
    while (!q.empty())
    {
        pii f = q.top();
        q.pop();
        int n = f.second;
        visited[n] = true;
        for (pii v_pair : adj[n])
        {
            int v = v_pair.first;
            int w = v_pair.second;
            if (visited[v])
                continue;
            if (dis[v] > w + dis[n])
            {
                dis[v] = w + dis[n];
                q.push({dis[v], v});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    int s, d;
    cin >> s >> d;

    dijkstra(s);
    cout << dis[d];

    return 0;
}

/*
6 9
1 2 5
2 3 2
1 3 10
3 4 1
4 1 5
1 5 9
5 6 1
2 6 4
2 5 2
4 6
*/