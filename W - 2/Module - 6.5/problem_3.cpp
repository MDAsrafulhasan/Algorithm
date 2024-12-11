#include<bits/stdc++.h>
using namespace std;
const int n=1e3+5;
vector<int> adj[n];

const int x=3;
int ar[x][x];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        ar[u][v]=1;
    }

    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=x;j++)
        {
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}
/*
3
5
1 2
2 3
1 3
3 1
3 2
*/