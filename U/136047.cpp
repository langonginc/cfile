#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int inf = 2* 1e6 + 5;
ll sum[4][4 * inf];
ll tag[4][4 * inf];
ll n, m;

inline ll lc(ll p)
{
	return p << 1;
}
inline ll rc(ll p)
{
	return p << 1 | 1;
}

inline void moveTag(ll p, ll l, ll r, ll d, ll id)
{
	sum[id][p] += (r - l + 1) * d;
	tag[id][p] += d;
}

inline void pushup(ll p, ll id) {
	sum[id][p] = sum[id][lc(p)] + sum[id][rc(p)];
}

inline void pushdown(ll p, ll l, ll r, ll id) {
	if (tag[id][p] == 0)
	{
		return;
	}
	ll mid = (l + r) >> 1;
	moveTag(lc(p), l, mid, tag[id][p], id);
	moveTag(rc(p), mid + 1, r, tag[id][p], id);
	tag[id][p] = 0;
}

void update(ll p, ll l, ll r, ll ql, ll qr, ll d, ll id) {
	if (ql <= l && r <= qr) {
		sum[id][p] += d * (r - l + 1);
		tag[id][p] += d;
		return;
	}
	pushdown(p, l, r, id);
	ll mid = (l + r) >> 1;
	if (ql <= mid) {
		update(lc(p), l, mid, ql, qr, d, id);
	}
	if (mid < qr) {
		update(rc(p), mid + 1, r, ql, qr, d, id);
	}
	pushup(p, id);
}

//void build(ll p, ll l, ll r, ll id) {
//	if (l == r) {
//		sum[id][p] = 0;
//		return;
//	}
//	ll mid = (l + r) >> 1;
//	build(lc(p), l, mid, id);
//	build(rc(p), mid + 1, r, id);
//	pushup(p, id);
//}

ll query(ll p, ll l, ll r, ll ql, ll qr, ll id) {
	if (ql <= l && r <= qr)
		return sum[id][p];
	pushdown(p, l, r, id);
	ll mid = (l + r) >> 1, result = 0;
	if (ql <= mid) {
		result += query(lc(p), l, mid, ql, qr, id);
	}
	if (mid < qr) {
		result += query(rc(p), mid + 1, r, ql, qr, id);
	}
	return result;
}

int main() {
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= m; i++) {
		int type;
		scanf("%d", &type);
		if (type == 0) {
			ll a, b, c, d, k;
			scanf("%lld%lld%lld%lld%lld", &a, &b,&c,&d, &k);
			/*ll startx = a;
			ll endx = c;
			ll starty = b;
			ll endy = d;
			if (startx == 1 && endx == 1)
			{
				update(1, 1, n, starty, endy, k, 1);
			}
			if (startx == 1 && endx == 2)
			{
				update(1, 1, n, starty, endy, k, 1);
				update(1, 1, n, starty, endy, k, 2);
			}
			if (startx == 1 && endx == 3)
			{
				update(1, 1, n, starty, endy, k, 1);
				update(1, 1, n, starty, endy, k, 2);
				update(1, 1, n, starty, endy, k, 3);
			}
			if (startx == 2 && endx == 2)
			{
				update(1, 1, n, starty, endy, k, 2);
			}
			if (startx == 2 && endx == 3)
			{
				update(1, 1, n, starty, endy, k, 2);
				update(1, 1, n, starty, endy, k, 3);
			}
			if (startx == 3 && endy == 3)
			{
				update(1, 1, n, starty, endy, k, 3);
			}*/
			for (int j = a; j <= c; ++j) {
				update(1, 1, n, b, d, k, j);
			}
		}
		else if (type == 1) {
			ll a, b, c, d, ans = 0;
			scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
			/*ll startx = a;
			ll endx = c;
			ll starty = b;
			ll endy = d;
			ll ans = 0;
			if (startx == 1 && endx == 1)
			{
				ans += query(1, 1, n, starty, endy, 1);
			}
			if (startx == 1 && endx == 2)
			{
				ans += query(1, 1, n, starty, endy, 1);
				ans += query(1, 1, n, starty, endy, 2);
			}
			if (startx == 1 && endx == 3)
			{
				ans += query(1, 1, n, starty, endy, 1);
				ans += query(1, 1, n, starty, endy, 2);
				ans += query(1, 1, n, starty, endy, 3);
			}
			if (startx == 2 && endx == 2)
			{
				ans += query(1, 1, n, starty, endy, 2);
			}
			if (startx == 2 && endx == 3)
			{
				ans += query(1, 1, n, starty, endy, 2);
				ans += query(1, 1, n, starty, endy, 3);
			}
			if (startx == 3 && endy == 3)
			{
				ans += query(1, 1, n, starty, endy, 3);
			}*/
			for (int j = a; j <= c; ++j) {
				ans += query(1, 1, n, b, d, j);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
