/*
* 1. airport
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 200005;

class Plane
{
public:
    int a, b;
    bool operator < (const Plane &p) const
    {
        if (a == p.a)
        {
            return b < p.b;
        }
        return a < p.a;
    }
} p1[inf], p2[inf];

int n, m1, m2, s[inf], nn, cnt1, cnt2, b1[inf], b2[inf], b1e[inf], b2e[inf];

inline int cal (int x)
{
    return lower_bound(s + 1, s + nn + 1, x) - s;
}

int main()
{
    freopen("airport.in", "r", stdin);
    freopen("airport.out", "w", stdout);

    scanf ("%d%d%d", &n, &m1, &m2);
    s[++ nn] = 0;
    for (int i = 1; i <= m1; i ++)
    {
        scanf ("%d%d", &p1[i].a, &p1[i].b);
        s[++ nn] = p1[i].a;
        s[++ nn] = p1[i].b;
    }
    for (int i = 1; i <= m2; i ++)
    {
        scanf ("%d%d", &p2[i].a, &p2[i].b);
        s[++ nn] = p2[i].a;
        s[++ nn] = p2[i].b;
    }
    sort (p1 + 1, p1 + m1 + 1);
    sort (p2 + 1, p2 + m2 + 1);
    sort (s + 1, s + nn + 1);

    /* lisan check
    for (int i = 1; i <= m1; i ++)
    {
        printf ("%d %d\n", cal(p1[i].a), cal(p1[i].b));
    }*/
    for (int i = 1; i <= m1; i ++)
    {
        int k = 1;
        while (true)
        {
            //printf (" DEBUG: %d < %d\n", p1[b1e[k]].b, p1[i].a);
            if (cal(p1[b1e[k]].b) < cal(p1[i].a))
            {
                cnt1 = max (cnt1, k);
                break;
            }
            k ++;
        }
        b1[k] ++;
        b1e[k] = i;
    }
    for (int i = 1; i <= m2; i ++)
    {
        int k = 1;
        while (true)
        {
            if (cal(p2[b2e[k]].b) < cal(p2[i].a))
            {
                cnt2 = max (cnt2, k);
                break;
            }
            k ++;
        }
        b2[k] ++;
        b2e[k] = i;
    }
    if (cnt1 + cnt2 <= n)
    {
        printf ("%d\n", m1 + m2);
        return 0;
    }

/*
    for (int i = 1; i <= cnt1; i ++)
    {
        printf ("%d ", b1[i]);
    }
    printf ("\n");
    for (int i = 1; i <= cnt2; i ++)
    {
        printf ("%d ", b2[i]);
    }
    printf ("\n");*/


    //sort (b1 + 1, b1 + cnt1 + 1);
    //sort (b2 + 1, b2 + cnt2 + 1);
    int pt1 = 1, pt2 = 1;
    ll sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (pt1 > cnt1)
        {
            sum += ll(b2[pt2 ++]);
        }
        else if (pt2 > cnt2)
        {
            sum += ll(b1[pt1 ++]);
        }
        else if (b1[pt1] > b2[pt2])
        {
            sum += ll(b1[pt1 ++]);
        }
        else
        {
            sum += ll(b2[pt2 ++]);
        }
    }
    printf ("%lld\n", sum);
    return 0;
}
