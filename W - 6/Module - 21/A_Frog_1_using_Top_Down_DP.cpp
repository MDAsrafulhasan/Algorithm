#include<bits/stdc++.h>
using namespace std;

const int N=1e5+3;
int dp[N];

int solve(int a[],int n)
{
    if(n==1)
    {
        return 0;
    }
    else if(dp[n]!=-1)
    {
        return dp[n];
    }
    else if(n==2)
    {
        dp[n]=abs(a[2]-a[1]);
        return dp[n];     // ( return dp[n]=abs(a[2]-a[1]); ) ekhane bojhay dp[n] e save kore return kore disde 
    }
    else
    {
        int choice_1 = solve(a,n-1)+abs(a[n]-a[n-1]);
        int choice_2 = solve(a,n-2)+abs(a[n]-a[n-2]);
        dp[n]=min(choice_1,choice_2);
        return dp[n];
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        dp[i]=-1;
        cin>>a[i];
    }
    cout<<solve(a,n);

    return 0;
}