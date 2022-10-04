#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 505;
const int zero = 4e5;

int n, iq[inf], eq[inf], dp[2 * zero + 5], ans;

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d", &iq[i], &eq[i]);
    }
    memset (dp, ~0x3f, sizeof (dp));
    dp[zero] = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (iq[i] >= 0)
        {
            for (int j = 2 * zero; j >= iq[i]; j --)
            {
                dp[j] = max (dp[j], dp[j - iq[i]] + eq[i]);
            }
        }
        else
        {
            for (int j = 0; j <= iq[i] + 2 * zero; j ++)
            {
                dp[j] = max (dp[j], dp[j - iq[i]] + eq[i]);
            }
        }
    }
    for (int i = zero; i <= 2 * zero; i ++)
    {
        if (dp[i] > 0)
        {
            ans = max (ans, dp[i] + i - zero);
        }
    }
    printf ("%d\n", ans);
    return 0;
}