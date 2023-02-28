#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int inf = 10005;

int n, m, k, a[inf], field[inf][inf];

int f (int x)
{
    double ans = 0;
    for (int i = 0; i <= k; i ++)
    {
        ans += double (a[i]) * pow (x, i);
    }
    if (ans > floor (ans)) return -1;
    return int (ans);
}

int main ()
{
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= k; i ++)
    {
        scanf ("%d", &a[i]);
    }
    for (int i = 0; i < n; i ++)
    {
        int v = f(i);
        if (v >= 0 && v < m)
        {
            field[v + 1][i + 1] = 1;
        }
    }
    for (int i = n; i > 0; i --)
    {
        for (int j = 1; j <= m; j ++)
        {
            if (field[i][j] == 0) printf (".");
            else printf ("*");
        }
        printf ("\n");
    }
    return 0;
}