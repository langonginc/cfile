#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[205][205], dp[205][205];
int n, m;

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            scanf ("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            dp[i][j] = max(dp[i - 1][j], max (dp[i - 1][j - 1], dp[i - 1][j + 1])) + a[i][j];
        }
    }
    printf ("%d", max(dp[n][m / 2 + 1], max(dp[n][m / 2], dp[n][m / 2 + 2])));
    return 0;
}