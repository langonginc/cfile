#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 1e7 + 1;
const int Mod = 1e9 + 7;
int n, m;
ll ans;

int main ()
{
    ll a[4], b[4], p[4];
    p[1] = 1, p[2] = 1, p[3] = 1;
    scanf ("%d%d%lld%lld%lld%lld%lld%lld", &n, &m, &a[1], &b[1], &a[2], &b[2], &a[3], &b[3]);
    for (int k = 1; k <= m; k ++)
    {
        int pos = 0;
        ll smin = LLONG_MAX;
        for (int i = 1; i <= 3; i ++)
        {
            if (p[i] <= n && p[i] * a[i] + b[i] < smin)
            {
                pos = i, smin = p[i] * a[i] + b[i];
            }
        }
        ans = (ans + smin) % Mod;
        p[pos] ++;
    }
    printf ("%lld", ans % Mod);
    return 0;
}