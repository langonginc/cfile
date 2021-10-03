#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
using namespace std;
typedef long long ll;
//const ll INF = 1000005;
const ll inf = 200005;
inline ll lc(ll p) {
	return p << 1;
}
inline ll rc(ll p) {
	return p << 1 | 1;
}
ll n, m, a[inf], sum[inf * 4], ma[inf * 4];
void push(ll p) {
	sum[p] = sum[lc(p)] + sum[rc(p)];
	ma[p] = max(ma[lc(p)], ma[rc(p)]);
}
void build(ll p, ll l, ll r) {
	if (l == r) {
		sum[p] = a[l];
		ma[p] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(lc(p), l, mid);
	build(rc(p), mid + 1, r);
	push(p);
}
ll checkma(ll p, ll l, ll r, ll ql, ll qr) {
	if (ql <= l && r <= qr)return ma[p];
	ll ans = -1, mid = (l + r) >> 1;
	if (ql <= mid) {
		ans = max(ans, checkma(lc(p), l, mid, ql, qr));
	}
	if (mid < qr) {
		ans = max(ans, checkma(rc(p), mid + 1, r, ql, qr));
	}
	return ans;
}
void change(ll k, ll l, ll r, ll ql, ll qr)
{
	if (r<ql || l>qr) return;
	if (ma[k] <= 1) return;
	if (l == r)
	{
		sum[k] = (ll) sqrt(sum[k]);
		ma[k] = sum[k];
		return;
	}
	ll mid = (l + r) / 2;
	change(k * 2, l, mid, ql, qr);
	change(k * 2 + 1, mid + 1, r, ql, qr);
	push(k);
}
ll checkmi(ll p, ll l, ll r, ll ql, ll qr) {
	if (ql <= l && r <= qr)return sum[p];
	ll ans = 0, mid = (l + r) >> 1;
	if (ql <= mid) {
		ans = checkmi(lc(p), l, mid, ql, qr);
	}
	if (mid < qr) {
		ans += checkmi(rc(p), mid + 1, r, ql, qr);
	}
	return ans;
}

int main() {
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
		{
			cout << checkmi(1, 1, n, l, r) << endl;
		}
		if (t == 2)
		{
			change(1, 1, n, l, r);
		}
	}
	return 0;
}