#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 105;

string s;
int n, dp[inf][inf];

int main ()
{
    cin >> s;
    n = s.length ();
    memset (dp, 0x3f, sizeof (dp));
    for (int k = 0; k <= n; k ++)
    {
        for (int i = 0; i < n - k; i ++)
        {
            int j = i + k;
            if (i == j) dp[i][j] = 1;
            else if (s[i] == s[j]) dp[i][j] = min (dp[i + 1][j], dp[i][j - 1]);
            else for (int m = i; m < j; m ++) 
            {
                dp[i][j] = min (dp[i][j], dp[i][m] + dp[m + 1][j]);
            }
        }
    }
    printf ("%d\n", dp[0][n - 1]);
    return 0;
}