#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;

const ll inf = 1100000;
ll n, m, k, p [inf], ans [inf], anc [inf][45], l, r;

ll leap (ll x)
{
  ll r = x,
     t = m;
  for (int i = 39; i >= 0; i --)
  {
    if ((1LL << i) < t)
    {
      r = anc [r][i],
      t -= (1 << i);
    }
  }
  return anc [r][0];
}

int main ()
{
  scanf ("%lld%lld%lld", &n, &k, &m);
  for (int i = 1; i <= n; i ++)
  {
    scanf ("%lld", &p [i]);
  }
  anc [1][0] = k + 1,
  l = 1,
  r = k + 1;
  for (int i = 2; i <= n; i ++)
  {
    while (r + 1 <= n && p [i] - p [l] > p [r + 1] - p [i])
    {
      l ++,
      r ++;
    }
    if (p [i] - p [l] >= p [r] - p [i])
    {
      anc [i][0] = l;
    }
    else
    {
      anc [i][0] = r;
    }
  }
  for (int i = 1; i < 40; i ++)
  {
    for (int x = 1; x <= n; x ++)
    {
      anc [x][i] = anc [anc [x][i - 1]][i - 1];
    }
  }
  for (int i = 1; i <= n; i ++)
  {
    printf ("%lld ", leap(i));
  }
  return 0;
}
