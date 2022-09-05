#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int inf = 3e5 + 5;

class Edge
{
    public:
    int v, id;
    ll w;
    bool used;
    bool dire;
    Edge (int _v, ll _w, int _id, bool _used, bool _dire)
    {
        v = _v, w = _w, id = _id, used = _used, dire = _dire;
    }
};

int n, s, t, ans[inf];
ll dep[inf], sum;

vector <Edge> adj[inf];

void dfs1 (int u, int f, ll depth)
{
    // printf ("DEBUG dfs1 u=%d, f=%d\n", u, f);
    for (int i = 0; i < adj[u].size(); i ++)
    {
        if (adj[u][i].v == f)
        {
            adj[u][i].used = true;
            dep[u] = depth;
        }
        else
        {
            dfs1 (adj[u][i].v, u, depth + adj[u][i].w);
        }
    }
}

void dfs2 (int u, int f, ll depth)
{
    // printf ("DEBUG dfs2 u=%d, f=%d, depth=%lld\n", u, f, depth);
    // printf ("DEBUG dfs2 dep[%d]=%lld\n", u, depth);
    dep[u] = depth;
    for (int i = 0; i < adj[u].size(); i ++)
    {
        // adj[u][i].used = !adj[u][i].used;
        // printf ("%d to %d as %d\n", u, adj[u][i].v, adj[u][i].used);
        if (adj[u][i].v != f)
        {
            adj[u][i].used = 0;
            // printf ("DEBUG dfs2 > to=%d, depth=%lld\n", adj[u][i].v, depth);
            if (adj[u][i].w + depth < dep[adj[u][i].v])
            {
                // printf ("DEBUG dfs2   > run dfs2\n");
                dfs2 (adj[u][i].v, u, depth + adj[u][i].w);
            }
        }
        else
        {
            adj[u][i].used = 1;
        }
    }
}

void dfs3 (int u, int f)
{
    sum += dep[u];
    // printf ("DEBUG dfs3 dep[%d]=%lld]\n", u, dep[u]);
    // printf ("DEBUG dfs3 u=%d, f=%d\n", u, f);
    for (int i = 0; i < adj[u].size(); i ++)
    {
        if (adj[u][i].dire)
        {
            if (adj[u][i].used)
            {
                ans[adj[u][i].id] = 1;
                // printf ("%d %d shun\n", u, adj[u][i].v);
                // sum += dep[u];
            }
        }
        else
        {
            if (adj[u][i].used)
            {
                ans[adj[u][i].id] = 2;
                // printf ("%d %d ni\n", u, adj[u][i].v);
                // sum += dep[u];
            }
        }
        if (adj[u][i].v != f) dfs3 (adj[u][i].v, u);
    }
}

int main ()
{
    scanf ("%d%d%d", &n, &s, &t);
    int u, v;
    ll w;
    for (int i = 1; i < n; i ++)
    {
        scanf ("%d%d%lld", &u, &v, &w);
        adj[u].push_back (Edge (v, w, i, false, true));
        adj[v].push_back (Edge (u, w, i, false, false));
    }
    dfs1 (s, 0, 0);
    dfs2 (t, 0, 0);
    dfs3 (1, 0);
    printf ("%lld\n", sum);
    for (int i = 1; i < n; i ++)
    {
        printf ("%d", ans[i]);
    }
    printf ("\n");
    return 0;
}