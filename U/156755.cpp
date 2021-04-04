#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int inf = 100005;
const int INF = 1000005;
ll n, m, a[inf], sum[inf * 4], tag[inf * 4], x, y, pre[inf];
inline ll lc (ll p){
	return p << 1;
}
inline ll rc (ll p){
	return p << 1 | 1;
}
void movetag (ll p, ll l, ll r, ll f){
	sum[p] += f * (r - l + 1);
	tag[p] += f;
}
void pushup (ll p){
	sum[p] = sum[lc (p)] + sum[rc (p)];
}
void pushdown (ll p, ll l, ll r){
	ll mid = (l + r) >> 1;
	movetag (lc (p), l, mid, tag[p]);
	movetag (rc (p), mid + 1, r, tag[p]);
	tag[p] = 0;
}
void update (ll p, ll l, ll r, ll ql, ll qr, ll d){
	if (ql <= l && r <= qr){
		sum[p] += d * (r - l + 1);
		tag[p] += d;
		return;
	}
	pushdown (p, l, r);
	ll mid = (l + r) >> 1;
	if (ql <= mid){
		update (lc (p), l, mid, ql, qr, d);
	}
	if (mid < qr){
		update (rc (p), mid + 1, r, ql, qr, d);
	}
	pushup (p);
}
void build (ll p, ll l, ll r){
	if (l == r){
		// sum[p] = a[l];
        sum[p] = 0;
		return;
	}
	ll mid = (l + r) >> 1;
	build (lc (p), l, mid);
	build (rc (p), mid + 1, r);
	pushup (p);
}
ll check (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr)
    return sum[p];
	pushdown (p, l, r);
	ll mid = (l + r) >> 1, result = 0;
	if (ql <= mid){
		result += check (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		result += check (rc (p), mid + 1, r, ql, qr);
	}
	return result;
}
int main (){
	scanf ("%lld%lld%lld", &n, &x, &y);
	for (ll i = 1; i <= n; i ++){
		scanf ("%lld", &a[i]);
        pre[i] = pre[i - 1] + a[i];
	}
    ll ans = 0;
	for (int i = 1; i <= n; i ++)
    {
        // pre[i]-x  <  pre[r]  <  pre[i]-y
        ans += check(1, -INF, INF, pre[i] - x, pre[i] - y);
        update (1, -INF, INF, pre[i], pre[i], 1);
    }
    printf ("%lld\n", ans);
	return 0;
}
