
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int inf = 5005;

// int h, n;
// int s[inf], t[inf];
// int dp[inf][inf];
// int pos[2][inf];

// int abs (int x)
// {
//     if (x > 0)
//     {
//         return x;
//     }
//     return -x;
// }

// int main ()
// {
//     scanf ("%d%d", &n, &h);
//     memset (dp, 0x3f, sizeof(dp));
//     for (int i = 1; i <= n; i ++)
//     {
//         scanf ("%d%d", &s[i], &t[i]);
//     }
//     dp[1][t[2]] = 0;
//     dp[2][t[1]] = 0;

// /*

// dp[1][*] = max{dp[2][*] + abs(* - s[i]) + abs(t[i] - s[i])}

// */

//     // for (int i = 1; i <= h; i ++)
//     // {
//     //     dp[1][i] = 0, dp[2][i] = 0;
//     // }
//     for (int i = 3; i <= n; i ++)
//     {
//         for (int j = h; j >= 1; j --)
//         {
//             int t1 = inf * inf;
//             int t2 = inf * inf;
//             // for (int k = 1; k <= h; k ++)
//             {
//                 t1 = min (t1, dp[2][t[i - 1]] + abs(t[i - 1] - s[i]) + abs(t[i] - s[i]));
//                 t2 = min (t2, dp[1][t[i - 1]] + abs(t[i - 1] - s[i]) + abs(t[i] - s[i]));
//             }
//             for (int k = 1; k <= h; k ++)
//             {
//                 dp[1][k] = min (dp[1][k], t1);
//                 dp[2][k] = min (dp[2][k], t2);
//                 // dp[1][k] = t1;
//                 // dp[2][k] = t2;
//             }
//         }
//     }
//     int ans = inf * inf;
//     for (int i = 1; i <= h; i ++)
//     {
//         if (dp[1][i] != 0)
//         {
//             ans = min (ans, dp[1][i]);
//         }
//         if (dp[2][i] != 0)
//         {
//             ans = min (ans, dp[2][i]);
//         }
//     }
//     printf ("%d\n", ans);
//     return 0;
// }

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 5005;

int h, n;
int s[inf], t[inf];
int dp[inf][3][inf];
int mh;

int abs (int x)
{
    if (x > 0)
    {
        return x;
    }
    return -x;
}

int main ()
{
    scanf ("%d%d", &n, &h);
    memset (dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d", &s[i], &t[i]);
        mh = max (mh, max (s[i], t[i]));
    }

/*

dp[1][*] = max{dp[2][*] + abs(* - s[i]) + abs(t[i] - s[i])}

*/

    for (int i = 1; i <= mh; i ++)
    {
        dp[1][0][i] = 0;
    }
    for (int i = 2; i <= n; i ++)
    {
        for (int k = 0; k < 2; k ++)
        {
            for (int j = 1; j <= mh; j ++)
            {
                dp[i][k][j] = dp[i - 1][k][t[i-1]] + abs(t[i - 1] - s[i]) + abs(t[i] - s[i]);
            }
            for (int j = 1; j <= mh; j ++)
            {
                dp[i][1 - k][t[i - 1]] = dp[i - 1][k][t[i - 1]] + abs(j - s[i]) + abs(t[i] - s[i]);
            }
        }
    }
    int ans = inf * inf;
    for (int i = 1; i <= h; i ++)
    {
        ans = min (ans, dp[n][1][i]);
        ans = min (ans, dp[n][0][i]);
    }
    printf ("%d\n", ans);
    return 0;
}