#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
typedef long long ll;
const int inf = 200005;
ll n, m, a[inf], sum[inf * 4], tag[inf * 4];
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
	scanf ("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i ++){
		scanf ("%lld", &a[i]);
	}
	build (1, 1, n);
	for (ll i = 1; i <= m; i ++){
		int type;
		scanf ("%d", &type);
		if (type == 1){
			ll a, b, k;
			scanf ("%lld%lld%lld", &a, &b, &k);
			update (1, 1, n, a, b, k);
		}
        else if (type == 2)
        {
            ll k;
            scanf ("%lld", &k);
            update (1, 1, n, 1, 1, k);
        }
        else if (type == 3)
        {
            ll k;
            scanf ("%lld", &k);
            update (1, 1, n, 1, 1, -k);
        }
		else if (type == 4){
			ll a, b;
			scanf ("%lld%lld", &a, &b);
			printf ("%lld\n", check (1, 1, n, a, b));
		}
        else if (type == 5){
			printf ("%lld\n", check (1, 1, n, 1, 1));
		}
	}
	return 0;
}
