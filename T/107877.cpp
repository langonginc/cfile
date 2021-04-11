#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 5005;

int h, n;
int s[inf], t[inf];
int dp[inf][inf];
int pos[2][inf];

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
    }
    dp[1][t[2]] = 0;
    dp[2][t[1]] = 0;

/*

dp[1][*] = max{dp[2][*] + abs(* - s[i]) + abs(t[i] - s[i])}

*/

    // for (int i = 1; i <= h; i ++)
    // {
    //     dp[1][i] = 0, dp[2][i] = 0;
    // }
    for (int i = 3; i <= n; i ++)
    {
        for (int j = h; j >= 1; j --)
        {
            int t1 = inf * inf;
            int t2 = inf * inf;
            for (int k = 1; k <= h; k ++)
            {
                t1 = min (t1, dp[2][k] + abs(k - s[i]) + abs(t[i] - s[i]));
                t2 = min (t2, dp[1][k] + abs(k - s[i]) + abs(t[i] - s[i]));
            }
            for (int k = 1; k <= h; k ++)
            {
                dp[1][k] = min (dp[1][k], t1);
                dp[2][k] = min (dp[2][k], t2);
                // dp[1][k] = t1;
                // dp[2][k] = t2;
            }
        }
    }
    int ans = inf * inf;
    for (int i = 1; i <= h; i ++)
    {
        if (dp[1][i] != 0)
        {
            ans = min (ans, dp[1][i]);
        }
        if (dp[2][i] != 0)
        {
            ans = min (ans, dp[2][i]);
        }
    }
    printf ("%d\n", ans);
    return 0;
}