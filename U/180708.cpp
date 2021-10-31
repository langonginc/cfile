#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 1e5 + 5;
ll q, n, k, a[inf], l[inf];
/*
int main ()
{
    a[1] = 0, l[1] = 1;
    a[2] = 1, l[2] = 1;
    for (int i = 3; i < inf; i ++)
    {
        a[i] = (a[i - 1] << l[i - 2]) + a[i - 2];
        l[i] = l[i - 1] + l[i - 2];
    }
    scanf ("%lld", &q);
    while (q --)
    {
        scanf ("%lld%lld", &n, &k);
        ll x = a[n] >> (l[n] - k);
        printf ("%c\n", (x & 1)?'a':'A');
    }
    return 0;
}*/


char dfs (ll n, ll k)
{
    if (n == 1)
    {
        return 'A';
    }
    if (n == 2)
    {
        return 'a';
    }
    if (k <= l[n - 1])
    {
        return dfs (n - 1, k);
    }
    return dfs (n - 2, k - l[n - 1]);
}

int main ()
{
    l[1] = l[2] = 1;
    for (int i = 3; i < inf; i ++)
    {
        l[i] = l[i - 1] + l[i - 2];
        if (l[i] < 0) l[i] = 1e18;
    }
    scanf ("%lld", &q);
    while (q --)
    {
        scanf ("%lld%lld", &n, &k);
        printf ("%c\n", dfs (n, k));
    }
    return 0;
}