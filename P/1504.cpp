#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 10005;
int dp[inf], sum[inf];
int n, a[inf], len, maxh, ans;
int main ()
{
    scanf ("%d", &n);
    for (int k = 1; k <= n; k ++)
    {
        len = 0, maxh = 0;
        while (++ len)
        {
            scanf ("%d", &a[len]);
            if (a[len] == -1)
            {
                len --;
                break;
            }
            maxh = maxh + a[len];
        }
        memset (dp, 0, sizeof (dp));
        dp[0] = 1;
        for (int i = 1; i <= len; i ++)
        {
            for (int j = maxh; j >= a[i]; j --)
            {
                if (dp[j - a[i]] == 1)
                {
                    dp[j] = 1;
                }
            }
        }
        for (int i = 0; i <= maxh; i ++)
        {
            if (dp[i] == 1)
            {
                sum[i] ++;
            }
        }
    }
    for (int i = 0; i < inf; i ++)
    {
        if (sum[i] == n)
        {
            ans = i;
        }
    }
    printf ("%d\n", ans);
    return 0;
}