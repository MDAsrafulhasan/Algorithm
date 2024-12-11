#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();

    // cout<<n;

    int x=0;
    bool ans =false;
    for(char c:b)
    {
        if(x==a.size())
        {
            ans =true;
            break;
        }
        if(c==a[x])
        {
            x++;
        }
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO";
    return 0;
}
/*
axe
bkazkxjkel
*/