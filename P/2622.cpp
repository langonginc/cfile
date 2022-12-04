#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
const int INF = INT_MAX - 5;

int n, m, a[1005][105], dp[1 << 11];

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            scanf ("%d", &a[i][j]);
        }
    }

    for (int i = 0; i <= (1 << n); i ++)
    {
        dp[i] = INF;
    }
    dp[(1 << n) - 1] = 0;

    for (int i = (1 << n) - 1; i >= 0; i --)
    {
        for (int j = 1; j <= m; j ++)
        {
            int r = i;
            for (int k = 1; k <= n; k ++)
            {
                if (a[j][k] == 1 && (i & (1 << (k - 1))))
                {
                    r ^= (1 << (k - 1));
                } 
                if (a[j][k] == -1 && ! (i & (1 << (k - 1))))
                {
                    r ^= (1 << (k - 1));
                }
            }
            dp[r] = min (dp[r], dp[i] + 1);
        }
    }
    printf ("%d\n", dp[0] == INF ? -1 : dp[0]);
    return 0;
}