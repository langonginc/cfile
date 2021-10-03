#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll n, m;
long long ans;

int main ()
{
    scanf ("%lld%lld", &n, &m);
    ll cnt, biao;
    if (n & 1)
    {
        biao = 1;
        cnt = 3;
        // if (m == 1)
        // {
        //     printf ("%d", ((n + 1) >> 1));
        // }
        // ans = ((n + 1) >> 1);
    }
    else
    {
        biao = 4;
        cnt = 4;
        // if (m == 4)
        // {
        //     printf ("%d", ((n + 1) >> 1));
        // }
        // ans = ((n + 1) >> 1) << 2;
    }
    for (ll i = ((n + 1) >> 1); i >= 1; i --)
    {
        if (m <= 0) break;
        if (biao <= m)
        {
            ans += biao * i;
            m -= biao;
        }
        else
        {
            ans += m * i;
            m -= m;
            break;
        }
        biao = (cnt * cnt) - (cnt - 2) * (cnt - 2);
        cnt += 2;
        
    }
    printf ("%lld", ans);
    return 0;
}