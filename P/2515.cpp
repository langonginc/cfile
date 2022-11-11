#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 1005;
const int Inf = 5005;

class Edge
{
    public:
    int to, next;
    Edge () {}
    Edge (int _to, int _next)
    {
        to = _to, next = _next;
    }
} ori[inf], dag[inf];

int n, m, head_ori[inf], head_dag[inf], v[inf], w[inf], cst[inf], val[inf], dp[inf][Inf], low[inf], dfn[inf], hep[inf], vis[inf], scc[inf], depend[inf], used[inf], hep_top, ori_cnt, dag_cnt, timectl, scc_cnt;

void addEdge_origin (int u, int v)
{
    ori[++ ori_cnt] = Edge (v, head_ori[u]);
    head_ori[u] = ori_cnt;
}

void addEdge_dag (int u, int v)
{
    dag[++ dag_cnt] = Edge (v, head_dag[u]);
    head_dag[u] = dag_cnt;
}

void tarjan (int u)
{
    low[u] = dfn[u] = ++ timectl;
    hep[++ hep_top] = u;
    vis[u] = true;
    for (int i = head_ori[u]; i != -1; i = ori[i].next)
    {
        int v = ori[i].to;
        if (! dfn[v])
        {
            tarjan (v);
            low[u] = min (low[u], low[v]);
        }
        else if (vis[v])
        {
            low[u] = min (low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        ++ scc_cnt;
        vis[u] = false;
        while (hep[hep_top + 1] != u)
        {
            scc[hep[hep_top]] = scc_cnt;
            vis[hep[hep_top --]] = false;
        }
    }
}

void dfs (int u)
{
    for (int i = cst[u]; i <= m; i ++)
    {
        dp[u][i] = val[u];
    }
    for (int i = head_dag[u]; i != -1; i = dag[i].next)
    {
        int v = dag[i].to;
        dfs (v);
        for (int j = m - cst[u]; j >= 0; j --)
        {
            for (int k = 0; k <= j; k ++)
            {
                dp[u][j + cst[u]] = max (dp[u][j + cst[u]], dp[u][j + cst[u] - k] + dp[v][k]);
            }
        }
    }
}

int main ()
{
    scanf ("%d%d", &n, &m);
    memset (head_ori, -1, sizeof (head_ori));
    memset (head_dag, -1, sizeof (head_dag));
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &w[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &v[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &depend[i]);
        if (depend[i] != 0) addEdge_origin (depend[i], i);
    }
    for (int i = 1; i <= n; i ++)
    {
        if (! dfn[i])
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        val[scc[i]] += v[i];
        cst[scc[i]] += w[i];
        if (scc[i] != scc[depend[i]] && depend[i] != 0)
        {
            addEdge_dag (scc[depend[i]], scc[i]);
            used[scc[i]] ++;
        }
    }
    int root = scc_cnt + 1;
    for (int i = 1; i <= scc_cnt; i ++)
    {
        if (! used[i]) addEdge_dag (root, i);
    }
    dfs (root);
    printf ("%d\n", dp[root][m]);
    return 0;
}