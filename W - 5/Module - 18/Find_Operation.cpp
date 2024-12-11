#include<bits/stdc++.h>
using namespace std;
int perent[8]={-1,-1,1,1,6,4,-1,-1};
int find(int n)
{
    while(perent[n]!=-1)
    {
        n=perent[n];
    }
    return n;
}
int main()
{
    int n;
    cin>>n;
    cout<<find(4);
    return 0;
}
/*
7 4
1 2
2 3
4 5
6 5
*/