#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int inf = 100005;
ll n, m, a[inf], sum[inf * 4], tag[inf * 4], x, y;
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
	scanf ("%lld%lld%lld", &n, &x, &y);
	for (ll i = 1; i <= n; i ++){
		scanf ("%lld", &a[i]);
	}
	build (1, 1, n);
    int ans = 0;
	for (int i = 1; i <= n; i ++)
    {
        for (int j = i; j <= n; j ++)
        {
            int t = check (1, 1, n, i, j);
            // printf ("[INFO] %d -> %d : %d\n", i, j, t);
            if (t >= x && t <= y)
            {
                ans ++;
                // printf ("[INFO] ANS\n");
            }
        }
    }
    printf ("%d\n", ans);
	return 0;
}
