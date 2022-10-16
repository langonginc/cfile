//
// Created by Jiayi Wu on 10/16/22.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 105;
const ll moder = 998244353;

ll C[inf][inf], f[125][inf][inf][125];
ll n, m, k, v[inf];

void init_C ()
{
    int i, j;
    for (i = 0; i < inf; ++ i)
    {
        C[i][i] = 1;
        C[i][0] = 1;
    }
    for (i = 1; i < inf; ++ i)
    {
        for (j = 1; j <= i; ++ j)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % moder;
        }
    }
}

ll fastPow (ll x, ll y)
{
    ll r = 1, base = x % moder;
    while (y)
    {
        if (y & 1)
        {
            r = (r * base) % moder;
        }
        base = (base * base) % moder, y >>= 1;
    }
    return r % moder;
}

inline ll count1 (ll x)
{
    ll ans = 0;
    while (x)
    {
        if (x & 1)
        {
            ans ++;
        }
        x >>= 1;
    }
    return ans;
}

int main ()
{
    init_C();
    scanf ("%lld%lld%lld", &n, &m, &k);
    for (int i = 0; i <= m; i ++)
    {
        scanf ("%lld", &v[i]);
    }
    for (int i = 0; i <= n; i ++)
    {
        f[0][i][n - i][0] = (fastPow (v[0], n - i) * C[n][i]) % moder;
    }
    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j <= n; j ++)
        {
            for (int t = 0; t <= n; t ++)
            {
                for (int l = 0; l <= k; l ++)
                {
                    for (int r = 0; r <= j; r ++)
                    {
                        f[i + 1][j - r][(t >> 1) + r][l + (t & 1)] = f[i + 1][j - r][(t >> 1) + r][l + (t & 1)] + f[i][j][t][l] * C[j][r] * fastPow (v[i + 1], r) % moder;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (ll t = 0; t <= n; t ++)
    {
        for (int l = 0; l <= k; l ++)
        {
            if (count1 (t) + l <= k)
            {
                ans = (ans + f[m][0][t][l]) % moder;
            }
        }
    }
    printf ("%lld\n", ans % moder);
    return 0;
}