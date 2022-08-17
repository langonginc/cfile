#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int inf = 11;
ll dep, m[inf], ans[inf];
bool flag;

ll gcd (ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd (y, x % y);
}

void dfs (ll a, ll b, ll x)
{
    if (x > dep) return;
    if (a == 1 && b > m[x - 1])
    {
        m[x] = b;
        if (! flag || m[x] < ans[x])
        {
            for (int i = 1; i <= dep; i ++)
            {
                ans[i] = m[i];
            }
            flag = true;
        }
        return;
    }
    ll l = max (b / a, m[x - 1] + 1),
       r = (dep - x + 1) * b / a;
    if (flag && r >= ans[dep])
    {
        r = ans[dep] - 1;
    }
    for (ll i = l; i < r; i ++)
    {
        m[x] = i;
        ll gval = gcd (a * i - b, b * i);
        dfs ((a * i - b) / gval, b * i / gval, x + 1);
    }
}

int main ()
{
    ll a, b;
    scanf ("%lld%lld", &a, &b);
    a /= gcd (a, b), b /= gcd (a, b);
    m[0] = 1;
    for (dep = 1; dep <= 10; dep ++)
    {
        dfs (a, b, 1);
        if (flag)
        {
            for (ll i = 1; i <= dep; i ++)
            {
                printf ("%lld ", ans[i]);
            }
            break;
        }
    }
    return 0;
}