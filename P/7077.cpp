#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int M = 998244353;

int n, m, q, a[maxn], type[maxn], p[maxn], v[maxn], mul[maxn], cnt[maxn];
int deg1[maxn], deg2[maxn];
queue <int> q1, q2;
vector <int> adj1[maxn], adj2[maxn];

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf ("%d", &a[i]);
    }
    scanf ("%d", &m);
    for (int i = 1; i <= m; i ++) {
        scanf ("%d", &type[i]);
        mul[i] = 1;
        if (type[i] == 1) {
            scanf ("%d%d", &p[i], &v[i]);
        } else if (type[i] == 2) {
            scanf ("%d", &mul[i]);
        } else {
            int k, x;
            scanf ("%d", &k);
            for (int j = 1; j <= k; j ++) {
                scanf ("%d", &x);
                adj2[i].push_back(x);
                adj1[x].push_back(i);
            }
        }
    }
    scanf ("%d", &q);
    for (int i = 1; i <= q; i ++) {
        int x;
        scanf ("%d", &x);
        adj2[0].push_back(x);
        adj1[x].push_back(0);
    }
    cnt[0] = 1, mul[0] = 1;
    for (int i = 0; i <= m; i ++) {
        deg1[i] = adj2[i].size();
        deg2[i] = adj1[i].size();
        if (deg1[i] == 0) q1.push(i);
        if (deg2[i] == 0) q2.push(i);
    }
    while (!q1.empty()) {
        int u = q1.front();
        q1.pop();
        for (int i = 0; i < adj1[u].size(); i ++) {
            int v = adj1[u][i];
            mul[v] = ll(mul[v]) * ll(mul[u]) % M;
            if (-- deg1[v] == 0) q1.push(v);
        }
    }
    while (!q2.empty()) {
        int u = q2.front();
        q2.pop();
        ll fac = 1;
        for (int i = adj2[u].size() - 1; i >= 0; i --) {
            int v = adj2[u][i];
            cnt[v] = (ll(cnt[v]) + fac * ll(cnt[u])) % M;
            fac = fac * ll(mul[v]) % M;
            if (-- deg2[v] == 0) q2.push(v);
        }
    }
    for (int i = 1; i <= n; i ++) {
        a[i] = ll(a[i]) * ll(mul[0]) % M;
    }
    for (int i = 1; i <= m; i ++) {
        if (type[i] == 1) {
            a[p[i]] = (a[p[i]] + ll(cnt[i]) * ll(v[i])) % M;
        }
    }
    for (int i = 1; i <= n; i ++) {
        printf ("%d ", a[i]);
    }
    return 0;
}