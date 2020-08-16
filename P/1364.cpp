#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;
const int inf = 505;

int n, size[inf], w[inf], dep[inf], dp[inf], ans = INT_MAX;
vector<int> adj[inf];

void dfs (int u, int f)
{
  dep[u] = dep[f] + 1;
  size[u] = w[u];
  dp[1] += dep[u] * w[u];
  for (int i = 0; i < adj[u].size(); i ++)
  {
    if (adj[u][i] != f)
    {
      dfs (adj[u][i], u);
      size[u] += size[adj[u][i]];
    }
  }
}

void getans (int u, int f)
{
  for (int i = 0; i < adj[u].size(); i ++)
  {
    if (adj[u][i] != f)
    {
      dp[adj[u][i]] = dp[u] + size[1] - size[adj[u][i]] - size[adj[u][i]];
      getans (adj[u][i], u);
    }
  }
  ans = min (ans, dp[u]);
}

int main ()
{
  cin >> n;
  for (int i = 1; i <= n; i ++)
  {
    int u, v, we;
    cin >> we >> u >> v;
    w[i] = we;
    if (u != 0 && v != 0)
    {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }
  dep[0] = -1;
  dfs (1, 0);
  getans (1, 0);
  printf ("%d\n", ans);
  return 0;
}
