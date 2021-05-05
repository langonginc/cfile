#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, a[1005][1005], dp[1005][1005], ans;

int main ()
{
    scanf ("%d%d", &n, &m);
    memset (a, 0x3f, sizeof (a));
    for (int i = 1; i <= m; i ++)
    {
        int x, y;
        scanf ("%d%d", &x, &y);
        a[x][y] = 0;
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (a[i][j] != 0)
            {
                dp[i][j] = min (dp[i - 1][j - 1], min (dp[i][j - 1], dp[i - 1][j])) + 1;
            }
            ans = max (ans, dp[i][j]);
        }
    }
    printf ("%d", ans);
    return 0;
}