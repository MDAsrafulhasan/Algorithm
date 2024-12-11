#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const ll N=1e5+4;
ll save[N];
ll fibonacci(ll n)
{
    if(n==0 || n==1) return 1;

    //memoization
    if(save[n]!=-1)
    {
        return save[n];
    }
    ll ans1=fibonacci(n-1);
    ll ans2=fibonacci(n-2);
    save[n]=ans1+ans2;
    return save[n];
}

int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        save[i]=-1;
    }
    cout<<fibonacci(n);
    return 0;
}
/*
100
*/