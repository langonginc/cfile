#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int dp[105][105], a[105];

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 0; j <= a[i]; j ++)
        {
            for (int k = 0; k <= m - j; k ++)
            {
                if (j == 0 && k == 0)
                {
                    continue;
                }
                else
                {
                    dp[i][j + k] = (dp[i][j + k] + dp[i - 1][k]) % 1000007;
                }
            }
        }
    }
    printf ("%d\n", dp[n][m] % 1000007);
    return 0;
}