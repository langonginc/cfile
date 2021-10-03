#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main ()
{
    int t, n, m, f[105][105], a[105], b[105], c[105], d[105];
    scanf ("%d", &t);
    while (t --)
    {
        bool flag=  false;
        scanf ("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++)
            scanf ("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        if (m & 1)
        {
            printf ("NO\n");
            continue;
        }
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n ; j ++)
                if (b[i] == c[i] && a[i] == a[j] && d[i] == d[j])
                    flag = true;
        if (flag) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}