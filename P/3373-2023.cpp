#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 4e5 + 5;

ll n, m, mod, a[inf], sum[inf], addtag[inf], multag[inf];

inline ll lc (ll p)
{
    return p << 1;
}

inline ll rc (ll p)
{
    return p << 1 | 1;
}

inline void pushUp (ll p)
{
    sum[p] = (sum[lc (p)] + sum[rc (p)]) % mod;
}

inline void moveTag (ll p, ll l, ll r, ll tmpadd, ll tmpmul)
{
    sum[p] = (sum[p] * tmpmul + tmpadd * (r - l + 1)) % mod;
    addtag[p] = (addtag[p] * tmpmul + tmpadd) % mod;
    multag[p] = (multag[p] * tmpmul) % mod;
}

inline void pushDown (ll p, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    moveTag (lc (p), l, mid, addtag[p], multag[p]);
    moveTag (rc (p), mid + 1, r, addtag[p], multag[p]);
    addtag[p] = 0, multag[p] = 1;
}

void buildTree (ll p, ll l, ll r)
{
    addtag[p] = 0, multag[p] = 1;
    if (l == r)
    {
        sum[p] = a[l] % mod;
        return;
    }
    ll mid = (l + r) >> 1;
    buildTree (lc (p), l, mid);
    buildTree (rc (p), mid + 1, r);
    pushUp (p);
}

ll querySum (ll p, ll l, ll r, ll ql, ll qr)
{
    if (ql <= l && r <= qr)
    {
        return sum[p] % mod;
    }
    ll mid = (l + r) >> 1, ans = 0;
    pushDown (p, l, r);
    if (mid >= ql)
    {
        ans = (ans + querySum (lc (p), l, mid, ql, qr)) % mod;
    }
    if (mid < qr)
    {
        ans = (ans + querySum (rc (p), mid + 1, r, ql, qr)) % mod;
    }
    return ans % mod;
}

void addUpdate (ll p, ll l, ll r, ll ql, ll qr, ll v)
{
    if (ql <= l && r <= qr)
    {
        sum[p] = (sum[p] + v * (r - l + 1)) % mod;
        addtag[p] = (addtag[p] + v) % mod;
        return;
    }
    ll mid = (l + r) >> 1;
    pushDown (p, l, r);
    if (mid >= ql)
    {
        addUpdate (lc (p), l, mid, ql, qr, v);
    }
    if (mid < qr)
    {
        addUpdate (rc (p), mid + 1, r, ql, qr, v);
    }
    pushUp (p);
}

void mulUpdate (ll p, ll l, ll r, ll ql, ll qr, ll v)
{
    if (ql <= l && r <= qr)
    {
        sum[p] = (sum[p] * v) % mod;
        addtag[p] = (addtag[p] * v) % mod;
        multag[p] = (multag[p] * v) % mod;
        return;
    }
    ll mid = (l + r) >> 1;
    pushDown (p, l, r);
    if (mid >= ql)
    {
        mulUpdate (lc (p), l, mid, ql, qr, v);
    }
    if (mid < qr)
    {
        mulUpdate (rc (p), mid + 1, r, ql, qr, v);
    }
    pushUp (p);
}

int main ()
{
    scanf ("%lld%lld%lld", &n, &m, &mod);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &a[i]);
    }
    buildTree (1, 1, n);
    for (int i = 1; i <= m; i ++)
    {
        int t, l, r, v;
        scanf ("%d%d%d", &t, &l, &r);
        if (t == 1)
        {
            scanf ("%d", &v);
            mulUpdate (1, 1, n, l, r, v);
        }
        if (t == 2)
        {
            scanf ("%d", &v);
            addUpdate (1, 1, n, l, r, v);
        }
        if (t == 3)
        {
            printf ("%lld\n", querySum (1, 1, n, l, r));
        }
    }
    return 0;
}