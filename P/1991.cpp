#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
const int inf = 1000005;

int f[inf], a[inf], b[inf], s, p, m, k, num;
double ans[inf], x[inf], y[inf];

class Edge
{
public:
  int x, y;
  double w;
  void operator () (int ix, int iy, double iw)
  {
    x = ix;
    y = iy;
    w = iw;
  }
} ph[inf];

inline bool cmp (Edge x, Edge y)
{
  return x.w < y.w;
}

int find (int x)
{
  if (f[x] == x)
  {
    return x;
  }
  else
  {
    return f[x] = find(f[x]);
  }
}

inline double dist(double x1, double y1, double x2, double y2)
{
   return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main ()
{
  scanf ("%d%d", &s, &p);
  if (s >= p)
  {
    printf ("0.00");
    return 0;
  }
  for (int i = 1; i <= p; i ++)
  {
    scanf ("%lf%lf", &x[i], &y[i]);
    f[i] = i;
  }
  for (int i = 1; i <= p; i ++)
  {
    for (int j = 1; j <= p; j ++)
    {
      m ++;
      ph[m](i, j, dist(x[i], y[i], x[j], y[j]));
    }
  }
  sort (ph + 1, ph + m + 1, cmp);
  for (int i = 1; i <= m; i ++)
  {
    int fx = find (ph[i].x), fy = find (ph[i].y);
    if (fx != fy)
    {
      f[fx] = fy;
      ans[++ num] = ph[i].w;
    }
  }
  printf ("%.2lf", ans[num - s + 1]);
  return 0;
}
