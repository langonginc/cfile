#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
using namespace std;


int n, w[55], c[55];

int main ()
{
  int t;
  scanf ("%d", &t);
  while (t --)
  {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
      scanf ("%d", &w[i]);
    }
    sort (w + 1, w + n + 1);
    int ans = 0;
    for (int i = 2; i <= n * 2; i ++)
    {
      int l = 1, r = n, tans = 0;
      while (l < r)
      {
        if (w[l] + w[r] > i)
        {
          r --;
        }
        else if (w[l] + w[r] < i)
        {
          l ++;
        }
        else
        {
          tans ++;
          r --, l ++;
        }
      }
      ans = max (ans, tans);
    }
    printf ("%d\n", ans);
  }
  return 0;
}
