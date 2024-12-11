// Count_SubsetSum_with_Given_Difference   and   target_sum   2 tai same 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    int dif;
    cin>>dif;

    if((dif+s)%2==0)
    {
        s= (dif+s)/2;
        int dp[n+1][s+1];
        dp[0][0]=1;
        for(int j=1;j<=s;j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(a[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
                }
                else
                dp[i][j]=dp[i-1][j];
                
            }
        }

        cout<<dp[n][s];

    }
    else
    cout<<"0";
    return 0;
}

/*
4
1 1 2 3
1
*/