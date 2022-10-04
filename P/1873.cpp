#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 1e6 + 5;

ll n, m, a[inf], maxlen;

bool check (int h)
{
    ll sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] > h) sum += a[i] - h;
    }
    return sum >= m;
}

int main ()
{
    scanf ("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &a[i]);
        maxlen = max (maxlen, a[i]);
    }
    ll l = 0, r = maxlen + 5, mid, ans;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check (mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf ("%lld\n", ans);
    return 0;
}