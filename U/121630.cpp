#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
const ll inf = 2 * 1e5 + 5;
ll n, m, a[inf], sum[4 * inf], tag[4 * inf];
inline ll lc(ll p)
{
	return p << 1;
}
inline ll rc(ll p)
{
	return p << 1 | 1;
}

inline void moveTag(ll p, ll l, ll r, ll d)
{
	if (d == 2)
		return;
	if (d == 1)
	{
		sum[p] = (r - l + 1);
	}
	if (d == 0)
	{
		sum[p] = 0;
	}
	tag[p] = d;
}

inline void pushDown(ll p, ll l, ll r)
{
	ll mid = (l + r) >> 1;
	moveTag(lc(p), l, mid, tag[p]);
	moveTag(rc(p), mid + 1, r, tag[p]);
	tag[p] = 2;
}

inline void pushUp(ll p)
{
	sum[p] = (sum[lc(p)] + sum[rc(p)]);
}

void buildTree(ll p, ll l, ll r)
{
	tag[p] = 2;
	if (l == r)
	{
		sum[p] = 1;
		return;
	}
	ll mid = (l + r) >> 1;
	buildTree(lc(p), l, mid);
	buildTree(rc(p), mid + 1, r);
	pushUp(p);
}

void update(ll p, ll l, ll r, ll ql, ll qr, ll d)
{
	if (ql <= l && r <= qr)
	{
		sum[p] = (r - l + 1) * d;
		tag[p] = d;
		return;
	}
	ll mid = (l + r) >> 1;
	pushDown(p, l, r);
	if (ql <= mid)
	{
		update(lc(p), l, mid, ql, qr, d);
	}
	if (mid < qr)
	{
		update(rc(p), mid + 1, r, ql, qr, d);
	}
	pushUp(p);
}

ll query(ll p, ll l, ll r, ll ql, ll qr)
{
	if (ql <= l && r <= qr)
	{
		return sum[p];
	}
	pushDown(p, l, r);
	ll mid = (l + r) >> 1, res = 0;
	if (ql <= mid)
	{
		res += query(lc(p), l, mid, ql, qr);
	}
	if (mid < qr)
	{
		res += query(rc(p), mid + 1, r, ql, qr);
	}
	return res;
}

int main()
{
	ll ans =0 ;
	cin >> n >> m;
	buildTree(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		ll op, x, y;
		cin >> op >> x >> y;
		if (op == 2)
		{
			update(1, 1, n, x, y,1);
		}
		else
		{
			ans += query(1, 1, n, x, y);
			//printf("%lld\n", ans);
			update(1, 1, n, x, y, 0);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
