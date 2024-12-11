#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;
vector<string> a;
bool visited[N][N];
int level[N][N];
pii perent[N][N];
vector<pii> derec = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
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
        for (auto d : derec)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (isvalid(ni, nj) && !(visited[ni][nj]) && a[ni][nj] != '#')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                perent[ni][nj] = {i, j};
            }
        }
    }
}

int main()
{
    int si, sj, ei, ej;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
                si = i, sj = j;
            if (a[i][j] == 'B')
                ei = i, ej = j;
        }
    }

    bfs(si, sj);
    if (level[ei][ej] > 0)
    {
        cout << "YES" << endl
             << level[ei][ej] << endl;
    }
    else
        cout << "NO";

    vector<pii> path;
    pii curr = {ei, ej};

    while (!(curr.first == si && curr.second == sj))
    {
        path.push_back(curr);
        curr = perent[curr.first][curr.second];
    }
    path.push_back({si, sj});
    reverse(path.begin(), path.end());

    // for (auto p : path)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }

    for (int i = 1; i < path.size(); i++)
    {
        if (path[i - 1].first == path[i].first)
        {
            // dam , bam
            if (path[i - 1].second == path[i].second - 1)
                cout << 'R';
            else
                cout << 'L';
        }
        else
        {
            // upor , niche
            if (path[i - 1].first == path[i].first - 1)
                cout << 'D';
            else
                cout << 'U';
        }
    }

    return 0;
}

/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/