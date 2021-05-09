#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 10005;

int n, k, m, dp[inf][inf], a[inf][inf];

int main ()
{
    scanf ("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; i ++)
    {
        int x, y;
        scanf ("%d%d", &x, &y);
        a[x][y] = 1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (!a[i][j])
            {
                dp[i][j] = max (dp[i][j], (dp[i - 1][j] + dp[i][j - 1]) % 10001) % 10001;
            }
        }
    }
    for (int i = 1; i <= m; i ++)
    {
        int x, y;
        scanf ("%d%d", &x, &y);
        if (a[x][y])
        {
            printf ("-1\n");
        }
        else
        {
            printf ("%d\n", dp[x][y]%10001);
        }
    }
    return 0;
}