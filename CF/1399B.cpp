// Codeforces 1399B

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
using namespace std;
typedef long long ll;

struct Gifts
{
  int a, b;
};

int main ()
{
  int t, n;
  scanf ("%d", &t);
  while (t --)
  {
    scanf ("%d", &n);
    Gifts v[55];
    Gifts vmin;
    vmin.a = vmin.b = INT_MAX;
    for (int i = 1; i <= n; i ++)
    {
      scanf ("%d", &v[i].a);
      vmin.a = min (vmin.a, v[i].a);
    }
    for (int i = 1; i <= n; i ++)
    {
      scanf ("%d", &v[i].b);
      vmin.b = min (vmin.b, v[i].b);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
      int a = v[i].a - vmin.a,
          b = v[i].b - vmin.b;
      ans = ans + max (a, b);
    }
    printf ("%lld\n", ans);
  }
  return 0;
}
