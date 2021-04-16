#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = 500005;

int n, h;
int dp[inf];
int p[inf], c[inf];

int main ()
{
    memset (dp, 0x3f, sizeof (dp));
    scanf ("%d%d", &n, &h);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d", &p[i], &c[i]);
    }
    // for (int i = 1; i <= n; i ++)
    // {
    //     for (int j = 0; j <= h; j ++)
    //     {
    //         if (dp[j - p[i]] + c[i] > dp[j])
    //         {
    //             dp[j] = dp[j - p[i]] + c[i];
    //         }
    //     }
    // } 
    dp[0] = 0;
    // dp[1] = 0;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = h; j >= 0; j --)
        // for (int j = 0; j <= T; j ++)
        {
            int nw = 0;
            for (int k = 0; k * p[i] <= j; k ++)
            {
                if (j - p[i] * k >= 0)
                    nw = min (nw, dp[j - p[i] * k] + c[i] * k);
            }
            dp[j] = min (dp[j], nw);
            // printf ("CASE i %d, j %d: dp[%d]=%d\n", i, j, j, dp[j]);
        }
    }
    int ans = 2147483647;
    for (int i = h; i < inf; i ++)
    {
        // ans = max (ans, dp[i]);
        if (dp[i] != 0) ans = min (ans, dp[i]);
    }
    printf ("%d\n", ans);
    return 0;
}