#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 5e5 + 5;

class Node
{
    public:
    int to, next;
    Node () {}
    Node (int _to, int _next)
    {
        to = _to, next = _next;
    }
};

int n, m, head[inf], nn;
Node pool[inf];

int col[inf], sum[5], ans;

void addEdge (int u, int v)
{
    pool[++ nn] = Node (v, head[u]);
    head[u] = nn;
}

bool dfs (int u, int cid)
{
    col[u] = cid;
    sum[cid] ++;
    for (int i = head[u]; i; i = pool[i].next)
    {
        int v = pool[i].to;
        if (col[v] != -1 && col[v] == col[u])
        {
            return false;
        }
        if (col[v] == -1 && dfs (v, cid ^ 1) == false)
        {
            return false;
        }
    }
    return true;
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        scanf ("%d%d", &u, &v);
        addEdge (u, v), addEdge (v, u);
    }
    memset (col, 0xff, sizeof (col));
    for (int i = 1; i <= n; i ++)
    {
        if (col[i] == -1)
        {
            memset (sum, 0, sizeof (sum));
            if (dfs (i, 0) == false)
            {
                printf ("Impossible\n");
                return 0;
            }
            ans += min (sum[0], sum[1]);
        }
    }
    printf ("%d\n", ans);
    return 0;
}
