//
// Created by Jiayi Wu on 10/15/22.
//


#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int inf = 1e6 + 5;
const ll moder = 11451477;

ll t, l, r;

int main ()
{
    scanf ("%lld", &t);
    for (int i = 1; i <= t; i ++)
    {
        scanf ("%lld%lld", &l, &r);
        ll kl = 1, posl = 0, kr = 1, posr = 0;
        for (; kl < inf; kl ++)
        {
            posl += kl;
            if (l <= posl) break;
        }
        for (; kr < inf; kr ++)
        {
            posr += kr;
            if (r <= posr) break;
        }
        ll ans = ((posl - l + 1) * kl + (r - posr + kr) * kr) % moder;
        for (ll j = kl + 1; j <= kr - 1; j ++)
        {
            ans = ((j * j) % moder + ans) % moder;
        }
        printf ("%lld\n", ans % moder);
    }
    return 0;
}

