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
            //leader A;
            perent[LeaderB] = LeaderA;
        }
        else if(perent_level[LeaderA] < perent_level[LeaderB])
        {
            //leader B
            perent[LeaderA] = LeaderB;
        }
        else
        {
            perent[LeaderB]= LeaderA;
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
        DSU_union(u, v);
    }

    cout << DSU_find(2) << endl;

    return 0;
}
/*
7 4
1 2
2 3
4 5
6 5
*/