#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    int l=0;
    int r=n-1;
    int count=0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid]==x)
        {
            count++;
            if(x==a[mid-1])
            {
                count++;
            }
            if(x==a[mid+1])
            {
                count++;
            }
            break;
        }
        else if(a[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    if(count>1) cout<<"YES";
    else cout<<"NO";

    return 0;
}