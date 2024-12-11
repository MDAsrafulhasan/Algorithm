#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int parent[N];
int parent_size[N];

int DSU_find(int a)
{
    while (parent[a] != -1)
    {
        a = parent[a];
    }
    return a;
}

void DSU_union(int a, int b)
{
    int LeaderA = DSU_find(a);
    int LeaderB = DSU_find(b);
    if (LeaderA != LeaderB)
    {
        if (parent_size[LeaderA] >= parent_size[LeaderB])
        {
            // leader A;
            parent[LeaderB] = LeaderA;
            parent_size[LeaderA] += parent_size[LeaderB];
        }
        else if (parent_size[LeaderA] < parent_size[LeaderB])
        {
            parent[LeaderA] = LeaderB;
            parent_size[LeaderB] += parent_size[LeaderA];
        }
    }
}

void DSU_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parent_size[i] = 1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    DSU_set(n);
    int x=0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        int leaderA=DSU_find(u);
        int leaderB=DSU_find(v);
        if(leaderA!=leaderB)
        {
            DSU_union(u,v);
        }
        else
        {
            x++;
        }
    }
    cout<<x;
    return 0;
}