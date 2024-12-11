#include <bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int u;
    int v;
    int w;
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> ve;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge ed(u,v,w);
        ve.push_back(ed);
    }

    int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        // for (int j=0;j<ve.size();j++)
        for(Edge child:ve)
        {
            // Edge child=ve[j];
            int u = child.u;
            int v = child.v;
            int w = child.w;
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