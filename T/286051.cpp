#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int inf = 5e5 + 5;
const double g = 9.8;

int n, m, x[inf], y[inf], v[inf];
long long ans;
double s[inf];

class Pointg
{
    public:
    int p, a;
    bool operator < (const Pointg &x) const
    {
        if (p > 0 && x.p > 0)
        return max (p - a, 0) + x.p < max (x.p - x.a, 0) + p;
        if (p > 0 || x.p > 0) return p > x.p;
        return true;
    }
} d[inf];

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d%d", &x[i], &y[i], &v[i]);
        s[i] = 1.0 * x[i] + 1.0 * v[i] * sqrt (2.0 * y[i] / g);
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &d[i].a);
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = i + 1; j <= n; j ++)
        {
            if (y[i] == y[j] && (s[i] - s[j]) * (x[i] - x[j]) < 0)
            {
                d[i].p ++, d[j].p ++;
            }
        }
    }
    sort (d + 1, d + n + 1);
    for (int i = 1; i <= m; i ++)
    {
        ans += max (0, d[i].p - d[i].a);
    }
    for (int i = m + 1; i <= n; i ++)
    {
        ans += d[i].p;
    }
    printf ("%lld\n", ans);
    return 0;
}