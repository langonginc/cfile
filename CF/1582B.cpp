#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll t, n, a, x, y;
// ll fac[605];

// inline ll c (ll m, ll n)
// {
//     return fac[n] / fac[m] / fac[n - m];
// }

// ll c (ll m, ll n)
// {
//     ll ans = 1;
//     for (ll i = m + 1; i <= n; i ++)
//     {
//         ans *= i;
//     }
//     for (ll i = 1; i <= n - m; i ++)
//     {
//         ans /= i;
//     }
//     return ans;
// }

int main ()
{
    scanf ("%lld", &t);
    // fac[0] = 1;
    // for (int i = 1; i <= 60; i ++)
    // {
    //     fac[i] = fac[i - 1] * i;
    // }
    while (t --)
    {
        x = y = 0;
        scanf ("%lld", &n);
        for (int i = 1;  i <= n; i ++)
        {
            scanf ("%lld", &a);
            if (a == 0) x ++;
            if (a == 1) y ++;
        }
        // if (x == 0) printf ("%lld\n", y);
        // else printf ("%lld\n", ((x - 1) * x + 2ll) * y);
        // ll ans = 0;
        // for (int i = 0; i <= x; i ++)
        // {
        //     ans += c(i, x);
        // }
        printf ("%lld\n", ll(pow(2, x)) * y);
    }
    return 0;
}

/*
  n    i
SUM   C     = 2^n
 i=1   n
*/