#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
const int inf = 1e5 + 5;

int n, m, f[inf * 3], ans;
int fx1, fx2, fx3, fy1, fy2, fy3;

inline int getf (int x, int t = 0)
{
  switch (t)
  {
    case 1: return x;
    case 2: return x + n;
    case 3: return x + 2 * n;
    case 0: return x;
  }
  return 0;
}

int find (int x)
{
  if (x == f[x])
    return x;
  else
  {
    return f[x] = find(f[x]);
  }
}

void getinfo (int x, int y)
{
  fx1 = find(getf(x)),
  fx2 = find(getf(x, 2)),
  fx3 = find(getf(x, 3)),
  fy1 = find(getf(y)),
  fy2 = find(getf(y, 2)),
  fy3 = find(getf(y, 3));
}

int main ()
{
  scanf ("%d%d", &n, &m);
  for (int i = 1; i <= 3 * n; i ++)
  {
    f[i] = i;
  }
  for (int i = 1; i <= m; i ++)
  {
    int x, y, t;
    scanf ("%d%d%d", &t, &x, &y);
    if (x > n || y > n)
    {
      ans ++;
      continue;
    }
    getinfo(x, y);
    if (t == 1)
    {
      if (fx2 == fy1 || fy2 == fx1)
      {
        ans ++;
      }
      else
      {
        f[fx1] = fy1;
        f[fx2] = fy2;
        f[fx3] = fy3;
      }
    }
    else
    {
      if (fy2 == fx1 || fx1 == fy1)
      {
        ans ++;
      }
      else
      {
        f[fy1] = fx2;
        f[fy2] = fx3;
        f[fy3] = fx1;
      }
    }
  }
  printf ("%d", ans);
  return 0;
}
