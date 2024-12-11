#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    vector<Edge> ans;
    DSU_set(n);
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), compare);

    for (Edge val : v)
    {
        int a = val.a;
        int b = val.b;
        int w = val.w;
        int leaderA = DSU_find(a);
        int leaderB = DSU_find(b);
        if (leaderA == leaderB)
            continue;
        ans.push_back(Edge(a, b, w));
        DSU_union(a, b);
    }
    for (Edge val : ans)
    {
        cout << val.a << " " << val.b << " " << val.w <<endl;
    }
    return 0;
}


/*
7 11
    1 2 5
    1 3 7
    3 2 9
    3 5 8
    5 6 5
    3 6 7
    2 4 6
    2 6 15
    4 6 8
    4 7 11
    6 7 9
*/
