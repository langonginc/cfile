#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 5e5 + 5;

class Edge {
    public:
    int to, next;
    Edge () {}
    Edge (int _to, int _next) {
        to = _to, next = _next;
    }
};

int nn;
Edge e[4 * maxn];
int head[maxn];

int vis[maxn], ring[maxn];
int n, m;


inline void addEdge (int u, int v) {
    e[++ nn] = Edge (v, head[u]);
    head[u] = nn;
}

// void findRing (int u, int f) {
//     vis[u] = true;
//     for (int i = head[u]; i; i = e[i].next) {
//         int v = e[i].to;
//         if (v == f) continue;
//         if (vis[v] && ring[v] == 0) {
//             // Ring, v is root.
//             printf ("V is root %d\n", v);
//             // ring[v] = v;
//             printf ("%d on ring %d\n", u, v);
//             ring[u] = v;
//             continue;
//         }
//         if (!vis[v]) {
//             findRing (v, u);
//             if (ring[v] > 0) {
//                 printf ("%d on ring %d\n", u, ring[v]);
//                 ring[u] = ring[v];
//             }
//         }
//     }
// }

void dfs (int u, int f) {
    priority_queue <int, vector<int>, greater<int> > q;
    vis[u] = true;
    printf ("%d ", u);
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        q.push (v);
    }
    while (!q.empty ()) {
        if (!vis[q.top ()]) {
            dfs (q.top (), u);
        }
        q.pop ();
    }
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int u, v;
        scanf ("%d%d", &u, &v);
        addEdge (u, v), addEdge (v, u);
    }
    // findRing (1, 0);
    // for (int i = 1; i <= n; i ++) {
    //     if (ring[i] > 0) {
    //         printf ("i=%d, in ring %d.\n", i, ring[i]);
    //     }
    // }
    dfs (1, 0);
    return 0;
}