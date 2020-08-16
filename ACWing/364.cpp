#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mxn = 400005;

class edge
{
public:
  int v, next;
} pool [4 * mxn];

int n, m, q, head [mxn], nn, low [mxn], pre [mxn], bccno [mxn], bcc_count;
int bridge [mxn * 4], dep [mxn], anc [mxn][20], dfstime, fa [mxn], ans;
vector <int> adj [mxn];

inline void add (int u, int v)
{
  pool[ nn ]. v = v;
  pool[ nn ]. next = head[ u ];
  head[ u ] = nn ++;
}

void tarjan (int u, int f)
{
  pre [u] = low [u] = ++ dfstime;
  for (int i = head [u]; i != -1; i = pool [i]. next)
  {
    int v = pool [i].v;
    if (pre [v] == 0)
    {
      tarjan (v, u);
      low [u] = min (low [u], low [v]);
      if (low [v] > pre [v])
      {
        bridge [i] = bridge [i ^ 1] = 1;
      }
    }
    else if (u != f)
    {
      low [u] = min (low [u], pre [v]);
    }
  }
}

void bcc( int u )
{
  bccno[ u ] = bcc_count;
  for( int i = head[ u ]; i != -1; i = pool[ i ]. next )
  {
    if( bridge[ i ] )
    {
      continue;
    }
    int v = pool[ i ]. v;
    if( bccno[ v ] == 0 )
    {
      bcc( v );
    }
  }
}

void dfs (int u, int f)
{
  dep [u] = dep [f] + 1;
  anc [u][0] = f;
  for (int i = 1; i < 20; i ++)
  {
    anc [u][i] = anc [anc [u][i - 1]][i - 1];
  }
  for (int i = 0; i < adj [u]. size (); i ++)
  {
    int v = adj [u][i];
    if (v != f)
    {
      dfs (v, u);
    }
  }
}

int lca (int x, int y)
{
  if (dep [x] < dep [y])
  {
    swap (x, y);
  }
  for (int i = 19; i >= 0; i--)
  {
    if (dep [anc [x][i]] >= dep [y])
    {
      x = anc [x][i];
    }
  }
  if (x == y) return x;
  for (int i = 19; i >= 0; i--)
  {
    if (anc [x][i] != anc [y][i])
    {
      x = anc [x][i], y = anc [y][i];
    }
  }
  return anc [x][0];
}

void cal (int x, int y)
{
  if (x == y)
  {
    return;
  }
  if (fa [x] == x)
  {
    ans --;
    cal (anc [x][0], y);
  }
  else
  {
    cal (fa [x], y);
  }
  fa [x] = y;
  return;
}

int main (int argc, char* argv [])
{
  int cs = 0;
  while (++ cs)
  {
    memset (head, -1, sizeof (head));
    memset (pre, 0, sizeof (pre));
    memset (low, 0, sizeof (low));
    memset (pre, 0, sizeof (pre));
    memset (dep, 0, sizeof (dep));
    memset (anc, 0, sizeof (anc));
    memset (fa, 0, sizeof (fa));
    memset (bccno, 0, sizeof (bccno));
    memset (bridge, 0, sizeof (bridge));
    nn = dfstime = ans = 0;
    scanf ("%d%d", &n, &m);
    if (n == 0 && m == 0) break;
    for (int i = 0; i < m; i ++)
    {
      int x, y;
      scanf ("%d%d", &x, &y);
      add (x, y);
    }
    tarjan (1, 0);
    for (int i = 1; i <= n; i ++)
    {
      if (bccno [i] == 0)
      {
        bcc_count++;
        bcc (i);
      }
    }
    for (int u = 1; u <= n; u ++)
    {
      for (int i = head [u]; i != -1; i = pool [i]. next)
      {
        if (bridge [i])
        {
          int v = pool [i]. v;
          if (bccno [u] != bccno [v])
          {
            adj [bccno [u]]. push_back (bccno [v]);
          }
        }
      }
    }
    dfs (1, 0);
    for (int i = 1; i <= n; i ++)
    {
      for (int j = 1; j <= n; j ++)
      {
        cal (i, lca (i, j));
        cal (j, lca (i, j));
      }
    }
    int q;
    scanf ("%d", &q);
    printf ("Case %d:\n", cs);
    for (int i = 0; i < q; i ++)
    {
      int u, v;
      scanf ("%d%d", &u, &v);
      int nu = bccno [u];
      int nv = bccno [v];
      printf ("%d\n", dep [nu] + dep[ nv ] - 2 * dep [lca (nu, nv)]);
    }
    putchar ('\n');
  }
  return 0;;
}
