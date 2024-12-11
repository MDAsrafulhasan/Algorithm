#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10;
vector<pii> adj[N];
bool visited[N];
const int INF = 1e9 + 1;
vector<int> dist(N, INF);

void dijkstra(int s)
{
    priority_queue<pii> pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    while (!pq.empty())
    {
        pii f = pq.top();
        int n = f.second;
        visited[n] = true;
        pq.pop();

        for (pii v_pair : adj[n])
        {
            int v = v_pair.first;
            int w = v_pair.second;
            if (visited[n])
                continue;
            if (dist[v] > dist[n] + w)
            {
                dist[v] = dist[n] + w;
                pq.push({dist[v], v});
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
    }
    int s, d;
    cin >> s >> d;
    dijkstra(s);
    cout << dist[d];
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