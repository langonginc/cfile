#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
typedef long long ll;
const int inf = 1000005;
ll n, m, a[inf], sum[inf * 4], ssum[inf * 4], tag[inf * 4];
inline ll lc (ll p){
	return p << 1;
}
inline ll rc (ll p){
	return p << 1 | 1;
}
void movetag (ll p, ll l, ll r, ll a){
    sum[p] += a * (l + r) * (r - l + 1) / 2;
    ssum[p] += a * (
		r * (r + 1) * (2 * r + 1) - 
		(l - 1) * l * (2 * (l - 1) + 1)
	) / 6;
    tag[p] += a;
}
void pushup (ll p){
	sum[p] = sum[lc (p)] + sum[rc (p)];
    ssum[p] = ssum[lc (p)] + ssum[rc (p)];
}
void pushdown (ll p, ll l, ll r){
	ll mid = (l + r) >> 1;
	movetag (lc (p), l, mid, tag[p]);
	movetag (rc (p), mid + 1, r, tag[p]);
	tag[p] = 0;
}
void update (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr){
		sum[p] += (l + r) * (r - l + 1) / 2;
        ssum[p] += (r * (r + 1) * (2 * r + 1) - (l - 1) * l * (2 * (l - 1) + 1)) / 6;
		tag[p] += 1;
		return;
	}
	pushdown (p, l, r);
	ll mid = (l + r) >> 1;
	if (ql <= mid){
		update (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		update (rc (p), mid + 1, r, ql, qr);
	}
	pushup (p);
}
ll querySum (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr)
        return sum[p];
	pushdown (p, l, r);
	ll mid = (l + r) >> 1, result = 0;
	if (ql <= mid){
		result += querySum (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		result += querySum (rc (p), mid + 1, r, ql, qr);
	}
	return result;
}
ll querySsum (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr)
        return ssum[p];
	pushdown (p, l, r);
	ll mid = (l + r) >> 1, result = 0;
	if (ql <= mid){
		result += querySsum (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		result += querySsum (rc (p), mid + 1, r, ql, qr);
	}
	return result;
}
int main (){
    ll n = 1000001;
	scanf ("%lld", &m);
	for (ll i = 1; i <= m; i ++){
		ll type;
		scanf ("%lld", &type);
		if (type == 1){
			ll x;
			scanf ("%lld", &x);
			update (1, 1, n, x, x);
		}
		else if (type == 2){
			ll a, b;
			scanf ("%lld%lld", &a, &b);
			update (1, 1, n, a, b);
		}
        else
        {
            ll a, b;
			scanf ("%lld%lld", &a, &b);
            printf ("%lld %lld\n", querySum (1, 1, n, a, b), querySsum (1, 1, n, a, b));
        }
	}
	return 0;
}
