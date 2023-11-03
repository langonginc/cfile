#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;

ll n, a[maxn], b[maxn], c[maxn], d[maxn], q, m, p[maxn];
ll dp[maxn], preTo0[maxn], preTo1[maxn];

int main () {
    scanf ("%lld", &n);
    for (int i = 1; i <= n; i ++) {
        scanf ("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i ++) {
        scanf ("%lld", &b[i]);
    }
    for (int i = 1; i <= n; i ++) {
        scanf ("%lld", &c[i]);
    }
    for (int i = 1; i <= n; i ++) {
        d[i] = min (a[i], d[i - 1] + b[i]);
        preTo0[i] = preTo0[i - 1] + b[i];
    }
    scanf ("%lld", &q);
    while (q --) {
        memset (dp, 0x7f, sizeof (dp));
        scanf ("%lld", &m);
        for (int i = 1; i <= m; i ++) {
            scanf ("%lld", &p[i]);
            preTo1[p[i]] = preTo1[p[i - 1]] + c[p[i]];
        }
        dp[p[1]] = min (d[p[1]] + preTo1[p[1]],d[p[1]-1]);
        for (int i = 2; i <= m; i ++) {
            dp[p[i]] = min (min (d[p[i]] + preTo1[p[i]], d[p[i] - 1] + preTo1[p[i - 1]]), dp[p[i - 1]] + preTo0[p[i] - 1] - preTo0[p[i - 1]]);
        }
        if (p[m] == n) {
            printf ("%lld\n", dp[n]);
        } else {
            printf ("%lld\n", min (d[n] + preTo1[p[m]], dp[p[m]] + preTo0[n] - preTo0[p[m]]));
        }
    }
    return 0;
}