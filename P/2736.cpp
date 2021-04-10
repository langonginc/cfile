#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 25;
int n, t, m;
int dp[inf][inf], d[inf];

int main ()
{
    scanf ("%d%d%d", &n, &t, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &d[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = m; j >= 1; j --)
        {
            // for (int k = t; k > 0; k --)
            for (int k = t; k >= d[i]; k --)
            {
                dp[j][k] = max (dp[j][k], max (dp[j - 1][t] + 1, dp[j][k - d[i]] + 1));
            }
        }
    }
    printf ("%d\n", dp[m][t]);
    return 0;
}