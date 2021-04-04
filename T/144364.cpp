#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = 500005;

int n, T;
int dp[inf];
int p[inf], c[inf], t[inf];

int main ()
{
    int h1, m1, h2, m2;
    scanf ("%d:%d%d:%d%d", &h1, &m1, &h2, &m2, &n);
    int h = h2 - h1;
    int m = (h * 60) + m2 - m1;
    T = m;
    // cout << T;
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d%d", &t[i], &c[i], &p[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = T; j >= 0; j --)
        // for (int j = 0; j <= T; j ++)
        {
            int nw = 0;
            for (int k = 0; k * t[i] <= j && k <= ((p[i] == 0)?(inf):(p[i])); k ++)
            {
                if (j - t[i] * k >= 0)
                    nw = max (nw, dp[j - t[i] * k] + c[i] * k);
            }
            dp[j] = max (dp[j], nw);
            // printf ("CASE i %d, j %d: dp[%d]=%d\n", i, j, j, dp[j]);
        }
    }
    // int ans = 0;
    // for (int i = 0; i <= T; i ++)
    // {
    //     ans = max (ans, dp[i]);
    // }
    printf ("%d\n", dp[T]);
    // printf ("%d\n", ans);
    return 0;
}