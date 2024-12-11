#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<string> a;
bool visited[N][N];
int n, m;

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int i, int j)
{
    if (visited[i][j])
        return;
    if (!isvalid(i, j))
        return;
    if (a[i][j] == '#')
        return;

    visited[i][j] = true;

    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        a.push_back(x);
    }

    int cc = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                continue;
            if (a[i][j] == '#')
                continue;
            dfs(i, j);
            cc++;
        }
    }
    cout << cc << endl;

    return 0;
}

/*
5 8
########
#..#...#
####.#.#
#..#...#
########*/