#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int inf = 205;

int n, m, match[inf], vis[inf], ans;
vector <int> adj[inf];

bool find (int u)
{
    for (int i = 0; i < adj[u].size (); i ++)
    {
        int v = adj[u][i];
        if (vis[v] == false)
        {
            vis[v] = true;
            if (match[v] == 0 || find (match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        int k, x;
        scanf ("%d", &k);
        for (int j = 1; j <= k; j ++)
        {
            scanf ("%d", &x);
            adj[i].push_back (x);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        memset (vis, 0, sizeof (vis));
        if (find (i))
        {
            ans ++;
        }
    }
    printf ("%d\n", ans);
    return 0;
}