#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int inf = 205;
const int infm = 25;

int n, m, dp[inf][infm][805];
int a[inf], b[inf];

int main ()
{
    memset (dp, ~0x3f, sizeof(dp));
    for (int i = 0; i <= n; i ++)
    {
        dp[i][0][400] = 0;
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            for (int k = 0; k <= 800; k ++)
            {
                if (k + b[i] - a[i] < 0)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
                else
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - 1][k + b[i] - a[i]] + a[i] + b[i]);
                }
            }
        }
    }
    int diff = 0, sum = 0;
    for (int i = 0; i <= 400; i ++)
    {
        if (dp[n][m][400 - i] > 0 || dp[n][m][400 + i] > 0)
        {
            diff = i;
            sum = max(dp[n][m][400 - i], dp[n][m][400 + i]);
            break;
        }
    }
    cout << diff << endl << sum << endl;
    return 0;
}
