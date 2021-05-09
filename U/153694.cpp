#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 5005;

ll n, a[inf], dp[inf][inf];

ll dfs (ll x, ll y, ll k)
{
    if (x >= y)
    {
        return a[x] / k;
    }
    if (dp[x][y]) return dp[x][y];
    return dp[x][y] = max (dp[x][y], max (dfs(x + 1, y, k + 1) + a[x] / k, dfs(x, y - 1, k + 1) + a[y] / k));
}

int main ()
{
    scanf ("%lld", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &a[i]);
    }
    printf ("%lld", dfs(1, n, 1));
    return 0;
}