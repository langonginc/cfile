#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;

ll dp[10000007];
ll k[105], c[105];

int main ()
{
    int n, m;
    scanf ("%d%d", &n ,&m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &k[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &c[i]);
    }
    dp[0] = 1;
    ll ans = -1, all = 0;
    for (int i = 1; i <= n; i ++)
    {
        all += k[i] * c[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        for (ll j = all; j >= 0; j --)
        {
            for (ll l = 1; l <= k[i] && j >= l * c[i]; l ++)
            {
                dp[j] = max(dp[j], dp[j - l * c[i]] * l);
                if (dp[j] >= m)
                {
                    ans = j, all = j - 1;
                }
            }
        }
    }
    printf ("%lld\n", ans);
    return 0;
}
