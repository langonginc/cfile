#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
const int inf = 5000005;
ll n, m, a[inf], sum[inf * 4];
inline ll lc (ll p){
	return p << 1;
}
inline ll rc (ll p){
	return p << 1 | 1;
}
void pushup (ll p){
	sum[p] = sum[lc (p)] + sum[rc (p)];
}
void update (ll p, ll l, ll r, ll q, ll d){
	if (l == r && l == q){
		sum[p] = d;
		return;
	}
	ll mid = (l + r) >> 1;
    if (q <= mid) update (lc (p), l, mid, q, d);
    else update (rc (p), mid + 1, r, q, d);
	pushup (p);
}
void build (ll p, ll l, ll r){
	if (l == r){
		sum[p] = a[l];
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
	ll mid = (l + r) >> 1, result = LLONG_MIN;
	if (ql <= mid){
		result = max(result, check (lc (p), l, mid, ql, qr));
	}
	if (mid < qr){
		result = max(result, check (rc (p), mid + 1, r, ql, qr));
	}
	return result;
}
int main (){
	scanf ("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i ++){
		scanf ("%lld", &a[i]);
	}
	build (1, 1, n);
	for (ll i = 1; i <= m; i ++){
		int type;
		scanf ("%d", &type);
		if (type == 2){
			ll a, k;
			scanf ("%lld%lld", &a, &k);
			update (1, 1, n, a, k);
		}
		else if (type == 1){
			ll a, b;
			scanf ("%lld%lld", &a, &b);
            if (a > b) swap(a, b);
			printf ("%lld\n", check (1, 1, n, a, b));
		}
	}
	return 0;
}
