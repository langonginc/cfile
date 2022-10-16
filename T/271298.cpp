/*

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int inf = 1e6 + 5;

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
    for (int i = 1; i <= inputmax; i ++)
    {
        pre[i] = pre[i - 1] + i;
        sum[i] = sum[i - 1] + i * i;
    }
    ll left = 1, right = inputmax, mid, hl, hr, rl, rr;
    for (int i = 1; i <= t; i ++)
    {
        left = 1, right = inputmax;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (l[i] <= pre[mid])
            {
                right = mid - 1;
                hl = mid;
                rl = pre[mid] - l[i];
            }
            else left = mid + 1;
        }

        left = 1, right = inputmax;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (r[i] <= pre[mid])
            {
                right = mid - 1;
                hr = mid;
                rr = pre[mid] - r[i];
            }
            else left = mid + 1;
        }

        printf ("hl=%lld hr=%lld\n", hl, hr);
        ll ans = hl * (rl + 1) + sum[hr - 1] - sum[hl] + hr * (hr - rr);
        printf ("%lld\n", ans);
    }
    return 0;
}

*/

#include <iostream>
#include <cstdio>
using namespace std;
