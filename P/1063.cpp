#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 405;
int n, a[inf], dp[inf][inf];

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
        a[i + n] = a[i];
    }
    a[0] = a[n], a[2 * n + 1] = a[1];
    // for (int i = 0; i <= n; i ++)
    // {
    //     dp[i][i + 1] = 1;
    //     // dp[i][i] = a[i];
    // }
    for (int i = 1; i < n; i ++)
    {
        for (int s = 1; s <= n; s ++)
        {
            for (int k = s + 1; k <= s + i; k ++)
            {
                dp[s][s + i] = max (dp[s][s + i], a[s] * a[k] * a[s + i + 1]);
                // printf ("%d %d: %d\n", s, s + i, dp[s][s + i]);
            }
        }
    }
    // for (int i = 1; i <= n; i ++)
    // {
    //     for (int j = 1; j <= 2 * n; j ++)
    //     {
    //         printf ("%d ", dp[i][j]);
    //     }
    //     printf ("\n");
    // }
    int ans = 0, row = 0;
    for (int i = 1; i <= n; i ++)
    {
        row = 0;
        for (int j = 1; j <= 2 * n; j ++)
        {
            row += dp[i][j];
        }
        ans = max (ans, row);
    }
    printf ("%d\n", ans);
    return 0;
}