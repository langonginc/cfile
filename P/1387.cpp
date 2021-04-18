#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, a[105][105], dp[105][105], ans = -2147483646;

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            scanf ("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (a[i][j])
            {
                dp[i][j] = min (min (dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
            }
            ans = max (ans, dp[i][j]);
        }
    }
    printf ("%d\n", ans);
    return 0;
}