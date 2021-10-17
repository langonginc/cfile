#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 50005;
const int mod = 1e9 + 7;

class Node
{
    public: 
    int to, next;
    Node () {}
    Node (Node *t) : to(t->to), next(t->next) {}
    Node (const Node &t) : to(t.to), next(t.next) {}
    Node (int to, int next) : to (to), next (next) {}
};

int n, r, m, head[inf], fa[inf], sz[inf], nn, ans[inf];
Node pool[2 * inf];

inline void addEdge (int u, int v)
{
    pool[++ nn] = Node (v, head[u]);
    head[u] = nn;
}

int dfs (int u, int f)
{
    fa[u] = f;
    sz[u] = 1;
    for (int i = head[u]; i; i = pool[i].next)
    {
        int v = pool[i].to;
        if (v != f)
        {
            sz[u] += dfs (v, u);
        }
    }
    return sz[u];
}

int main ()
{
    scanf ("%d%d%d", &n, &r, &m);
    for (int i = 1; i < n; i ++)
    {
        int a, b;
        scanf ("%d%d", &a, &b);
        addEdge (a, b);
        addEdge (b, a);
    }
    dfs (r, 0);
    for (int u = 1; u <= n; u ++)
    {
        for (int i = head[u]; i; i = pool[i].next)
        {
            int v = pool[i].to;
            if (v != fa[u])
            {
                ans[u] = (ans[u] + (sz[u] - sz[v]) * sz[v]) % mod;
            }
        }
        ans[u] = (ans[u] + sz[u]) % mod;
    }
    while (m --)
    {
        int x;
        scanf ("%d", &x);
        printf ("%d\n", ans[x]);
    }
    return 0;
}