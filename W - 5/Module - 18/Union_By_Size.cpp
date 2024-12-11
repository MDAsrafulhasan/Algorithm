#include <bits/stdc++.h>
using namespace std;

const int N=1e5+3;
int perent[N];
int perent_size[N];

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
        if (perent_size[LeaderA] > perent_size[LeaderB])
        {
            //leader A;
            perent[LeaderB] = LeaderA;
            perent_size[LeaderA] += perent_size[LeaderB];
        }
        else
        {
            perent[LeaderA] = LeaderB;
            perent_size[LeaderB] += perent_size[LeaderA];
        }
    }
}
void DSU_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        perent[i] = -1;
        perent_size[i] = 1;
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
        DSU_union(u, v);
    }

    cout << DSU_find(4) << endl;

    return 0;
}
/*
7 4
1 2
2 3
4 5
6 5
*/