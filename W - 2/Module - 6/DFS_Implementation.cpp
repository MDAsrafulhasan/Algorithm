#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true; // rule 1 - actions just after entering node u
    cout << "Visiting Node : " << u << endl;
    for (int v : adj[u])
    {
        if (visited[v]) // rule 2 - action bnefore entering a new neighbor
        {
            continue;
        }
        dfs(v);
        // rule 3 - action after exiting a neighbor
    }
    // rule 4 - action before exiting node u
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
        adj[v].push_back(u); // ei line tar jonno undirected graph hbe
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    dfs(1);

    cout << "Visiting arr" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " status : " << visited[i] << endl;
    }
    return 0;
}

/*
10
9
1 2
1 3
1 10
2 4
3 5
3 6
4 7
4 8
6 9
*/