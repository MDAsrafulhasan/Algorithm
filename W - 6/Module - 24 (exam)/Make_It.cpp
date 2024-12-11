// #include <bits/stdc++.h>
// using namespace std;

// bool knapsack(int s)
// {
//     if (s == 1)
//         return true;
//     if (s < 1)
//         return false;

//     if (s > 1)
//     {
//         if (s % 2 == 0)
//             return knapsack(s / 2);
//         else
//             return knapsack(s - 3);
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     for (int k = 0; k < t; k++)
//     {
//         int s;
//         cin >> s;
//         if (knapsack(s))
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
//     return 0;
// }







#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N];

bool knapsack(int s, int j)
{
    if (j == s)
        return true;
    if (j > s)
        return false;

    
    // if (dp[j] != -1)
    //     return dp[j];


    else
    {
        bool op1 = knapsack(s, j * 2);
        bool op2 = knapsack(s, j + 3);
        return dp[j] = op1 || op2;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int s;
        cin >> s;
        int j = 1;


        for (int i = 0; i < N; i++)
        {
            dp[i] = -1;
        }


        if (knapsack(s, j))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}











// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     for (int k = 0; k < t; k++)
//     {
//         int s;
//         cin >> s;
//         vector<bool> dp(s, false);
//         dp[1] = true;
//         for (int i = 2; i <= s; i++)
//         {
//             if (i * 2 == s)
//                 dp[i * 2] = true;
//             else  if (i + 3 == s)
//                 dp[i + 3] = true;
//         }
//         if (dp[s])
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }

//     return 0;
// }










// #include<bits/stdc++.h>
// using namespace std;

// bool knapsack(float s)
// {
//     if(s==1) return true;
//     if(s>1)
//     {
//         bool op1 = knapsack(s/2);
//         bool op2 = knapsack(s-3);
//         return op1 || op2;
//     }
//     else return false; 

// }
// int main()
// {
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++)
//     {
//         // int n=1;
//         float s;
//         cin>>s;
//         if(knapsack(s)==true) cout<<"YES"<<endl;
//         else
//         cout<<"NO"<<endl;

//     }
//     return 0;
// }