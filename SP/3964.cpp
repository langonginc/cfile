#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 50005;

int dp[inf];
int w[inf], v[inf];
int n, m, d, money;

int main ()
{
    scanf ("%d", &m);
    while (m --)
    {
        memset (dp, 0, sizeof(dp));
        scanf ("%d%d%d", &money, &n, &d);
        for (int i = 1; i <= d; i ++)
        {
            scanf ("%d%d", &w[i], &v[i]);
        }
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= d; j ++)
            {
                for (int k = w[j]; k <= money; k = k + 1000)
                {
                    dp[k/1000] = max (dp[k / 1000], dp[(k - w[j]) / 1000] + v[j]);
                }
            }
            money += dp[money / 1000];
        }
        printf ("%d\n", money);
    }
    return 0;
}