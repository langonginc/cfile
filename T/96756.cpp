#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = 1005;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int f[inf][inf];
int color[inf][inf];
int colorc, n, s;
int maxs, maxd;
int mx, my, mc;
bool vis[inf][inf];

void dfs (int x, int y)
{
    color[x][y] = colorc;
    s ++;
    // printf ("[INFO] UPDATE in (%d, %d)\n", x, y);
    for (int i = 0; i < 4; i ++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx > 0 && yy > 0 && xx <=n && yy <= n && f[xx][yy] && !color[xx][yy])
        {
            dfs (xx, yy);
        }
    }
}

void dfs2 (int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; i ++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx > 0 && yy > 0 && xx <=n && yy <= n && f[xx][yy])
        {
            if (!vis[xx][yy])
                dfs2 (xx, yy);
        }
        else
        {
            maxd ++;
        }
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
            {
                f[i][j] = 0;
            }
            else
            {
                f[i][j] = 1;
            }
        }
    }
    // for (int i = 1; i <= n; i ++)
    // {
    //     for (int j = 1; j <= n; j ++)
    //     {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (f[i][j] && !color[i][j])
            {
                colorc ++;
                s = 0;
                dfs (i, j);
                // maxs = max(s, maxs);
                if (s > maxs)
                {
                    maxs = s;
                    mx = i, my = j;
                    mc = colorc;
                }
            }
        }
    }
    // for (int i = 1; i <= n; i ++)
    // {
    //     for (int j = 1; j <= n; j ++)
    //     {
    //         cout << color[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << mx << " " << my << endl;
    dfs2 (mx, my);
    // cout << maxs << " " << maxd << endl;
    printf ("%d %d", maxs, maxd);
    return 0;
}
