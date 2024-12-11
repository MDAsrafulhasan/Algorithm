#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
vector<pair<int, int>> adj[N];
bool visited[N];

void prims_algo(int perent)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {perent, perent}});
    int cnt = 0;
    vector<pair<int, pair<int, int>>> ans;
    while (!pq.empty())
    {
        pair<int, pair<int, int>> f = pq.top();
        pq.pop();
        int u = f.second.first;
        int v = f.second.second;
        int w = f.first;
        if (visited[v])
            continue;
        visited[v] = true;
        cnt++;
        ans.push_back({u,{v,w}});
        for (pair<int, int> child : adj[v])
        {
            int node = child.first;
            int weight = child.second;
            if(!visited[node])
            {
                pq.push({weight,{v,node}});
            }
        }
    }
    ans.erase(ans.begin());

    long long int sum=0;

    for(pair<int, pair<int, int>> val:ans)
    {
        sum+=val.second.second;
    }
    cout<<sum;
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
        adj[v].push_back({u, w});
    }
    prims_algo(1);
    return 0;
}