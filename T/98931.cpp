#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = 1005;

int dp[inf], t[inf], f[inf], h[inf];
int n, d;

int main ()
{
    scanf ("%d%d", &d, &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d%d", &t[i], &f[i], &h[i]);
    }
    dp[0] = 10;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = d; j > 0; j --)
        {
            if (dp[j] >= t[j])
            {
                if (j + h[j] >= d)
                {
                    printf ("%d\n", t[i]);
                    return 0;
                }
                dp[j + h[i]] = max (dp[j + h[i]], dp[j]);
                dp[j] = max (dp[j], dp[j] + t[i]);
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < inf; i ++)
    {
        mx = max(mx, dp[i]);
    }
    printf ("%d\n", mx);
    return 0;
}
