#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int N = 1e18 + 4;
    long long int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edge_list;
    while (m--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        edge_list.push_back({u, {v, w}});
    }
    long long int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = N;
    }

    long long int s;
    cin >> s;
    dis[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (pair<int, pair<int, int>> child : edge_list)
        {
            long long int u = child.first;
            long long int v = child.second.first;
            long long int w = child.second.second;
            if (dis[u] !=N && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
            }
        }
    }

    bool cycle = false;
    for (pair<int, pair<int, int>> child : edge_list)
    {
        long long int u = child.first;
        long long int v = child.second.first;
        long long int w = child.second.second;
        if (dis[u] !=N && dis[v] > dis[u] + w)
        {
            cycle = true;
            dis[v] = dis[u] + w;
        }
    }

    long long int x;
    cin >> x;
    while (x--)
    {
        int d;
        cin >> d;
        if (!cycle)
        {
            if (dis[d] == N)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }
    if (cycle)
        cout << "Negative Cycle Detected";

    return 0;
}




//(using Fload warshal algorithm)



// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     long long int N = 1e18+4;
//     long long int n, m;
//     cin >> n >> m;
//     long long int a[n + 1][n + 1];
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == j)
//                 a[i][j] = 0;
//             else
//                 a[i][j] = N;
//         }
//     }
//     while (m--)
//     {
//         long long int u, v, w;
//         cin >> u >> v >> w;
//         a[u][v] = w;

//     }

//     for (int k = 1; k <= n; k++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (a[i][j] > a[i][k] + a[k][j])
//                 {
//                     a[i][j] = a[i][k] + a[k][j];
//                 }
//             }
//         }
//     }

//     long long int isvalid = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == j)
//             {
//                 if (a[i][j] != 0)
//                 {
//                     isvalid++;
//                 }
//             }
//         }
//     }

//     // for (int i = 1; i <= n; i++)
//     // {
//     //     for (int j = 1; j <= n; j++)
//     //     {
//     //         if (a[i][j] == LONG_MAX)
//     //             cout << "x"
//     //                  << " ";
//     //         else
//     //             cout << a[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }

//     long long int s;
//     cin >> s;

//     long long int x;
//     cin >> x;
//     while (x--)
//     {
//         int d;
//         cin >> d;
//         if (isvalid == 0)
//         {
//             if (a[s][d] == N)
//                 cout << "Not Possible" << endl;
//             else
//                 cout << a[s][d] << endl;
//         }
//     }
//     if (isvalid != 0)
//         cout << "Negative Cycle Detected";

//     return 0;
// }