#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 505;
const int enf = 5e4 + 5;

int n, m, k, match[inf], ans;
bool vis[inf], g[inf][inf];

bool find (int u)
{
    for (int i = 1; i <= m; i ++)
    {
        if (g[u][i] && vis[i] == false)
        {
            vis[i] = true;
            if (match[i] == 0 || find (match[i]))
            {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}

int main ()
{
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i ++)
    {
        int u, v;
        scanf ("%d%d", &u, &v);
        g[u][v] = 1;
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