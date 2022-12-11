#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1e5 + 5;

int n, m, a[inf], num[inf], sum[inf][25], dp[1 << 21];

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
        for (int j = 1; j <= m; j ++)
        {
            sum[i][j] = sum[i - 1][j];
        }
        num[a[i]] ++, sum[i][a[i]] ++;
    }
    memset (dp, 0x3f, sizeof (dp));
    dp[0] = 0;
    for (int i = 1; i < (1 << m); i ++)
    {
        int len = 0;
        for (int j = 1; j <= m; j ++)
        {
            if (i & (1 << (j - 1)))
            {
                len += num[j];
            }
        }
        for (int j = 1; j <= m; j ++)
        {
            if (i & (1 << (j - 1)))
            {
                dp[i] = min (dp[i], dp[i ^ (1 << (j - 1))] + num[j] - (sum[len][j] - sum[len - num[j]][j]));
            }
        }
    }
    printf ("%d\n", dp[(1 << m) - 1]);
    return 0;
}