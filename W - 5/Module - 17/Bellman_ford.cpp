#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> list_0f_edge;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        list_0f_edge.push_back({u, {v, w}});
    }
    int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto child : list_0f_edge)
        {
            int u = child.first;
            int v = child.second.first;
            int w = child.second.second;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
    return 0;
}

/*
4 4
1 2 5
2 3 2
3 4 -2
1 4 10
*/
