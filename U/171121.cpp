#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 15;
int n, m, dp[2 << inf];

int main ()
{
    memset (dp, 0x3f, sizeof (dp));
    for (int i = 0; i < (2 << inf); i ++) dp[i] = 214748364;
    scanf ("%d%d", &n, &m);
    dp[0] = 0;
    while (m --)
    {
        // for (int i = 1; i <= n; i ++)
        {
            int a, b, y;
            scanf ("%d%d", &a, &b);
            for (int j = 1; j <= b; j ++)
            {
                int t;
                scanf ("%d", &t);
                y |= (1 << (t - 1));
            }
            for (int j = 1 << n; j >= 0; j --)
            {
                dp[j | y] = dp[j] + a;
            }
        }
    }
    if (dp[(1<<n)-1] >= 214748364)
    {
        printf ("-1");
    }
    else
    {
        printf ("%d", dp[(1 << n) - 1]);
    }
    return 0;
}