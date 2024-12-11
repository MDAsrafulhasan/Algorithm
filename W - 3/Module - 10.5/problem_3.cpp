#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 1;
vector<string> mat;
bool visited[N][N];
int level[N][N];
vector<pii> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

bool isvalid(int i, int j)
{
    return (i > 0 && i < n && j > 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    level[si][sj] = 0;
    visited[si][sj] = true;
    while (!q.empty())
    {
        pii f = q.front();
        q.pop();
        int i = f.first;
        int j = f.second;
        for (auto d : direc)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (isvalid(ni, nj) && !(visited[ni][nj]) && mat[ni][nj] != 'x')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        mat.push_back(x);
    }
    int si, sj, ei, ej;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 's')
                si = i, sj = j;
            if (mat[i][j] == 'e')
                ei = i, ej = j;
        }
    }
    // cout << si << " " << sj << " " << ei << " " << ej;

    bfs(si, sj);
    if(level[ei][ej]!=0) cout<<"YES";
    else
    cout<<"NO";
    return 0;
}