#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 4005;

int n, a[inf], b[inf], c[inf], d[inf], bu[inf], s[inf], bun, sn, field[inf][inf];

inline int back (int x)
{
    return lower_bound (s + 1, s + sn + 1, x) - s;
}

inline int abs (int x)
{
    if (x > 0) return x;
    else return -x;
}

int main ()
{
    scanf ("%d", &n);
    bu[0] = - 1e8 - 5;
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        bu[++ bun] = a[i], bu[++ bun] = b[i], bu[++ bun] = c[i], bu[++ bun] = d[i];
    }
    sort (bu + 1, bu + bun + 1);
    for (int i = 1; i <= bun; i ++)
    {
        if (bu[i] != bu[i - 1])
        {
            s[++ sn] = bu[i];
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        a[i] = back (a[i]),
        b[i] = back (b[i]),
        c[i] = back (c[i]),
        d[i] = back (d[i]);
        printf ("%d %d %d %d\n", a[i], b[i], c[i], d[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        field[a[i]][d[i]] ++, field[c[i] + 1][b[i] + 1] ++;
        field[a[i]][b[i] + 1] --, field[c[i] + 1][d[i]] --;


        char fn[100] = "./Output-";
        char fd[100];
        sprintf(fd, "%d", i);
        strcat (fn, fd);
        strcat (fn, ".csv");
        freopen (fn, "w", stdout);
        for (int k = 0; k <= 2 * sn; k ++)
        {
            for (int j = 0; j <= 2 * sn; j ++)
            {
                printf ("%d,", field[k][j]);
            }
            printf ("\n");
        }
        // printf ("----------------\n");
    }
    long long ans = 0;
    for (int i = 1; i < inf; i ++)
    {
        for (int j = 1; j < inf; j ++)
        {
            field[i][j] += field[i - 1][j] + field[i][j - 1] - field[i - 1][j - 1];
            // if (field[i][j])
            // {
            //     ans ++;
            // }
        }
    }
    freopen ("./Output-ans.csv", "w", stdout);
    for (int i = 0; i <= 2 * sn; i ++)
    {
        for (int j = 0; j <= 2 * sn; j ++)
        {
            printf ("%d,", field[i][j]);
        }
        printf ("\n");
    }
    // printf ("----------------\n");
        freopen ("/dev/tty", "w", stdout);

    for (int i = 0; i < inf; i ++)
    {
        int line = 0;
        for (int j = 0; j < inf; j ++)
        {
            if (! line)
            {
                if (field[i][j])
                {
                    line = 1;
                }
            }
            if (line)
            {
                if (field[i][j])
                {
                    line ++;
                }
                else
                {
                    int left = j - line, right = j - 1;
                    int line_target = abs(s[right] - s[left] + 1);
                    printf ("tar %d\n", line_target);
                    if (abs (i - 1) + 1 == abs (i))
                    {
                        ans += line_target;
                    }
                    else
                    {
                        ans += (abs (i) - abs (i - 1)) * line_target;
                        printf ("hei %d\n", abs (i) - abs(i - 1));
                    }
                    line = 0;
                }
            }
        }
    }
    printf ("%lld\n", ans);
    return 0;
}