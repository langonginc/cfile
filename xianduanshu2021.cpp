#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 1e5 + 5;
ll n, m, a[inf], sum[4 * inf], tag[4 * inf];

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
}

inline void moveTag (ll p, ll l, ll r, ll d)
{
    tag[p] += d;
    sum[p] += d *= (r - l + 1); 
}

inline void pushDown (ll p, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    moveTag (lc (p), l, mid, tag[p]);
    moveTag (rc (p), mid + 1, r, tag[p]);
    tag[p] = 0;
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

void update (ll p, ll l, ll r, ll ql, ll qr, ll d)
{
    if (ql <= l && r <= qr)
    {
        sum[p] += d * (r - l + 1);
        tag[p] += d;
        return;
    }
    ll mid = (l + r) >> 1;
    pushDown (p, l, r);
    if (ql <= mid) update (lc (p), l, mid, ql, qr, d);
    if (mid < qr) update (rc (p), mid + 1, r, ql, qr, d);
    pushUp (p);
}

ll query (ll p, ll l, ll r, ll ql, ll qr)
{
    if (ql <= l && r <= qr)
    {
        return sum[p];
    }
    ll mid = (l + r) >> 1, result = 0;
    pushDown (p, l, r);
    if (ql <= mid) result += query (lc (p), l, mid, ql, qr);
    if (mid < qr) result += query (rc (p), mid + 1, r, ql, qr);
    return result;
}

int main ()
{
    scanf ("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i ++){
		scanf ("%lld", &a[i]);
	}
	buildTree (1, 1, n);
	for (ll i = 1; i <= m; i ++){
		int type;
		scanf ("%d", &type);
		if (type == 1){
			ll a, b, k;
			scanf ("%lld%lld%lld", &a, &b, &k);
			update (1, 1, n, a, b, k);
		}
		else if (type == 2){
			ll a, b;
			scanf ("%lld%lld", &a, &b);
			printf ("%lld\n", query (1, 1, n, a, b));
		}
	}
	return 0;
}