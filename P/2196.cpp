#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 25;

bool conn[inf][inf], vis[inf];
int a[inf], path[inf], ans[inf], c;
int n, vmax;

inline bool func (int x)
{
    for (int i = 1; i <= n; i ++)
    {
        if (conn[x][i] && !vis[i])
        {
            return false;
        }
    }
    return true;
}

void dfs (int x, int step, int sum)
{
    if (func (x))
    {
        if (vmax < sum)
        {
            vmax = sum;
            c = step;
            for (int i = 1; i <= step; i ++)
            {
                ans[i] = path[i];
            }
        }
        return;
    }
    for (int i = 1; i <= n; i ++)
    {
        if (conn[x][i] && !vis[i])
        {
            vis[i] = true;
            path[step + 1] = i;
            dfs (i, step + 1, sum + a[i]);
            vis[i] = false;
        }
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i ++)
    {
        for (int j = i + 1; j <= n; j ++)
        {
            cin >> conn[i][j];
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        vis[i] = true;
        path[1] = i;
        dfs (i, 1, a[i]);
        vis[i] = false;
    }
    for (int i = 1; i <= c; i ++)
    {
        printf ("%d ", ans[i]);
    }
    printf ("\n");
    printf ("%d\n", vmax);
    return 0;
}
