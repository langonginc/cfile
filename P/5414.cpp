#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 105;
int a[inf], dp[inf], n, sum;

int main ()
{
    int t;
    scanf ("%d", &t);
    while (t --)
    {
        memset (dp, 0, sizeof (dp));
        sum = 0;
        scanf ("%d", &n);
        for (int i = 1; i <= n; i ++)
        {
            scanf ("%d", &a[i]);
            sum += a[i];
        }
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j < i; j ++)
            {
                if (a[i] >= a[j])
                {
                    dp[i] = max (dp[i], dp[j]);
                }
            }
            dp[i] += a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            ans = max (ans, dp[i]);
        }
        printf ("%d\n", sum - ans);
    }
    return 0;
}