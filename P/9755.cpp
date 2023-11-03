#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef __int128 i1;
const int maxn = 1e5 + 5;
const i1 i1c = 1;

int n;
ll a[maxn], b[maxn], c[maxn];
vector <int> adj[maxn];
ll s[maxn];

struct Point {
    int id, tm;
    bool operator < (const Point &x) const {
        return tm < x.tm;
    }
} dfsn[maxn];
ll fa[maxn];

inline i1 h1 (i1 i, i1 x, i1 y) {
    if (x > y) return 0;
    return (i1c * y - x + 1) * b[i] + (i1c * x + y) * (y - x + 1) * c[i] / 2;
}

bool check1 (ll i, ll x, ll day) {
    i1 h = 0;
    if (c[i] >= 0) {
        h = h1(i, x, day);
    } else {
        i1 t = (i1c - b[i]) / c[i];
        if (t >= day) {
            h = h1(i, x, day);
        } else {
            if (t < x) {
                h = day - x + 1;
            }
            else h = h1(i, x, t) + (day - t);
        }
    }
    return h >= i1c * a[i];
}

// ll dfs (int u, int f, ll day) {
//     ll minDay = day;
//     for (int i = 0; i < adj[u].size(); i ++) {
//         int v = adj[u][i];
//         if (v == f) continue;
//         ll sub = dfs(v, u, day);
//         minDay = min (minDay, sub - 1);
//     }
//     ll l = 1, r = day, mid, ans = 0;
//     while (l <= r) {
//         mid = (l + r) >> 1;
//         if (check1 (u, mid, day)) {
//             ans = mid;
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }
//     minDay = min (minDay, ans);
//     s[u] = minDay;
//     // printf ("[DFS] u=%d, min=%lld, max=%lld\n", u, minDay, day);
//     return minDay;
// }

int cnt = 0;

void dfs (int u, int f) {
    fa[u] = f;
    for (int i = 0; i < adj[u].size(); i ++) {
        int v = adj[u][i];
        if (v == f) continue;
        dfs(v, u);
    }
    cnt++;
    dfsn[cnt] = { u, cnt };
}

bool check2 (ll day) {
    bool flag1 = true;
    for (int u = 1; u <= n; u ++) {
        ll l = 1, r = day, mid, ans = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check1 (u, mid, day)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ans <= 0) return false;
        s[u] = ans;
        // s[u] = min (minDay, ans);
    }
    for (int i = 1; i <= n; i ++) {
        int u = dfsn[i].id;
        // ll minDay = day;
        // for (int j = 0; j < adj[u].size(); j ++) {
        //     int v = adj[u][j];
        //     if (v == fa[u]) continue;
        //     minDay = min (minDay, s[v] - 1);
        // }
        // // printf ("C2: S %d\n", u);
        // s[u] = min (minDay, s[u]);
        s[fa[u]] = min (s[fa[u]], s[u] - 1);
    }
    if (s[1] <= 0) flag1 = false;

    bool flag2 = true;
    sort (s + 1, s + n + 1);
    for (ll i = 1; i <= n; i ++) {
        if (i > s[i]) {
            flag2 = false;
            break;
        }
    }
    return flag1 && flag2;
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf ("%lld%lld%lld", &a[i], &b[i], &c[i]);
    }
    for (int i = 1; i < n; i ++) {
        int u, v;
        scanf ("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    // sort(dfsn + 1, dfsn + n + 1);
    ll l = n-1, r = 1e9 + 1, mid, ans = 114514;
    while (l <= r) {
        mid = (l + r) >> 1;
        // printf ("%lld\n", mid);
        if (check2(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf ("%lld\n", ans);
    return 0;
}