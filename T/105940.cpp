#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;

ll n, m, a, b, sum_x = 0, sum_y = 0;

int main ()
{
    scanf ("%lld%lld%lld%lld", &n, &m, &a, &b);
    for (ll i = a; i <= n; i += a)
    {
        sum_x ++;
    }
    for (ll i = b; i <= m; i += b)
    {
        sum_y ++;
    }
    printf ("%lld\n", sum_x * sum_y);
    return 0;
}