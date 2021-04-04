#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = 1e6 + 5;
int n, s, t, ans;
int a[inf], dp[inf];

int main ()
{
    scanf ("%d%d%d", &n, &s, &t);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        int nv = 0;
        bool fl = true;
        for (int j = i - t; j <= i - s; j ++)
        {
            if (j < 0) continue;
            nv = max (nv, dp[j]);
            fl = false;
            // printf (" >> catch dp[%d]: %d\n", j, dp[j]);
        }
        if (fl) dp[i] = 0;
        else dp[i] = nv + a[i];
        ans = max (ans, dp[i]);
        // printf ("CASE %d: new %d, dp %d\n", i, nv, dp[i]);
    }
    printf ("%d\n", ans);
    return 0;
}