#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 1000005;

/*

f[x][0]: 
-*
-*

f[x][1]:
-**
-*0

f[x][2]:
-*0
-**

*/

int n, dp[inf][3];

int main ()
{
    scanf ("%d", &n);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 2][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 2][0] + dp[i - 1][1];
        dp[i][0] %= 10000;
        dp[i][1] %= 10000;
        dp[i][2] %= 10000;
    }
    printf ("%d\n", dp[n][0]);
    return 0;
}