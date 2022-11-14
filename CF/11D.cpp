#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 600005;

inline int lowbit (int x)
{
    return x & -x;
}

ll n, m, dp[inf][20], ans;
bool g[20][20];

int main ()
{
    scanf ("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        scanf ("%d%d", &u, &v);
        g[u - 1][v - 1] = true, g[v - 1][u - 1] = true;
    }
    for (int i = 0; i < n; i ++)
    {
        dp[1 << i][i] = 1;
    }
    for (int i = 1; i <= (1 << n); i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (!dp[i][j]) continue;
            for (int k = 0; k < n; k ++)
            {
                if (!g[j][k]) continue;
                if (lowbit (i) <= (1 << k))
                {
                    if ((1 << k) & i)
                    {
                        if ((1 << k) == lowbit (i))
                        {
                            ans += dp[i][j];
                        }
                    }
                    else
                    {
                        dp[i | (1 << k)][k] += dp[i][j];
                    }
                }
            }
        }
    }
    printf ("%lld\n", (ans - m) >> 1);
    return 0;
}