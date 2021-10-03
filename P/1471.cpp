#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
typedef long long ll;
const int inf = 1000005;
ll n, m;
double a[inf], sum[inf * 4], ssum[inf * 4], tag[inf * 4];
inline ll lc (ll p){
	return p << 1;
}
inline ll rc (ll p){
	return p << 1 | 1;
}
void movetag (ll p, ll l, ll r, double a){
    ssum[p] += 2.0 * a* sum[p] + (r - l + 1) * a * a;
	sum[p] += (r - l + 1) * a;
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
void build (ll p, ll l, ll r){
	if (l == r){
		sum[p] = a[l];
		ssum[p] = a[l] * a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build (lc (p), l, mid);
	build (rc (p), mid + 1, r);
	pushup (p);
}
void update (ll p, ll l, ll r, ll ql, ll qr, double d){
	if (ql <= l && r <= qr){
        ssum[p] += 2.0 * sum[p] * d + (r - l + 1) * d * d;
		sum[p] += (r - l + 1) * d;
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
double querySum (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr)
        return sum[p];
	pushdown (p, l, r);
	ll mid = (l + r) >> 1;
	double result = 0;
	if (ql <= mid){
		result += querySum (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		result += querySum (rc (p), mid + 1, r, ql, qr);
	}
	return result;
}
double querySsum (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr)
        return ssum[p];
	pushdown (p, l, r);
	ll mid = (l + r) >> 1;
	double result = 0;
	if (ql <= mid){
		result += querySsum (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		result += querySsum (rc (p), mid + 1, r, ql, qr);
	}
	return result;
}
int main (){
	scanf ("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i ++)
	{
		scanf ("%lf", &a[i]);
	}
	build (1, 1, n);
	for (ll i = 1; i <= m; i ++)
	{
		ll type;
		scanf ("%lld", &type);
		if (type == 1){
			ll a, b;
			double k;
			scanf ("%lld%lld%lf", &a, &b, &k);
			update (1, 1, n, a, b, k);
		}
        else if (type == 2)
        {
            ll a, b;
			scanf ("%lld%lld", &a, &b);
            printf ("%.4lf\n", querySum (1, 1, n, a, b) / ((b - a + 1) * 1.0));
        }
		else
        {
            ll a, b;
			scanf ("%lld%lld", &a, &b);
			double _sum = querySum (1, 1, n, a, b) / ((b - a + 1) * 1.0);
			double _ssum = querySsum (1, 1, n, a, b) / ((b - a + 1) * 1.0);
            printf ("%.4lf\n", _ssum - _sum * _sum);
        }
	}
	return 0;
}
