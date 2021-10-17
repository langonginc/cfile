#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int inf = 2e5 + 5;
ll n, m, a[inf], t[inf], tag[inf], sqrtn;

inline ll pos (ll l)
{
    return l / sqrtn + (l % sqrtn != 0);
}

inline ll inpos (ll l)
{
    return l % sqrtn;
}

void movetag (ll p)
{
    for (ll i = (p - 1) * sqrtn + 1; i <= p * sqrtn; i++)
    {
        a[i] += tag[p];
    }
    tag[p] = 0;
}

void update (ll l, ll r, ll d)
{
    if (pos (l) == pos (r))
    {
        movetag (pos (l));
        for (ll i = l; i <= r; i ++)
        {
            a[i] += d;
            t[pos (l)] += d;
        }
    }
    for (ll i = pos (l) + (inpos(l - 1) ? 1 : 0); i < pos(r) + (inpos(r) ? 0 : 1); i ++)
    {
        tag[i] += d;
        t[i] += d * sqrtn;
    }
    if (inpos (l - 1))
    {
        movetag (pos (l));
        for (ll i = l; i <= pos (l) * sqrtn; i ++)
        {
            a[i] += d;
            t[pos (l)] += d;
        }
    }
    if (inpos (r))
    {
        movetag (pos (r));
        for (ll i = (pos (r) - 1) * sqrtn + 1; i <= r; i ++)
        {
            a[i] += d;
            t[pos (r)] += d;
        }
    }
}

ll query (ll l, ll r)
{
    ll result = 0;
    if (pos (l) == pos (r))
    {
        for (ll i = l; i <= r; i ++)
        {
            result += a[i];
        }
        return result;
    }
    for (ll i = pos (l) + (inpos(l - 1) ? 1 : 0); i < pos(r) + (inpos(r) ? 0 : 1); i ++)
    {
        result += t[i];
    }
    if (inpos (l - 1))
    {
        movetag (pos (l));
        for (ll i = l; i <= pos (l) * sqrtn; i ++)
        {
            result += a[i];
        }
    }
    if (inpos (r))
    {
        movetag (pos (r));
        for (ll i = (pos (r) - 1) * sqrtn + 1; i <= r; i ++)
        {
            result += a[i];
        }
    }
    return result;
}

int main ()
{
    scanf ("%lld%lld", &n, &m);
    sqrtn = sqrt (n);
    for (ll i = 1; i <= n; i ++)
    {
        scanf ("%lld", &a[i]);
    }
    for (ll i = 1; i <= n / sqrtn + 1; i ++)
    {
        for (ll j = (i - 1) * sqrtn + 1; j <= i * sqrtn; j ++)
        {
            t[i] += a[j];
        }
    }
    while (m --)
    {
        ll op, l, r;
        scanf ("%lld%lld%lld", &op, &l, &r);
        if (op == 1)
        {
            ll d; scanf ("%lld", &d);
            update (l, r, d);
        }
        else printf ("%lld\n", query (l, r));
    }
    return 0;
}