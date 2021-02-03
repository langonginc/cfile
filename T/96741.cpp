#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
using namespace std;
const int inf = 505;

#define debug

int dp[inf][inf];
int n, a[inf];

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    memset (dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i ++)
    {
        dp[i][i] = 1;
    }
    for (int i = 1; i < n; i ++)
    {
        if (a[i] == a[i + 1])
        {
            dp[i][i + 1] = 1;
        }
        else
        {
            dp[i][i + 1] = 2;
        }
    }
    for (int len = 3; len <= n; len ++)
    {
        for (int i = n; i > 0; i --)
        {
            int j = i + len - 1;
            if (j <= n)
            {
                int tmp = INT_MAX;
                int pos = 0;
                bool tt = false;
                for (int k = i; k < j; k ++)
                {
                    // tmp = min(tmp, dp[i][k] + dp[k + 1][j]);
                    if (tmp > dp[i][k] + dp[k + 1][j])
                    {
                        tmp = dp[i][k] + dp[k + 1][j];
                        pos = k;
                    }
                }
                if (a[i] == a[j])
                {
                    // tmp = min(tmp, dp[i + 1][j - 1]);
                    if (tmp > dp[i + 1][j - 1])
                    {
                        tmp = dp[i + 1][j - 1];
                        tt = true;
                    }
                }
                dp[i][j] = tmp;
                #ifdef debug
                printf ("[DP] %d,%d value: %d. ", i, j, tmp);
                if (tt) printf ("回文\n");
                else printf ("RUN at %d\n", pos);
                #endif
            }
        }
    }
    printf ("%d\n", dp[1][n]);
    return 0;
}
