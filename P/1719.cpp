#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 150;
ll n, dp[inf][inf], pre[inf][inf], ans;

int main ()
{
    scanf ("%lld", &n);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            ll x;
            scanf ("%lld", &x);
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + x;
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            for (int p = 0; p < i; p ++)
            {
                for (int q = 0; q < j; q ++)
                {
                    ans = max (ans, pre[i][j] - pre[p][j] - pre[i][q] + pre[p][q]);
                }
            }
        }
    }
    printf ("%lld\n", ans);
    return 0;
}