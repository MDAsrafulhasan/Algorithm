#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1001;
const int M = 1001;
bool visited[N][M];
vector<pair<int, int>> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int level[N][M];
char a[N][M];

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> pq;
    pq.push({si, sj});
    visited[si][sj] = true;
    level[si][sj]=1;
    while (!pq.empty())
    {
        pair<int, int> perent = pq.front();
        int pi = perent.first;
        int pj = perent.second;
        pq.pop();
        for (auto child : direc)
        {
            int i = child.first + pi;
            int j = child.second + pj;
            if (isvalid(i, j) && !visited[i][j] && a[i][j] == '.')
            {
                visited[i][j] = true;
                pq.push({i, j});
                level[i][j] = level[pi][pj] + 1;
            }
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

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    bfs(si, sj);

    if (level[di][dj] > 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}