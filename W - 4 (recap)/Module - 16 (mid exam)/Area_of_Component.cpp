#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1003;
const int M = 1003;
bool visited[N][M];
vector<pair<int, int>> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char a[N][M];
int maxi_dote = 0;

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    maxi_dote++;
    for (auto child : direc)
    {
        int i = si + child.first;
        int j = sj + child.second;
        if (isvalid(i, j) && !visited[i][j] && a[i][j] == '.')
        {
            dfs(i, j);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int mn = INT_MAX;
    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (!visited[i][j] && a[i][j] == '.')
            {
                cnt++;
                dfs(i, j);
                mn = min(mn, maxi_dote);
                maxi_dote = 0;
            }
        }
    }

    if (cnt > 0)
        cout << mn;
    else
        cout << "-1";

    return 0;
}