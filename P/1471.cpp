#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
typedef long long ll;
const int inf = 200005;
ll n, m;
double a[inf], sum[inf * 4], sum2[inf * 4], tag[inf * 4], tag2[inf * 4];
inline ll lc (ll p){
	return p << 1;
}
inline ll rc (ll p){
	return p << 1 | 1;
}
void movetag (ll p, ll l, ll r, ll f){
	sum[p] += f * (r - l + 1);
	tag[p] += f;
    sum2[p] += f * (r - l + 1);
	tag2[p] += f;
}
void pushup (ll p){
	sum[p] = sum[lc (p)] + sum[rc (p)];
	sum2[p] = sum2[lc (p)] + sum2[rc (p)];    
}
void pushdown (ll p, ll l, ll r){
	ll mid = (l + r) >> 1;
	movetag (lc (p), l, mid, tag[p]);
	movetag (rc (p), mid + 1, r, tag[p]);
    movetag (lc (p), l, mid, tag2[p]);
	movetag (rc (p), mid + 1, r, tag2[p]);
	tag[p] = 0;
	tag2[p] = 0;
}
void update (ll p, ll l, ll r, ll ql, ll qr, double d){
	if (ql <= l && r <= qr){
        sum2[p] += sum[p] * (d * 2) + (r - l + 1) * d * d;
        tag2[p] += d;
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
        sum2[p] = a[l] * a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build (lc (p), l, mid);
	build (rc (p), mid + 1, r);
	pushup (p);
}
double query1 (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr)
        return sum[p];
	pushdown (p, l, r);
	ll mid = (l + r) >> 1;
    double result = 0;
	if (ql <= mid){
		result += query1 (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		result += query1 (rc (p), mid + 1, r, ql, qr);
	}
	return result;
}
double query2 (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr)
        return sum2[p];
	pushdown (p, l, r);
	ll mid = (l + r) >> 1;
    double result = 0;
	if (ql <= mid){
		result += query2 (lc (p), l, mid, ql, qr);
	}
	if (mid < qr){
		result += query2 (rc (p), mid + 1, r, ql, qr);
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
			ll a, b;
            double k;
			scanf ("%lld%lld%lf", &a, &b, &k);
			update (1, 1, n, a, b, k);
		}
        else if (type == 2){
			ll a, b;
			scanf ("%lld%lld", &a, &b);
			printf ("%.4lf\n", query1 (1, 1, n, a, b) / ((b - a + 1) * 1.0));
		}
        else if (type == 3){
			ll a, b;
			scanf ("%lld%lld", &a, &b);
			printf ("%.4lf\n", (query2 (1, 1, n, a, b) / ((b - a + 1) * 1.0)) - query1(1, 1, n, a, b) / ((b - a + 1) * 1.0));
		}
	}
	return 0;
}
