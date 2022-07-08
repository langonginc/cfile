#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int inf = 2e5 + 10;
int n, c, a[inf];

int main ()
{
    scanf ("%d%d", &n, &c);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    sort (a + 1, a + n + 1);
    ll l = 1, r = 1, ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        while (l <= n && a[l] < a[i] - c) l ++;
        while (r <= n && a[r] <= a[i] - c) r ++;
        if (a[i] - a[l] == c)
        {
            ans += r - l;
        }
    }
    printf ("%lld\n", ans);
    return 0;
}