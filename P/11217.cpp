#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

ll n, q, w0;
ll a[maxn * 4], sum[maxn * 4], tag[maxn * 4];

inline ll lc (ll p) {
    return p << 1;
}

inline ll rc (ll p) {
    return p << 1 | 1;
}

inline void moveTag (ll p, ll l, ll r, ll d) {
    sum[p] += d * (r - l + 1);
    tag[p] += d;
}

inline void pushUp (ll p) {
    sum[p] = sum[lc(p)] + sum[rc(p)];
}

inline void pushDown (ll p, ll l, ll r) {
    ll mid = (l + r) >> 1;
    moveTag(lc(p), l, mid, tag[p]);
    moveTag(rc(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}

void update (ll p, ll l, ll r, ll ql, ll qr, ll d) {
    if (ql <= l && r <= qr) {
        moveTag(p, l, r, d);
        return;
    }
    pushDown(p, l, r);
    ll mid = (l + r) >> 1;
    if (ql <= mid) {
        update(lc(p), l, mid, ql, qr, d);
    }
    if (mid < qr) {
        update(rc(p), mid + 1, r, ql, qr, d);
    }
    pushUp(p);
}

void buildTree (ll p, ll l, ll r) {
    if (l == r) {
        sum[p] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    buildTree(lc(p), l, mid);
    buildTree(rc(p), mid + 1, r);
    pushUp(p);
}

ll query (ll p, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && r <= qr) {
        return sum[p];
    }
    pushDown(p, l, r);
    ll mid = (l + r) >> 1, ans = 0;
    if (ql <= mid) {
        ans += query(lc(p), l, mid, ql, qr);
    }
    if (mid < qr) {
        ans += query(rc(p), mid + 1, r, ql, qr);
    }
    return ans;
}

int main () {
    scanf("%lld%lld%lld", &n, &q, &w0);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
    }
    buildTree(1, 1, n);
    for (int i = 1; i <= q; i ++) {
        ll l, r, d;
        scanf("%lld%lld%lld", &l, &r, &d);
        update(1, 1, n, l, r, d);
        ll w = w0;
        ll s = query(1, 1, n, 1, n);
        ll p = 0;
        while (w - s >= 0) {
            w -= s, p ++;
            s <<= 1;
        }
        ll left = 1, right = n, mid, res = 0;
        while (w != 0 && left <= right) {
            mid = (left + right) >> 1;
            ll x = (1ll << p) * query(1, 1, n, 1, mid);
            if (w >= x) {
                left = mid + 1;
                res = mid - (w == x);
            } else {
                right = mid - 1;
            }
        }
        // printf("@%lld, p=%lld, res = %lld.\n", p * n + res - (w == 0), p, res);
        printf("%lld\n", p * n + res - (w == 0));
    }
    return 0;
}