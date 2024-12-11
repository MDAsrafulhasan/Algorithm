#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a1[n+1];
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }

    int m;
    cin >> m;
    int a2[m+1];
    for (int i = 0; i < m; i++)
    {
        cin >> a2[i];
    }

    int s=n+m;
    int arr[s]; // main array

    a1[n] = INT_MIN;
    a2[m] = INT_MIN;
    int a1_indx = 0, a2_indx = 0;
    for (int i = 0; i < s; i++)
    {
        if (a1[a1_indx] > a2[a2_indx])
        {
            arr[i] = a1[a1_indx];
            a1_indx++;
        }
        else
        {
            arr[i] = a2[a2_indx];
            a2_indx++;
        }
    }

    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}