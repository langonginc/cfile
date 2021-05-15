#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 65;
int dp[inf][inf];
int n, m;

int main ()
{
    scanf ("%d%d", &n, &m);
    dp[0][1] = 1;
    for (int i = 1; i <= m; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (j == 1)
            {
                dp[i][j] = dp[i - 1][n] + dp[i - 1][j + 1];
            }
            else if (j == n)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
        }
    }
    printf ("%d\n", dp[m][1]);
    return 0;
}