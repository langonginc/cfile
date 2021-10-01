#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int inf = 200005;

ll n, m, a[inf * 4];

inline ll lc(ll p) { return p << 1; }
inline ll rc(ll p) { return p << 1 | 1; }

inline void pushUp(ll p)
{
	a[p] = max (a[lc(p)], a[rc(p)]);
}

void update(ll p, ll l, ll r, ll w,  ll d)
{
	if (l == r && l == w)
	{
		a[p] = d;
		return;
	}
	ll mid = (l + r) >> 1;
	if (w <= mid)
	{
		update(lc(p), l, mid, w, d);
	}
	if (mid < w)
	{
		update(rc(p), mid + 1, r, w, d);
	}
	pushUp(p);
}

ll query(ll p, ll l, ll r, ll ql, ll qr)
{
	if (ql <= l && r <= qr)
	{
		return a[p];
	}
	ll mid = (l + r) >> 1, mx = -2147483647;
	if (ql <= mid)
	{
		mx = max(mx, query(lc(p), l, mid, ql, qr));
	}
	if (mid < qr)
	{
		mx = max(mx, query(rc(p), mid + 1, r, ql, qr));
	}
	return mx;
}

int main()
{
	cin >> n >> m;
    ll t = 0, cnt = 0;
	for (int i = 0; i < n; i ++)
	{
		char c;
		ll x;
		cin >> c >> x;
		if (c == 'Q')
		{
            if (x == 0) t = 0;
            else t = query(1, 1, n, cnt - x + 1, cnt) % m;
			printf("%lld\n", t);
		}
		else
		{
			update(1, 1, n, ++cnt, (x + t) % m);
		}
	}
	return 0;
}