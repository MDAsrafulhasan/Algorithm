#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pii;
typedef pair<int, int> pi;
const int N = 1e5 + 4;
vector<pi> adj[N];
bool visited[N];
int n, m;

void prims_algo(int parent)
{
    vector<pii> edge_list;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, {parent, parent}});
    while (!pq.empty())
    {
        pii f = pq.top();
        pq.pop();
        int pU = f.second.first;
        int pV = f.second.second;
        int pW = f.first;
        if (visited[pV])
            continue;
        visited[pV] = true;
        edge_list.push_back({pU, {pV, pW}});

        for (pi child : adj[pV])
        {
            int v = child.first;
            int w = child.second;
            if (!visited[v])
            {
                pq.push({w, {pV, v}});
            }
        }
    }
    long long int sum = 0;
    edge_list.erase(edge_list.begin());
    for (pii val : edge_list)
    {
        sum += val.second.second;
    }

    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            x++;
    }

    if (x == 0)
        cout << sum;
    else
        cout << "-1";
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    prims_algo(1);
    return 0;
}