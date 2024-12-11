#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
bool visited[N];
vector<pair<int, int>> a[N];
long long int d[N];

void bfs(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    d[s] = 0;
    while (!pq.empty())
    {
        pair<int, int> perent = pq.top();
        int pn = perent.second;
        pq.pop();
        if (visited[pn])
            continue;
        visited[pn] = true;
        for (auto child : a[pn])
        {
            int n = child.first;
            int w = child.second;
            if (d[n] > d[pn] + w)
            {
                d[n] = d[pn] + w;
                pq.push({d[n], n});
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
        a[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = INT_MAX;
    }

    int s;
    cin >> s;
    bfs(s);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int dw, c;
        cin >> dw >> c;
        if (d[dw] <= c)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}