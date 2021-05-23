#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int inf = 55;
int n, t;
int dp[5000005];
int v[5000005], w[5000005];

int main ()
{
    int nn = 0;
    scanf ("%d%d", &n, &t);
    for (int i = 1; i <= n; i ++)
    {
        int a, b, c, d, g;
        scanf ("%d%d%d%d", &a, &b, &c, &d);
        g = c / d;
        if (c % d != 0)
        {
            g ++;
        }
        for (int j = 1; j < g; j ++)
        {
            ++ nn;
            v[nn] = b * d;
            w[nn] = a;
        }
        ++ nn;
        v[nn] = b * ((c % d) == 0?d:(c % d));
        w[nn] = a;
    }
    for (int i = 1; i <= nn; i ++)
    {
        for (int j = t; j >= w[i]; j --)
        {
            dp[j] = max (dp[j], dp[j - w[i]] + v[i]);
        }
    }
    printf ("%d\n", dp[t]);
    return 0;
}