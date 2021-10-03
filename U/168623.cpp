/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
const int inf = 1e5 + 5;
ll a[inf], pre[inf], n, q, ans;

int main ()
{
    scanf ("%lld%lld", &n, &q);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    while (q --)
    {
        ll k;
        ans = INT_MAX;
        scanf ("%lld", &k);
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= i; j ++)
            {
                // if ((a[i] < k && a[j] < a[i]) || (a[i] > k && a[j] > a[i])) continue;
                ans = min(ans, abs(pre[i] - pre[j] - k));
            }
        }
        printf ("%lld\n", ans);
    }
    return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <cstring>
// #include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
const int inf = 1e5 + 5;
ll a[inf], pre[inf], n, q, ans;

inline ll myabs (ll a)
{
    return a > 0 ? a : -a;
}

int main ()
{
    scanf ("%lld%lld", &n, &q);
    for (ll i = 1; i <= n; i ++)
    {
        scanf ("%lld", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    while (q --)
    {
        ll k;
        ans = LLONG_MAX;
        scanf ("%lld", &k);
        ll l = 1, sum = 0;
        for (ll r = 1; r <= n; r ++)
        {
            sum = pre[r] - pre[l - 1];
            ans = min(ans, myabs(sum - k));
            while (sum > k)
            {
                sum = pre[r] - pre[l ++ ];
                if (l <= r)
                    ans = min(ans, myabs(sum - k));
            }
        }
        printf ("%lld\n", ans);
    }
    return 0;
}
