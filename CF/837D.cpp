#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int inf = 205;
const int binf = 6005;
int dp[5][inf][binf], n2[inf], n5[inf]; //设f[i][j][k]为在前i个数里选择j个，其中包含k个质因数5时，最多的质因数2的个数。
int main ()
{
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
    	ll x;
    	scanf ("%lld", &x);
    	// while (x % 2 == 0)
		while ((x & 1) == 0)
    	{
    		n2[i] ++;
    		x /= 2;
		}
		while (x % 5 == 0)
		{
			n5[i] ++;
			x /= 5;
		}
	}
    // for (int i = 0; i <= n; i ++)
    // {
    //     printf ("%d: %d %d\n", n2[i], n5[i]);
    // }
	memset (dp, -1, sizeof (dp));
//	printf ("HELLO LINE 30\n");
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j <= m; j ++)
		{
			for (int k = 0; k <= 6000; k ++)
			{
				dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
				if (
					j >= 1 &&
					k >= n5[i] &&
					dp[(i + 1) % 2][j - 1][k - n5[i]] != -1
				)
				{
					dp[i % 2][j][k] = max (dp[i % 2][j][k], dp[(i - 1) % 2][j - 1][k - n5[i]] + n2[i]);
				}
			}
		}
	}
	int ans = 0;
	for (int k = 0; k < 6000; k ++)
	{
		ans = max (ans, min(k, dp[n % 2][m][k]));
	}
	printf("%d\n", ans);
	return 0;
}