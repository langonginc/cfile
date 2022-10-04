#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>
typedef long long ll;
const int inf = 2e5 + 5;
const ll themax = 1 << 30;
ll n, m, a[inf], sum[inf * 4], smx[inf * 4], lr[inf * 4], xum[inf * 4];

class Pair{
    public:
    ll a, b, c;
    Pair () {}
    Pair (ll _a, ll _b, ll _c)
    {
        a = _a, b = _b, c = _c;
    }
};

/*

0 -> Any
1 -> With Left
2 -> With Right

*/

inline ll lc (ll p){
	return p << 1;
}
inline ll rc (ll p){
	return p << 1 | 1;
}
inline void pushup (ll p){
    if (sum[lc (p)] * sum[rc (p)] > themax) sum[p] = themax + 1;
	else sum[p] = sum[lc (p)] * sum[rc (p)];
    // smx[p] = max (max (smx[lc (p)], smx[rc (p)]), max (1ll, sum[lc (p)] * sum[rc (p)]));
    smx[p] = max (max (smx[lc (p)], smx[rc (p)]), smx[lc (p)] * smx[rc (p)]);

    xum[p] = 
    
}
void update (ll p, ll l, ll r, ll h, ll d){
    if (r < h || l > h) return;
	if (l == r && l == h){
		sum[p] = d;
        // smx[p] = max (d, 1ll);
        smx[p] = d;
		return;
	}
	ll mid = (l + r) >> 1;
    update (lc (p), l, mid, h, d);
    update (rc (p), mid + 1, r, h, d);
	pushup (p);
}
void build (ll p, ll l, ll r){
	if (l == r){
		sum[p] = a[l];
        // smx[p] = max (a[l], 1ll);
        smx[p] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build (lc (p), l, mid);
	build (rc (p), mid + 1, r);
	pushup (p);
}
Pair check (ll p, ll l, ll r, ll ql, ll qr){
	if (ql <= l && r <= qr)
    {
        printf ("p=%lld l=%lld r=%lld res=%lld\n", p, l, r, smx[p]);
        return Pair (smx[p], 0);
    }
	ll mid = (l + r) >> 1, result = 1, a = 0 , b = 0;
    Pair pa, pb;
	if (ql <= mid){
		// result = max (check (lc (p), l, mid, ql, qr), result);
        // result *= check (lc (p), l, mid, ql, qr);
        
        pa = check (lc (p), l, mid, ql, qr);
        a = pa.a;
        // result = a;
	}
	if (mid < qr){
		// result = max (check (rc (p), mid + 1, r, ql, qr), result);
        // a = check (rc (p), mid + 1, r, ql, qr);
        // if (result * a > themax) result = themax + 1;
        // else result *= a;

        pb = check (rc (p), mid + 1, r, ql, qr);
        b = pb.a;
        // result = max (result, b);
	}
    if (a != 0 && b == 0) result = a;
    if (a == 0 && b != 0) result = b;
    if (a != 0 && b != 0) result = (a * b > themax) ? (themax + 1) : (a * b);
    printf ("p=%lld l=%lld r=%lld a=%lld b=%lld res=%lld\n", p, l, r, a, b, result);
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
			ll a, k;
			scanf ("%lld%lld", &a, &k);
			update (1, 1, n, a, k);
		}
		else if (type == 2){
			ll a, b;
			scanf ("%lld%lld", &a, &b);
            ll res = check (1, 1, n, a, b);
            if (res <= 0) printf ("1\n");
            else if (res > themax) printf ("Too large\n");
			else printf ("%lld\n", res);
		}
	}
	return 0;
}
