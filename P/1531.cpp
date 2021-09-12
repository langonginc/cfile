#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int inf = 200005;

ll n, m, a[inf], high[4 * inf];

inline ll lc(ll p) { return p << 1; }
inline ll rc(ll p) { return p << 1 | 1; }

inline void pushUp(ll p)
{
	high[p] = max (high[lc(p)], high[rc(p)]);
}

void buildTree(ll p, ll l, ll r)
{
	if (l == r)
	{
        high[p] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	buildTree(lc(p), l, mid);
	buildTree(rc(p), mid + 1, r);
	pushUp(p);
}

void update(ll p, ll l, ll r, ll w,  ll d)
{
	if (l == r && l == w)
	{
		// a[l] = d;
        high[p] = max (high[p], d);
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
		return high[p];
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
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	buildTree(1, 1, n);
	while (m--)
	{
		char x;
		ll l, r;
		cin >> x >> l >> r;
		if (x == 'Q')
		{
			printf("%d\n", query(1, 1, n, l, r));
		}
		else
		{
			update(1, 1, n, l, r);
		}
	}
	return 0;
}