#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0, y = 0; i < s.size(); i++)
    {
        if (i == s.size() - 1)
        {
            cout << s[i];
        }
        else
        {
            if(y==2)
            {
                cout<<"-";
                y=0;
            }
            cout << s[i];
            y++;
        }
    }
    return 0;
}