#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mxm = 300005;
const int mxn = 100005;
const ll inf = 0x3f3f3f3f3f;

class Edge
{
  public:
    ll u, v, w;
    bool operator < (const Edge &opt) const
    {
      return w < opt.w;
    }
} edge[mxn * 5];

class Node
{
  public:
    ll v, next, w;
} pool[mxm * 5];

ll n, m, nn, f[mxn], dep[mxn], anc[mxm][25], m1[mxm][25], m2[mxm][25], head[mxm];
short use[mxn];

inline void add (ll u, ll v, ll w){
  nn++;
  pool[nn].v = v;
  pool[nn].w = w;
  pool[nn].next = head[u];
  head[u] = nn;
}

inline int find (ll x)
{
  if (x == f [x])
    return x;
  else
    return f [x] = find (x);
}

inline void marge(ll x, ll y) {
    f[find(x)] = find(y);
}

void dfs (ll u, ll fa, ll w)
{
  dep[u] = dep[fa] + 1;
  anc[u][0] = fa;
  m1[u][0] = w;
  m2[u][0] = -inf;
  for (int j = 1; j < 20; j ++)
  {
    anc[u][j] = anc[anc[u][j - 1]][j - 1];
    m1[u][j] = max (m1[u][j - 1], m1[anc[u][j - 1]][j - 1]);
    m2[u][j] = max (m2[u][j - 1], m2[anc[u][j - 1]][j - 1]);
    if (m1[u][j - 1] < m1[anc[u][j - 1]][j - 1])
      m2[u][j] = max (m2[u][j], m1[u][j - 1]);
    else if (m1[u][j - 1] > m1[anc[u][j - 1]][j - 1])
      m2[u][j] = max (m2[u][j], m1[anc[u][j - 1]][j - 1]);
  }
  for (ll i = head[u]; i; i = pool[i].next)
  {
    ll v = pool[i].v;
    //...Something
  }
}

ll lca (ll x, ll y, ll ma)
{
  if (dep[x] > dep[y])
    swap (x, y);
  ll ans = -inf;
  for (int j = 19; j >= 0; j --)
  {
    if (dep[anc[y][j]] >= dep[x])
    {
      if (m1[y][j] != ma)
      {
        ans = max (ans, m1[y][j]);
      }
      else
      {
        ans = max (ans, m2[y][j]);
      }
      y = anc[y][j];
    }
  }
  if (x == y)
    return ans;
  for (int j = 19; j >= 0; j --)
  {
    if (anc[x][j] != anc[y][j])
    {
      if (m1[x][j] != ma)
        ans = max (ans, m1[x][j]);
      else
        ans = max (ans, m2[x][j]);
      if (m1[y][j] != ma)
        ans = max (ans, m1[y][j]);
      else
        ans = max (ans, m2[y][j]);
      x = anc[x][j];
      y = anc[y][j];
    }
  }
  if (m1 [x][0] != ma)
    ans = max (ans, m1[x][0]);
  else
    ans = max (ans, m2[x][0]);
  if (m1 [y][0] != ma)
    ans = max (ans, m1[y][0]);
  else
    ans = max (ans, m2[y][0]);
  return ans;
}

int main ()
{
  scanf ("%lld%lld", &n, &m);
  for (int i = 1; i <= m; i ++)
    scanf ("%lld%lld%lld", &edge[i].u, &edge[i].v, &edge[i].w);
  sort (edge + 1, edge + m + 1);
  ll mst = 0, count = 0;
  for (int i = 0; i <= n; i ++)
    f[i] = i;
  for (int i = 1; i <= m; i ++)
  {
    if (find (edge[i].u) != find (edge[i].v))
    {
      ll u = edge[i].u,
         v = edge[i].v,
         w = edge[i].w;
      use[i] = 1, mst += w;
      marge (u, v);
      add (u, v, w);
      add (v, u, w);
      count ++;
      if (count == n - 1)
        break;
    }
    //... Something
  }
  count = inf;
  for (int i = 1; i <= m; i ++)
    if (!use[i])
      count = min (count, mst - lca (edge[i].u, edge[i].v, edge[i].w) + edge[i].w);
  printf ("%lld\n", count);
  return 0;
}

