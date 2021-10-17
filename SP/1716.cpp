#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
const int inf = 100005;
ll n, m, a[inf], sum[inf * 4], lft[inf * 4], rgt[inf * 4], res[inf * 4], ans, pre;
inline ll lc (ll p){
	return p << 1;
}
inline ll rc (ll p){
	return p << 1 | 1;
}
void pushup (ll p){
	sum[p] = sum[lc (p)] + sum[rc (p)];
    // if (sum[lc (p)] >= 0)
    // {
    //     lft[p] = sum[lc (p)] + lft[rc (p)];
    // }
    // else
    // {
    //     lft[p] = lft[lc (p)] + lft[rc (p)];
    // }
    // if (sum[rc (p)] >= 0)
    // {
    //     rgt[p] = sum[rc (p)] + rgt[lc (p)];
    // }
    // else
    // {
    //     rgt[p] = rgt[rc (p)] + rgt[lc (p)];
    // }
    lft[p] = max (lft[lc(p)], sum[lc(p)] + lft[rc(p)]);
    rgt[p] = max (rgt[rc(p)], sum[rc(p)] + rgt[lc(p)]);
    res[p] = max (rgt[lc(p)] + lft[rc(p)], max (res[lc(p)], res[rc(p)]));
}
void update (ll p, ll l, ll r, ll k, ll d){
	if (l == r && l == k){
		sum[p] = lft[p] = rgt[p] = res[p] = d;
		return;
	}
	ll mid = (l + r) >> 1;
	if (k <= mid)
    {
		update (lc (p), l, mid, k, d);
    }
	else
    {
		update (rc (p), mid + 1, r, k, d);
	}
	pushup (p);
}
void build (ll p, ll l, ll r){
	if (l == r){
		sum[p] = lft[p] = rgt[p] = res[p] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build (lc (p), l, mid);
	build (rc (p), mid + 1, r);
	pushup (p);
}
void query (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr)
	{
		ans = max (ans, res[p]);
        ans = max(ans, pre + lft[p]);
        pre = max(rgt[p], pre + sum[p]);
		return;
	}
        // return res[p];
	ll mid = (l + r) >> 1;
	// ans = 0;
	if (ql <= mid){
		query (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		query (rc (p), mid + 1, r, ql, qr);
	}
	// return result;
	// if (qr <= mid) return query (lc (p), l, mid, ql, qr);
	// if (mid < x) return query (rc(p), mid + 1, r, ql, qr);
	// return 
}
int main (){
	scanf ("%lld", &n);
	for (ll i = 1; i <= n; i ++){
		scanf ("%lld", &a[i]);
	}
	build (1, 1, n);
    scanf ("%lld", &m);
	for (ll i = 1; i <= m; i ++){
		int type;
		scanf ("%d", &type);
		if (type == 0){
			ll a, k;
			scanf ("%lld%lld", &a, &k);
			update (1, 1, n, a, k);
		}
		else if (type == 1){
			ll a, b;
			scanf ("%lld%lld", &a, &b);
			ans = pre = INT_MIN;
			query (1, 1, n, a, b);
			printf ("%lld\n", ans);
		}
	}
	return 0;
}
