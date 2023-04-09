#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int inf = 5005;

int n, m, s, t, vis[inf], ans = 2147483647;

vector <int> adj[inf];

void dfs (int u, int f, int l)
{
    if (l > ans) return;
    if (u == t) 
    {
        ans = min (ans, l);
        return;
    }
    for (int i = 0; i < adj[u].size (); i ++)
    {
        int v = adj[u][i];
        if (v != f && ! vis[v])
        {
            vis[v] = true;
            dfs (v, u, l + 1);
            vis[v] = false;
        }
    }
}

int main ()
{
    scanf ("%d%d%d%d", &n, &m, &s, &t);
    int u, v;
    for (int i = 1; i <= m; i ++)
    {
        scanf ("%d%d", &u, &v);
        adj[u].push_back (v), adj[v].push_back (u);
    }
    vis[s] = true;
    dfs (s, 0, 0);
    if (ans == 2147483647) printf ("No path\n");
    else printf ("%d\n", ans);
    return 0;
}