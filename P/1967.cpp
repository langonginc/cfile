# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
const int mxn = 10005;
int nn = 0;

class Ori {
  public:
    int u, v, w;
    bool operator < (const Ori & t) const
    {
      return w < t. w;
    }
} ori [mxn];

class Edge {
  public:
    int v, next, w;
} pool [2 * mxn];

int n, m, q;
int dep [mxn], anc [mxn][20], cap [mxn][20], head [mxn], fa [mxn];

inline void add (int u, int v, int w){
  nn++;
  pool[nn].v = v;
  pool[nn].w = w;
  pool[nn].next = head[u];
  head[u] = nn;
}

inline int find (int x)
{
  if (x == fa [x])
    return x;
  else
    return fa [x] = find (x);
}

inline void marge(int x, int y) {
    fa[find(x)] = find(y);
}

void dfs (int u, int f, int w)
{
  dep [u] = dep [f] + 1,
  anc [u][0] = f,
  cap [u][0] = w;
  for (int i = 1; (1 << i) <= dep [u]; i ++)
  {
    anc [u][i] = anc [anc [u][i - 1]][i - 1],
    cap [u][i] = min (cap [u][i - 1], cap [anc [u][i - 1]][i - 1]);
  }
  for (int i = head [u]; i; i = pool [i]. next)
  {
    int v = pool [i]. v;
    if (v != f)
    {
      dfs (v, u, pool [i]. w);
    }
  }
}

int lca (int x, int y)
{
  if (dep [x] > dep [y])
    swap (x, y);
  int cx = mxn, cy = mxn;
  for (int i = 15; i >= 0; i --)
  {
    if (dep [anc [y][i]] > dep [x])
    {
      cy = min (cy, cap [y][i]),
      y = anc [y][i];
    }
  }
  if (x == y)
    return cy;
  for (int i = 15; i >= 0; i --)
  {
    if (anc [x][i] != anc [y][i])
    {
      cx = min (cx, cap [x][i]),
      cy = min (cy, cap [y][i]),
      x = anc [x][i],
      y = anc [y][i];
    }
  }
  cx = min (cx, cap [x][0]),
  cy = min (cy, cap [y][0]);
  return min (cx, cy);
}

int main (int argc, char* argv [])
{
  scanf ("%d%d", &n, &m);
  for (int i = 0; i < m; i ++)
  {
    scanf ("%d%d%d", &ori [i]. u, &ori [i]. v, &ori [i]. w);
  }
  
  sort (ori, ori + m);
  for (int i = 0; i <= n; i ++)
    fa [i] = i;
  for (int i = 0; i < m; i ++)
  {
    if (find (ori [i]. u) != find (ori [i]. v))
    {
      marge (ori [i]. u, ori [i]. v);
      add (ori [i]. u, ori [i]. v, ori [i]. w);
      add (ori [i]. v, ori [i]. u, ori [i]. w);
    }
  }
  for (int i = 1; i <= n; i ++)
    if (dep [i] == 0)
      dfs (i, 0, mxn);

  scanf ("%d", &q);
  for (int i = 1; i <= q; i ++)
  {
    int x, y;
    scanf ("&d&d", &x, &y);
    if (find (x) != find (y))
      printf ("-1\n");
    else
      printf ("%d\n", lca (x, y));
  }
  return 0;
}
