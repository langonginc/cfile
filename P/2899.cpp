#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int INF = 1e9 + 7;
const int inf = 10005;

class Edge
{
    public:
    int to, next;
    Edge () {}
    Edge (int to, int next) : to(to), next(next) {}
} pool[inf * 4];

int n, head[inf], nn, dp[inf][5];

inline void addEdge (int u, int v)
{
    pool[++ nn] = Edge (v, head[u]);
    head[u] = nn;
}

void dfs (int u, int f)
{
    dp[u][0] = 0, dp[u][1] = 1, dp[u][2] = INF;
    for (int i = head[u]; i; i = pool[i].next)
    {
        int v = pool[i].to;
        if (v != f)
        {
            dfs (v, u);
            dp[u][0] += min (dp[v][1], dp[v][2]);
            dp[u][1] += min (min (dp[v][0], dp[v][1]), dp[v][2]);
        }
    }
    for (int i = head[u]; i; i = pool[i].next)
    {
        int v = pool[i].to;
        if (v != f)
        {
            dp[u][2] = min (dp[u][2], dp[u][0] + dp[v][1] - min (dp[v][1], dp[v][2]));
        }
    }
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i < n; i ++)
    {
        int a, b;
        scanf ("%d%d", &a, &b);
        addEdge (a, b);
        addEdge (b, a);
    }
    dfs (1, 0);
    printf ("%d", min (dp[1][1], dp[1][2]));
    return 0;
}