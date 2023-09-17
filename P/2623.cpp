#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 105;

int n, m, x[maxn], a[maxn], b[maxn], c[maxn], dp[500005];

vector <int> v;
vector <int> w;

int main ()
{
    scanf ("%d%d", &n, &m);
    v.push_back (0);
    w.push_back (0);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &x[i]);
        if (x[i] == 1) 
        {
            scanf ("%d%d", &a[i], &b[i]);
            for (int j = 1; j <= m; j ++)
            {
                v.push_back (j);
                w.push_back (a[i] * j * j - b[i] * j);
            }
        }
        if (x[i] == 2)
        {
            scanf ("%d%d%d", &a[i], &b[i], &c[i]);
            int p;
            for (p = 1; (p << 1) - 1 <= c[i]; p <<= 1)
            {
                v.push_back (p * b[i]);
                w.push_back (p * a[i]);
            }
            int r = c[i] - p;
            v.push_back (r * b[i]);
            w.push_back (r * a[i]);
        }
        if (x[i] == 3) 
        {
            scanf ("%d%d", &a[i], &b[i]);
            for (int p = 1; ((p << 1) - 1) <= m; p <<= 1)
            {
                v.push_back (p * b[i]);
                w.push_back (p * a[i]);
            }
        }
    }
    for (int i = 1; i < v.size(); i ++)
    {
        for (int j = m; j >= v[i]; j --)
        {
            dp[j] = max (dp[j], w[i] + dp[j - v[i]]);
        }
    }
    printf ("%d\n", dp[m]);
    return 0;
}