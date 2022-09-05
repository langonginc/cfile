#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
typedef long long ll;
const int inf = 1e5 + 5;

ll n, x, p, q, t[inf], sleep, date, task = 1;

// ll gcd (ll a, ll b)
// {
//     if (b == 0)
//     {
//         return a;
//     }
//     return gcd (b, a % b);
// }

int main ()
{
    scanf ("%lld%lld%lld%lld", &n, &x, &p, &q);
    // ll g = gcd (p, q);
    // p /= g, q /= g;
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &t[i]);
    }
    while (++ date)
    {
        ll sleeptime = p * x * date / q;
        ll todaytask = 0;
        sleep += x;
        while (sleep - todaytask - t[task] >= sleeptime && todaytask + t[task] < x)
        {
            // printf ("Required %lld time to sleep, after this last %lld time.\n", sleeptime, sleep[date] - todaytask - t[task]);
            todaytask += t[task ++];
            // printf ("Did task #%lld in date %lld.\n", task - 1, date);
            if (task > n)
            {
                printf ("%lld\n", date);
                return 0;
            }
        }
        sleep -= todaytask;
    }
    return 0;
}