#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;

int fac[maxn], inv[maxn];

inline int fastPow (int a, int b) {
    int res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = res * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return res % mod;
}

inline int c (int n, int m) {
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int fa[maxn];

int find (int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

inline void merge (int x, int y) {
    fa[find(x)] = find(y);
}

int n, q, size[maxn], f[maxn], ans[maxn];

inline void initInv () {
    fac[0] = 1;
    for (int i = 1; i <= n; i ++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[1] = 1;
    for (int i = 2; i <= n; i ++) {
        inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
    }
}

void init () {
    initInv ();
    for (int i = 0; i <= n; i ++) {
        fa[i] = i;
        f[i] = i;
        size[i] = 1;
        ans[i] = 1;
    }
    // inv[n] = fastPow (fac[n], mod - 2);
    // for (int i = n; i >= 1; i --) {
    //     inv[i - 1] = inv[i] * i % mod;
    // }
}

int main () {
    scanf ("%d%d", &n, &q);
    int cache = 0;
    init ();
    for (int i = 1; i <= q; i ++) {
        int opt, x, y;
        scanf ("%d", &opt);
        if (opt == 1) {
            scanf ("%d%d", &x, &y);
            x = (x + cache) % n + 1;
            y = (y + cache) % n + 1;
            x = find (x), y = find (y);
            f[x] = y;
            size[y] += size[x];
            ans[y] = (ans[y] * ans[x] % mod) * c(size[y] - 1, size[x]) % mod;
            merge (x, y);
        } else {
            scanf ("%d", &x);
            x = (x + cache) % n + 1;
            printf ("%d\n", cache = ans[find(x)]);
        }
    }
    return 0;
}