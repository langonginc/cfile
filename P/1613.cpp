#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 55;

int n, m, dp[inf][inf][75], dis[inf][inf];

int main ()
{
    scanf ("%d%d", &n, &m);
    memset (dis, 0x3f, sizeof (dis));
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        scanf ("%d%d", &u, &v);
        dp[u][v][0] = true;
        dis[u][v] = 1;            
    }
    for (int s = 1; s <= 64; s ++)
    {
        for (int k = 1; k <= n; k ++)
        {
            for (int i = 1; i <= n; i ++)
            {
                for (int j = 1; j <= n; j ++)
                {
                    if (dp[i][k][s - 1] && dp[k][j][s - 1])
                    {
                        dp[i][j][s] = true;
                        dis[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int k = 1; k <= n; k ++)
    {
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= n; j ++)
            {
                dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    printf ("%d\n", dis[1][n]);
    return 0;
}