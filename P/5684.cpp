#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 2005;
const ll MOD = 1e9 + 7;

ll fact(ll x)
{
    ll ans = 1;
    for (ll i = 2; i <= x; i ++)
    {
        ans = (ans * i) % MOD;
    }
    return ans % MOD;
}

ll A(ll m, ll n)
{
    ll ans = 1;
    for (ll i = m - n + 1; i <= m; i ++)
    {
        ans = (ans * i) % MOD;
    }
    return ans % MOD;
}

ll n, a[30];

int main ()
{
    string str;
    cin >> n >> str;
    ll sum = fact(n) % MOD;
    for (int i = 0; i < n; i ++)
    {
        a[str[i] - 'a'] ++;
    }
    ll count = 0;
    for (int i = 0; i < 26; i ++)
    {
        if (a[i] & 1)
        {
            count ++;
        }
    }
    if (count >= 2)
    {
        printf ("%lld\n", sum);
        return 0;
    }

    ll ans = 1;
    for (int i = 0; i < 26; i ++)
    {
        ans = (ans * A(a[i], (a[i] >> 1))) % MOD;
    }
    ans = (ans * fact(n >> 1)) % MOD;
    printf ("%lld\n", 1ll * (sum - ans + MOD) % MOD);
    return 0;
}