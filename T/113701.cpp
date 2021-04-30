#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 105;
int a[inf], dp[inf][inf], n;
int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &dp[1][i]);
    }
    for (int i = 2; i <= n; i ++)
    {
        for (int j = 1; j <= n - i + 1; j ++)
        {
            dp[i][j] = max (dp[i - 1][j + 1] + dp[i - 1][j], dp[i - 1][j]);
            printf ("%d, %d: %d\n", i, j, dp[i][j]);
        }
    }
    printf ("%d", dp[n][1]);
    return 0;
}