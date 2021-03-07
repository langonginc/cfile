#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int inf = 1005;

int adj[inf][inf];
int n;
int dp[inf];

int dfs (int x)
{
    if (dp[x] > 0)
    {
        return dp[x];
    }
    dp[x] = 1;
    for (int i = 1; i <= n; i ++)
    {
        if (adj[x][i])
        {
            dp[x] = max (dp[x], dfs(i) + 1);
        }
    }
    return dp[x];
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int x, y;
        scanf ("%d%d", &x, &y);
        adj[x][y] = 1;
    }
    for (int i = 1; i <= n; i ++)
    {
        if (dp[i] == 0)
        {
            dfs (i);
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i ++)
    {
        mx = max (mx, dp[i]);
    }
    printf ("%d\n", mx);
    return 0;
}
