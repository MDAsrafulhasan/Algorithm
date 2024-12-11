#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 4;
vector<pii> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<string> mat;
bool visited[N][N];
int level[N][N];
pii perent[N][N];
int n, m;

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pii f = q.front();
        int i = f.first;
        int j = f.second;
        q.pop();
        for (auto d : direc)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (isvalid(ni, nj) && !(visited[ni][nj]) && mat[ni][nj] != 'x')
            {
                q.push({ni, nj});
                level[ni][nj] = level[i][j] + 1;
                perent[ni][nj] = {i, j};
                visited[ni][nj] = true;
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

    bfs(si, sj);

    if (level[ei][ej] == 0)

        cout << "-1" << endl;
    else
    {
        cout << level[ei][ej] << endl;

        vector<pii> path;
        pii curr = {ei, ej};
        while (!(curr.first == si && curr.second == sj))
        {
            path.push_back(curr);
            curr = perent[curr.first][curr.second];
        }
        path.push_back({si, sj});
        reverse(path.begin(), path.end());

        for (int i = 1; i < path.size(); i++)
        {
            if (path[i - 1].first == path[i].first)
            {
                // Right or Left
                if (path[i - 1].second == path[i].second - 1)
                    cout << "R";
                else
                    cout << "L";
            }
            else
            {
                // Up or down
                if (path[i - 1].first == path[i].first - 1)
                    cout << "D";
                else
                    cout << "U";
            }
        }
    }

    return 0;
}

/*
6 5
.s.x.
...x.
..x..
..x..
..xex
.....
*/