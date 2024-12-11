#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> adj[N];
bool visited[N];
int level[N];
int perent[N];

void bfs(int per)
{
    queue<int> q;
    q.push(per);
    visited[per]=true;
    perent[per]=-1;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int child:adj[f])
        {
            if(visited[child]) continue;
            visited[child]=true;
            q.push(child);
            level[child] = level[f] +1;
            perent[child]=f;
        }
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    cout<<level[n]<<endl;

    vector<int> path;
    int curr = n;
    while(curr!=-1)
    {
        path.push_back(curr);
        curr = perent[curr];
    }
    reverse(path.begin(),path.end());
    for(int val:path) cout<<val<<" ";
    return 0;
}

/*
5 5
1 2
1 3
1 4
2 3
5 4
*/