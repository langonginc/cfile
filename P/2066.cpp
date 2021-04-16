#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 20;
int n, m, a[inf][inf], dp[inf][inf], ans[inf][inf][inf];

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
        for (int j = 0; j <= m; j ++)
        {
            for (int k = j; k >= 0; k --)
            {
                if (dp[i][j] < dp[i - 1][j - k] + a[i][k])
                {
                    dp[i][j] = dp[i - 1][j - k] + a[i][k];
                    for (int l = 1; l <= i - 1; l ++)
                    {
                        ans[i][j][l] = ans[i - 1][j - k][l];
                    }
                    ans[i][j][i] = k;
                }
            }
        }
    }
    printf ("%d\n", dp[n][m]);
    for (int i = 1; i <= n; i ++)
    {
        printf ("%d %d\n", i, ans[n][m][i]);
    }
    return 0;
}