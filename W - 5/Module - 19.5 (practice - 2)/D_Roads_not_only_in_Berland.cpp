#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
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
    int n;
    cin >> n;
    DSU_set(n);
    int x = 0;
    vector<int> v1;
    vector<int> v2;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = DSU_find(a);
        int leaderB = DSU_find(b);
        if (leaderA == leaderB)
        {
            x++;
            v1.push_back(a);
            v1.push_back(b);
        }
        else
        {
            DSU_union(a, b);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int leaderA = DSU_find(1);
        int leaderB = DSU_find(i);
        if (leaderA != leaderB)
        {
            v2.push_back(leaderA);
            v2.push_back(leaderB);
            DSU_union(leaderA, leaderB);
        }
    }

    if (x > 0)
    {
        cout << x << endl;
        int j=0,k=0;
        for (int i = 0; i < v1.size(); i += 2)
        {
            cout<<v1[j]<<" "<<v1[j+1]<<" ";
            j+=2;
            cout<<v2[k]<<" "<<v2[k+1]<<" ";
            k+=2;
            cout << endl;
        }
    }
    else
        cout << x;

    return 0;
}

/*
3 6 7 1 4 7 10 7
*/