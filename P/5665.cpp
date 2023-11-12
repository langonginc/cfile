#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;

int n, a[maxn], s[maxn], cnt, t;

int main () {
    scanf ("%d%d", &n, &t);
    for (int i = 1; i <= n; i ++) {
        scanf ("%d", &a[i]);
    }
    s[1] = a[1];
    cnt = 1;
    for (int i = 2; i < n; i ++) {
        // printf ("[log] test %d\n", i);
        if (a[i] >= s[cnt]) {
            // printf ("[log] good! ++cnt.\n");
            s[++ cnt] = a[i];
        } else {
            ll sum = a[i];
            int p = i;
            while (p <= n && (sum += a[++ p]) < s[cnt]);
            // printf ("[log]   p=%d, sum=%d\n", p, sum);
            if (a[i] + s[cnt] >= sum) {
                s[++ cnt] = sum;
                i = p;
            } else {
                s[cnt] += a[i];
            }
        }
    }
    if (a[n] >= s[cnt]) {
        s[++ cnt] = a[n];
    } else {
        s[cnt] += a[n];
    }
    ll ans = 0;
    for (int i = 1; i <= cnt; i ++) {
        ans += 1ll * s[i] * s[i];
    }
    printf ("%lld\n", ans);
    return 0;
}