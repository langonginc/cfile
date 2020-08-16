# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
typedef long long ll;
const ll mxn = 500005;

class Edge {
  ll v, w, next;
} pool [mxn];

ll anc [mxn][30], dep [mxn], dis [mxn][30], MaxDis = -mxn, head [2 * mxn];
ll n, m;

inline void add (ll u, ll v, ll w)
{
  pool
}

void dfs (ll u, ll f, ll w)
{
  dep [u] = dep [f] + 1;
  anc [u][0] = f;
  dis [u][0] = w;
  for (int i = 1; (1 << i) <= dep [u]; i ++)
  {
    anc [u][i] = anc [anc [u][i - 1]][i - 1],
    dis [u][i] = dis [u][i - 1] + dis [anc [u][i - 1]][i - 1],
    MaxDis = max (MaxDis, dis [u][i]);
  }
  for (int i = head [u]; i; i = pool [i]. next)
  {
    int v = pool[i]. v;
    if (v != f)
      dfs (v, u, pool[i]. w);
  }
  return;
}

int main ()
{
  scanf ("%lld", &n);
  for (int i = 0; i < n - 1; i ++)
  {
    ll u, v, w;
    scanf ("%lld%lld%lld", u, v, w);
  }
}
