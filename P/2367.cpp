#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
const int inf = 5e6 + 5;

int n, m, a[inf], b[inf], x, y, z, ans = INT_MAX;

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
        b[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= m; i ++)
    {
        scanf ("%d%d%d", &x, &y, &z);
        b[x] += z, b[y + 1] -= z;
    }
    for (int i = 1; i <= n; i ++)
    {
        b[i] += b[i - 1];
        ans = min (ans, b[i]);
    }
    printf ("%d\n", ans);
    return 0;
}