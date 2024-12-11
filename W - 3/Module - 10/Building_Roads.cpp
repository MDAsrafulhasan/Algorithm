#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int> adj[N];
bool visited[N];

void dfs(int per)
{
    visited[per]=true;
    for(int child : adj[per])
    {
        if(visited[child]) continue;
        dfs(child);
    }
}

int main()
{
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cc=0;
    vector<int> leader_node;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;
        leader_node.push_back(i);
        dfs(i);
        cc++;
    }
    cout<<cc-1<<endl;
    for(int i=1;i<leader_node.size();i++)
    {
        cout<<leader_node[i-1]<<" "<<leader_node[i]<<endl;
    }
    return 0;
}

/*
4 2
1 2
3 4
*/