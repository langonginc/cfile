#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int inf = 200005;

ll n, vis[inf], size[inf], dep[inf], dp[inf], ans = 0;
vector <ll> adj[inf];

void dfs (int u, int f)
{
  size[u] = 1;
  dp[1] ++;
  for (int i = 0; i < adj[u].size(); i ++)
  {
    int v = adj[u][i];
    if (f != v)
    {
      dfs (v, u);
      size[u] += size[v];
      dp[1] += size[v];
    }
  }
}

void dfs2 (int u, int f)
{
  for (int i = 0; i < adj[u].size(); i ++)
  {
    int v = adj[u][i];
    if (v != f)
    {
      dp[v] = dp[u] + size[1] - size[v] * 2;
      ans = max (ans, dp[v]);
      dfs2 (v, u);
    }
  }
}

int main ()
{
  scanf ("%lld", &n);
  for (int i = 1; i < n; i ++)
  {
    ll u, v;
    scanf ("%lld%lld", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs (1, 0);
  dfs2 (1, 0);
  printf ("%lld\n", ans);
  return 0;
}
