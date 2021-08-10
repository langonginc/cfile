#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 1000005;

int n, lc[inf], rc[inf], size[inf], val[inf], ans;

void dfs (int u)
{
    size[u] = 1;
    if (lc[u] != -1)
    {
        dfs (lc[u]);
        size[u] += size[lc[u]];
    }
    if (rc[u] != -1)
    {
        dfs (rc[u]);
        size[u] += size[rc[u]];
    }
}

bool check (int l, int r)
{
    if (
        (l == -1 && r == -1) || 
        (
            l != -1 && r != -1 &&
            val[l] == val[r] &&
            check (lc[l], rc[r]) && check (lc[r], rc[l])
        )
    ){
        return true;
    }
    return false;
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &val[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d", &lc[i], &rc[i]);
    }
    dfs (1);
    for (int i = 1; i <= n; i ++)
    {
        if (check (lc[i], rc[i]))
        {
            ans = max (ans, size[i]);
        }
    }
    printf ("%d\n", ans);
    return 0;
}