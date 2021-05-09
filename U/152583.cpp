#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll inf = 100005;
ll l, n, k;
ll a[inf];

bool check (ll x)
{
    ll res = 0;
    for (int i = 1; i < n; i ++)
    {
        ll len = a[i + 1] - a[i];
        if (len > x)
        {
            res += len / x;
            if (len % x == 0)
            {
                res --;
            }
        }
    }
    return res <= k;
}

int main ()
{
    scanf ("%lld%lld%lld", &l, &n, &k);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    ll left = 1, right = l, mid = 0, ans = 0;
    while (left < right)
    {
        mid = (left + right) >> 1;
        if (check (mid))
        {
            ans = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    printf ("%d\n", ans);
    return 0;
}
