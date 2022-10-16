#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int inf = 1e6 + 5;
const ll moder = 11451477;

ll t, n, pre[inf], sum[inf], l[inf], r[inf], inputmax;

int main ()
{
    scanf ("%lld", &t);
    for (int i = 1; i <= t; i ++)
    {
        scanf ("%lld%lld", &l[i], &r[i]);
        inputmax = max (inputmax, l[i]);
        inputmax = max (inputmax, r[i]);
    }
    for (int i = 1; i < inf - 5; i ++)
    {
        pre[i] = (pre[i - 1] + i);
        sum[i] = (sum[i - 1] + (1ll * i * i));
        if (sum[i] < 0) return 1;
    }
    ll left = 1, right = inputmax, mid, hl, hr, rl, rr;
    for (int i = 1; i <= t; i ++)
    {
        left = 1, right = inf - 5ll;
        while (left <= right)
        {
            mid = (left + right) >> 1ll;
            if (l[i] <= pre[mid])
            {
                right = mid - 1ll;
                hl = mid;
                rl = pre[mid] - l[i];
            }
            else left = mid + 1ll;
        }

        left = 1, right = inf - 5ll;
        while (left <= right)
        {
            mid = (left + right) >> 1ll;
            if (r[i] <= pre[mid])
            {
                right = mid - 1ll;
                hr = mid;
                rr = pre[mid] - r[i];
            }
            else left = mid + 1ll;
        }

//        printf ("%lld %lld %lld %lld\n", hl, hr, rl, rr);
        ll ans = ((hl * (rl + 1ll)) % moder + (sum[hr - 1ll] - sum[hl]) % moder + (hr * (hr - rr)) % moder) % moder;
//        printf (" > %lld %lld %lld \n", (hl * (rl + 1ll)) % moder, (sum[hr - 1ll] - sum[hl]) % moder,(hr * (hr - rr)) % moder );
        printf ("%lld\n", ans % moder);
    }
    return 0;
}

