#include <bits/stdc++.h>
using namespace std;
int perent[1000];

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
        perent[LeaderB] = LeaderA;
    }
}
void DSU_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        perent[i] = -1;
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

    cout << DSU_find(5) << endl;

    return 0;
}

/*
7 4
1 2
2 3
4 5
6 5
*/