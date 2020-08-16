#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;
const int INF = INT_MAX;
const int inf = 4e5 + 5;

struct Edge
{
  int from, to, next;
} pool[inf];

int n, m, k, head[inf], h[inf], ans[inf], f[inf], dead[inf], nn;

inline void add (int u, int v)
{
  pool[++ nn].from = u,
  pool[nn].to = v,
  pool[nn].next = head[u];
  head[u] = nn;
}

inline int find (int x)
{
  if (x == f[x])
    return x;
  else
    return f[x] = find(f[x]);
}

inline void merge (int x, int y)
{
  f[find (x)] = find (y);
}

int main ()
{
  scanf ("%d%d", &n, &m);
  for (int i = 0; i <= n; i ++)
    f[i] = i;
  for (int i = 1; i <= m; i ++)
  {
    int x, y;
    scanf ("%d%d", &x, &y);
    add (x, y), add (y, x);
  }
  scanf ("%d", &k);
  int cnt = n - k;
  for (int i = 1; i <= k; i ++)
  {
    scanf ("%d", &h[i]);
    dead[h[i]] = true;
  }
  for (int i = 1; i <= 2 * m; i ++)
  {
    Edge nw = pool[i];
    if (dead[nw.from] == false || dead[nw.to] == false)
    {
      if (find(nw.from) != find(nw.to))
      {
        cnt --;
        merge (nw.from, nw.to);
      }
    }
  }
  ans[k + 1] = cnt;
  for (int u = k; u > 0; u --)
  {
    int x = h[u];
    cnt ++;
    dead[x] = false;
    for (int i = head[u]; i != 0; i = pool[i].next)
    {
      Edge nw = pool[i];
      if (dead[nw.to] == false && find (x) != find(nw.to))
      {
        cnt --;
        merge (nw.to, x);
      }
    }
    ans[u] = cnt;
  }
  for (int i = 1; i <= k + 1; i ++)
  {
    printf ("%d\n", ans[i]);
  }
  return 0;
}

