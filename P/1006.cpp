#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 55;

int n, m, dp[inf][inf][inf][inf], a[inf][inf];

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
            for (int k = i + 1; k <= n; k ++)
            // for (int k = 1; k <= n; k ++)
            {
                for (int l = 1; l < j; l ++)
                // for (int l = 1; l <= m; l ++)
                {
                    dp[i][j][k][l] = a[i][j] + a[k][l] + max (
                        max (
                            dp[i][j - 1][k][l - 1],
                            dp[i][j - 1][k - 1][l]
                        ),
                        max (
                            dp[i - 1][j][k][l - 1],
                            dp[i - 1][j][k - 1][l]
                        )
                    );
                }
            }
        }
    }
    printf ("%d\n", dp[n - 1][m][n][m - 1]);
    // printf ("%d\n", dp[n ][m][n][m]);
    return 0;
}