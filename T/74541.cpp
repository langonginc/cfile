#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 1005;

#define debug

ll n, r, s;
ll mor[inf], aft[inf], all[inf];
ll ans = 0;
bool but[inf], butm[inf];

bool cmp(ll x,ll y)
{
    return x > y;
}

void finish()
{
    for (int j = 1; j <= n; j ++)
    {
        for (int k = 1; k <= n; k ++)
        {
            if (!but[k] && !butm[j])
            {
                ans += (mor[j] + aft[k] - r) * s;
                but[k] = true;
                butm[j] = true;
#ifdef debug
                printf ("\n[D] Morning[%d]: %lld Afternoon[%d]: %lld Free: %lld\n", j, mor[j], k, aft[k], (mor[j] + aft[k] - r)*s);
#endif
                break;
            }
        }
    }
}

int main ()
{
    while (true)
    {
        ans = 0;
        scanf ("%lld%lld%lld", &n, &r, &s);
        memset (but, 0, sizeof (but));
        memset (butm, 0, sizeof (butm));
        if (n == 0 && r == 0 && s == 0)
        {
            break;
        }
        for (int i = 1; i <= n; i ++)
        {
            scanf ("%lld", &mor[i]);
        }
        for (int i = 1; i <= n; i ++)
        {
            scanf ("%lld", &aft[i]);
        }
        sort (mor + 1, mor + n + 1, cmp);
        sort (aft + 1, aft + n + 1, cmp);
        int pos = 1;
        for (int i = 1; i <= n; i ++)
        {
            while (pos <= n && mor[i] + aft[pos] > r)
            {
                pos ++;
            }
            if (pos > n)
            {
                if (i < n)
                {
                    pos = 1;
                    continue;
                }
//                finish();
                break;
            }
            but[pos] = true;
            butm[i] = true;
#ifdef debug
            printf ("\n[D] Morning: %lld Afternoon: %lld Free: %d\n", mor[i], aft[pos], (mor[i] + aft[pos])>r?1:0);
#endif
            pos ++;
        }
        finish();
        printf ("%lld\n", ans);
    }
    return 0;
}