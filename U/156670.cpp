#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 1000005;
ll n, d, a[inf], ans;

// template <class T> T abs (T x)
// {
//     if (x > 0) return x;
//     else return -x;
// }

int main ()
{
    scanf ("%lld%lld", &n, &d);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &a[i]);
    }
    sort (a + 1, a + n + 1);
    ll x;
    // for (int i = 1; i <= n - 2; i ++)
    // {
    //     x = a[i + 2] - a[i];
    //     if (x <= d)
    //     {
    //         ans ++;
    //     }
    // }
    // int l = 1, m = 2, r = 3;
    // while (r <= n)
    // {
    //     while (l >= m) m ++;
    //     while (m >= r) r ++;
    //     if (r > n) break;
    //     x = a[r] - a[l];
    //     if (x < d)
    //     {
    //         printf (" < %d - %d - %d : %d\n", l, m, r, x);
    //         ans ++;
    //         r ++;
    //     }
    //     else if (x == d)
    //     {
    //         printf (" = %d - %d - %d : %d\n", l, m, r, x);
    //         ans ++;
    //         if (m + 1 < r) m ++;
    //         else l ++;
    //     }
    //     else
    //     {
    //         printf (" >!%d - %d - %d : %d\n", l, m, r, x);
    //         l ++;
    //     }
    // }
    for (int i = 1; i <= n - 1; i ++)
    {
        ll r = i;
        while (r <= n && a[r] - a[i] <= d) r ++;
        ll m = r - i - 1;
        if (m >= 2)
        {
            ans += (m - 1) * m / 2;
        }
    }
    printf ("%lld\n", ans);
    return 0;
}