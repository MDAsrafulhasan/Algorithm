#include <bits/stdc++.h>
using namespace std;

int perent[1000];
int perent_level[1000];

int DSU_find(int a)
{
    while (perent[a] != -1)
    {
        a = perent[a];
    }
    return a;
}
void DSU_union(int a, int b)
{
    int LeaderA = DSU_find(a);
    int LeaderB = DSU_find(b);
    if (LeaderA != LeaderB)
    {
        if (perent_level[LeaderA] > perent_level[LeaderB])
        {
            // leader A;
            perent[LeaderB] = LeaderA;
        }
        else if (perent_level[LeaderA] < perent_level[LeaderB])
        {
            // leader B
            perent[LeaderA] = LeaderB;
        }
        else
        {
            perent[LeaderB] = LeaderA;
            perent_level[LeaderA]++;
        }
    }
}
void DSU_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        perent[i] = -1;
        perent_level[i] = 0;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    DSU_set(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        int LeaderA = DSU_find(u);
        int LeaderB = DSU_find(v);
        if (LeaderA == LeaderB)
        {
            cout << "cycle ditected in " << u << " " << v;
        }
        else
            DSU_union(u, v);
    }

    return 0;
}
/*
5 5
1 2
2 5
1 4
4 5
2 3
*/