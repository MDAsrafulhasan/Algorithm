#include<bits/stdc++.h>
using namespace std;

const int n=1e3+5;
vector<int> adj[n];
bool visited[n];

void bfs(int per)
{
    queue<int> q;
    q.push(per);
    visited[per]=true;

    stack<int> st;
    while(!q.empty())
    {
        int f= q.front();
        q.pop();
        st.push(f);

        for(int child: adj[f])
        {
            if(visited[child]) continue;
            q.push(child);
            visited[child]=true;
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
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
        adj[u].push_back(v);
    }

    bfs(1);
    return 0;
}

/*
4 
4
1 2
3 4
1 3
2 4
*/