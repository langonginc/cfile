#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1005;
const int mod = 998244353;

int t, n, m, c, f, id, a[inf][inf], r[inf][inf], up[inf][inf], down[inf][inf];

int main ()
{
    scanf ("%d%d", &t, &id);
    while (t --)
    {
        memset (r, 0, sizeof (r));
        memset (up, 0, sizeof (up));
        memset (down, 0, sizeof (down));
        scanf ("%d %d %d %d\n", &n, &m, &c, &f);
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= m; j ++)
            {
                char ch;
                scanf ("%c", &ch);
                a[i][j] = ch - '0';
            }
            scanf ("\n");

            for (int j = m; j > 0; j --)
            {
                if (a[i][j] == 0)
                {
                    r[i][j] = r[i][j + 1] + 1;
                }
            }
        }

        for (int i = 3; i <= n; i ++)
        {
            for (int j = 1; j <= m; j ++)
            {
                if (a[i][j] == 0 && a[i - 1][j] == 0 && a[i - 2][j] == 0)
                {
                    up[i][j] = up[i - 1][j] + r[i - 2][j] - 1;
                }
            }
        }

        for (int j = 1; j <= m; j ++)
        {
            if (a[n][j] == 0) down[n][j] = 1;
            for (int i = n - 1; i > 0; i --)
            {
                if (a[i][j] == 0) down[i][j] = down[i + 1][j] + 1;
            }
        }

        int ansc = 0, ansf = 0;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= m; j ++)
            {
                ansc = (ansc + (1ll * up[i][j] * (r[i][j] - 1)) % mod) % mod;
                ansf = (ansf + (1ll * up[i][j] * (r[i][j] - 1) * (down[i][j] - 1)) % mod) % mod;
            }
        }
        printf ("%d %d\n", (1ll * ansc * c) % mod, (1ll * ansf * f) % mod);
    }
    return 0;
}