#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int inf = 2e5 + 5;

ll n, a[inf], sum[inf];
bool b[inf];

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
    sum[p] = sum[lc (p)] + sum[rc (p)];
    b[p] = b[lc (p)] & b[rc (p)];
}

void update (ll p, ll l, ll r, ll ql, ll qr)
{
    if (b[p]) return;
    if (ql <= l && r <= qr && l == r)
    {
        if (! b[p])
        {
            sum[p] = sqrt (sum[p]);
            if (sum[p] == 1) b[p] = true;
        }
        return;
    }
    ll mid = (l + r) >> 1;
    if (mid >= ql)
    {
        update (lc (p), l, mid, ql, qr);
    }
    if (mid < qr)
    {
        update (rc (p), mid + 1, r, ql, qr);
    }
    pushUp (p);
}

ll query (ll p, ll l, ll r, ll ql, ll qr)
{
    if (ql <= l && r <= qr)
    {
        return sum[p];
    }
    ll mid = (l + r) >> 1, ans = 0;
    if (mid >= ql)
    {
        ans += query (lc (p), l, mid, ql, qr);
    }
    if (mid < qr)
    {
        ans += query (rc (p), mid + 1, r, ql, qr);
    }
    return ans;
}

void buildTree (ll p, ll l, ll r)
{
    if (l == r)
    {
        sum[p] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    buildTree (lc (p), l, mid);
    buildTree (rc (p), mid + 1, r);
    pushUp (p);
}

int main ()
{
    scanf ("%lld", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &a[i]);
    }
    buildTree (1, 1, n);
    for (int i = 1; i <= n; i ++)
    {
        int t, l, r, c;
        scanf ("%d%d%d%d", &t, &l, &r, &c);
        if (t == 0) update (1, 1, n, l, r);
        if (t == 1) printf ("%lld\n", query (1, 1, n, l, r));
    }
    return 0;
}
