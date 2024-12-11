#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int>>> list_of_adge;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        list_of_adge.push_back({u, {v, w}});
    }
    int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[1]=0;

    for (int k = 1; k <= n - 1; k++)
    {
        for (auto child : list_of_adge)
        {
            int u = child.first;
            int v = child.second.first;
            int w = child.second.second;
            if (dis[u]<INT_MAX && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(dis[i]==INT_MAX) cout<<"30000"<<" ";
        else
        cout<<dis[i]<<" ";
    }
    return 0;
}