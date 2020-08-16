#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int inf = 10005;

ll n, x, win[inf], los[inf], use[inf], dp[inf];

int main ()
{
  scanf ("%lld%lld", &n, &x);
  for (int i = 1; i <= n; i ++)
  {
    scanf ("%lld%lld%lld", &los[i], &win[i], &use[i]);
    los[i] *= 5;
    win[i] *= 5;
  }

  for (int i = 1; i <= n; i ++)
  {
    for (int j = x; j >= 0; j --)
    {
      if (j >= use[i])
      {
        dp[j] = max (dp[j] + los[i], dp[j - use[i]] + win[i]);
      }
      else
      {
        dp[j] += los[i];
      }
    }
  }
  printf ("%lld\n", dp[x]);
  return 0;
}

