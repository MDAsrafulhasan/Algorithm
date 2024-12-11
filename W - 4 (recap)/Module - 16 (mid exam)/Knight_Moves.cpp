#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 104;
const int M = 104;
bool visited[N][M];
vector<pair<int, int>> direc = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
int level[N][M];
// int non_valid = 0;

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> pq;
    pq.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
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
            if (isvalid(i, j) && !visited[i][j])
            {
                visited[i][j] = true;
                pq.push({i, j});
                level[i][j] = level[pi][pj] + 1;
                // non_valid++;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        int a[n][m];
        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;

        bfs(ki, kj);

        // if (non_valid != 0)
        //     cout << level[qi][qj] << endl;
        // else
        //     cout << "-1" << endl;
        if(ki==qi && kj==qj) cout<<level[qi][qj]<<endl;
        else
        {
            if(level[qi][qj]>0) cout<<level[qi][qj]<<endl;
            else cout<<"-1"<<endl;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                visited[i][j] = false;
                level[i][j] = 0;
            }
        }
        // non_valid = 0;
    }
    return 0;
}