//
// Created by Jiayi Wu on 10/16/22.
//

#ifndef CFILE_FASTPOW_H
#define CFILE_FASTPOW_H

typedef long long ll;

ll fastPow (ll x, ll y)
{
    ll r = 1, base = x;
    while (y)
    {
        if (y & 1)
        {
            r *= base;
        }
        base *= base, y >>= 1;
    }
    return r;
}

#endif //CFILE_FASTPOW_H
