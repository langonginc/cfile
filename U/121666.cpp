#include<iostream>
#include<cstdio>
//#include<queue>
#include<algorithm>
#include<cstring>
//#include<queue>
//#include<iomanip>
#include<cstdlib> 
//#include<set>
//#include<vector> 
#include<climits>
using namespace std;
typedef long long ll;
const int inf = 200005;

ll n, m, a[inf], sum[4*inf], sq[4*inf];

inline ll lc(ll x)
{
	return x << 1;
}
inline ll rc(ll x)
{
	return x << 1 | 1;
}

inline void pushUp(ll p)
{
	sum[p] = sum[lc(p)] + sum[rc(p)];
	sq[p] = sq[lc(p)] + sq[rc(p)];
}

void buildTree(ll p, ll l, ll r)
{
	if (l == r)
	{
		sum[p] = a[l], sq[p] = a[l] * a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	buildTree(lc(p), l, mid);
	buildTree(rc(p), mid + 1, r);
	pushUp(p);
}

void update(ll p, ll l, ll r, ll q, ll d)
{
	if (l == r)
	{
		sum[p] = d, sq[p] = d*d;
		return;
	}
	ll mid = (l + r) >> 1;
	if (q <= mid)
		update(lc(p), l, mid, q, d);
	else
		update(rc(p), mid + 1, r, q, d);
	pushUp(p);
}

ll querySum(ll p, ll l, ll r, ll ql, ll qr)
{
	if (ql <= l && r <= qr)
	{
		return sum[p];
	}
	ll mid = (l + r) >> 1, res = 0;
	if (ql <= mid)
	{
		res += querySum(lc(p), l, mid, ql, qr);
	}
	if (mid < qr)
	{
		res += querySum(rc(p), mid + 1, r, ql, qr);
	}
	return res;
}

ll querySq(ll p, ll l, ll r, ll ql, ll qr)
{
	if (ql <= l && r <= qr)
	{
		return sq[p];
	}
	ll mid = (l + r) >> 1, res = 0;
	if (ql <= mid)
	{
		res += querySq(lc(p), l, mid, ql, qr);
	}
	if (mid < qr)
	{
		res += querySq(rc(p), mid + 1, r, ql, qr);
	}
	return res;
}

int main()
{
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	buildTree(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		ll op, x, y;
		scanf("%lld%lld%lld", &op, &x, &y);
		if (op == 1)
		{
			ll res = 0;
			ll s = querySum(1, 1, n, x, y);
			ll sq1 = querySq(1, 1, n, x, y);
			res = (s * s - sq1) /2;
			printf("%lld\n", res);
		}
		else
		{
			update(1, 1, n, x, y);
		}
	}
	return 0;
}
