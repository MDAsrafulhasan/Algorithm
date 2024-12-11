#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ar[n][n];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ar[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << ":" << " ";
        
        for (int j = 1; j <= n; j++)
        {
            if (ar[i][j] == 1)
               cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
1st one-
4
0 0 0 1
1 0 0 1
1 1 0 0
0 0 1 0

2nd one-
5
0 0 0 0 0
1 0 0 1 1
1 1 0 1 1
1 1 1 0 0
0 0 1 0 0

*/