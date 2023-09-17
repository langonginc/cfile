#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 105;

ll p[maxn], q[maxn], r[maxn], b[maxn];
ll n;

ll inDegree[maxn];

ll gcd (ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

ll dfs (ll u)
{
    if (u == 0) return 1;
    ll nowR = dfs (r[u]);
    ll nowB = dfs (b[u]);
    ll g = gcd (p[u], q[u]);
    ll ans = p[u] / g + q[u] / g;
    ans = ans * nowR * nowB / gcd (nowR, nowB);
    return ans;
}

int main ()
{
    scanf ("%lld", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld%lld%lld%lld", &p[i], &q[i], &r[i], &b[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        if (r[i] != 0) inDegree[r[i]] ++;
        if (b[i] != 0) inDegree[b[i]] ++;
    }
    for (ll i = 1; i <= n; i ++)
    {
        if (inDegree[i] == 0)
        {
            printf ("%lld\n", dfs (i));
        }
    }
    return 0;
}