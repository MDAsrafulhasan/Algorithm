#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> derec = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, 
                    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
const int N = 10;
bool visited[N][N];
int level[N][N];

bool isvalid(int i,int j)
{
    return (i>=0 && i<8 && j>=0 && j<8);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj]=true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pii f = q.front();
        int i = f.first;
        int j = f.second;
        q.pop();
        for (auto d : derec)
        {
            int ni=i+d.first;
            int nj=j+d.second;
            if(isvalid(ni,nj) && !(visited[ni][nj]))
            {
                q.push({ni,nj});
                visited[ni][nj]=true;
                level[ni][nj] = level [i][j]+1;
            }
        }
    }
}

void reset_level_visited()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main()
{
    int si, sj, ei, ej;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        si = x[0] - 'a';
        sj = x[1] - '1';
        ei = y[0] - 'a';
        ej = y[1] - '1';
        // cout<<si<<" "<<sj<<"    "<<ei<<" "<<ej<<endl;
        bfs(si, sj);
        cout << level[ei][ej]<<endl;
        reset_level_visited();
    }
    return 0;
}

/*
3
a1 h8
a1 c2
h8 c3
*/