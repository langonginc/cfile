#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
const int inf = 25;

int n, match[inf], g[inf][inf], z;
int visx[inf], visy[inf];
int topx[inf], topy[inf];

bool find (int u)
{
    visx[u] = true;
    for (int i = 1; i <= n; i ++)
    {
        if (visy[i] == false)
        {
            int gap = topx[u] + topy[i] - g[u][i];
            if (gap == 0)
            {
                visy[i] = true;
                if (match[i] == 0 || find (match[i]))
                {
                    match[i] = u;
                    return true;
                }
            }
            else if (gap > 0)
            {
                z = min (z, gap);
            }
        }
    }
    return false;
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            scanf ("%d", &g[i][j]);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            int x;
            scanf ("%d", &x);
            g[j][i] *= x;
        }
    }
    // memset (match, 0xff, sizeof (match));
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            topx[i] = max (topx[i], g[i][j]);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        while (true)
        {
            z = INT_MAX;
            memset (visx, 0, sizeof (visx));
            memset (visy, 0, sizeof (visy));
            if (find (i)) break;
            for (int j = 1; j <= n; j ++)
            {
                if (visx[j])
                {
                    topx[j] -= z;
                }
            }
            for (int j = 1; j <= n; j ++)
            {
                if (visy[j])
                {
                    topy[j] += z;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        ans += g[match[i]][i];
    }
    printf ("%d\n", ans);
    return 0;
}