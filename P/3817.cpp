#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 1e5 + 5;
ll a[inf], n, x, ans;

int main ()
{
    scanf ("%lld%lld", &n, &x);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] + a[i - 1] > x)
        {
            ans += a[i] + a[i - 1] - x;
            a[i] = x - a[i - 1];
        }
    }
    printf ("%lld", ans);
    return 0;
}