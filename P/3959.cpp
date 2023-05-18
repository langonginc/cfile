#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int maxN = 13;
const int maxM = 1e3 + 5;
const ll maxV = 1e18;

template <typename T>
inline T lowbit (T x)
{
    return x & -x;
}

ll g[maxN][maxN], dp[maxN][maxN][1 << maxN];
ll n, m;

int state[maxN], stateID[1 << maxN];

bool vis[maxN][maxN][1 << maxN];

ll dpFunc (int pos, int dis, int set)
{
    if (set == 0)
    {
        return dp[pos][dis][set] = 0;
    }

    if (vis[pos][dis][set])
    {
        return dp[pos][dis][set];
    }
    vis[pos][dis][set] = true;
    ll &ans = dp[pos][dis][set];
    for (int subSet = set; subSet > 0; subSet = (subSet - 1) & set)
    {
        for (int i = subSet; i > 0; i -= lowbit (i))
        {
            int next = stateID[lowbit (i)];
            if (g[pos][next] < maxV)
            {
                int remainSet = set ^ subSet;
                ans = min (ans, dpFunc (pos, dis, remainSet) + dis * g[pos][next] + dpFunc (next, dis + 1, subSet & (~ state[next])));
            }
        }
    }
    return ans;
}

int main ()
{
    memset (g, 0x3f, sizeof (g));
    scanf ("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int x, y;
        ll v;
        scanf ("%d%d%lld", &x, &y, &v);
        g[x][y] = min (g[x][y], v);
        g[y][x] = min (g[y][x], v);
    }

    for (int i = 1; i <= n; i ++)
    {
        stateID[1 << (i - 1)] = i;
        state[i] = 1 << (i - 1);
    }

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            for (int s = 0; s < (1 << n); s ++)
            {
                dp[i][j][s] = maxV;
            }
        }
    }

    ll ans = maxV;
    for (int i = 1; i <= n; i ++)
    {
        ans = min (ans, dpFunc (i, 1, ((1 << n) - 1) & (~ state[i])));
    }
    printf ("%lld\n", ans);
    return 0;
}