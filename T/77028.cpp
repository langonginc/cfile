#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
const int inf = 1e5+5;
const int INF = INT_MAX;

class node
{
  public:
    int v, w;
};

inline node makenode (int v, int w)
{
  node a;
  a.v = v, a.w = w;
  return a;
}

int n, r, d1[inf], d2[inf], vis[inf];
vector <node> adj[inf];

void spfa ()
{
  queue <int> q;
  for (int i = 0; i <= n; i ++)
  {
    d1[i] = d2[i] = INF;
  }
  q.push (1);
  d1[1] = 0, d2[1] = INF;
  vis[1] = 1;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i ++)
    {
      int v = adj[u][i].v,
          w = adj[u][i].w;
      bool p = false;
      if (d1[u] + w < d1[v])
      {
        d2[v] = d1[v];
        d1[v] = d1[u] + w;
        p = true;
      }
      if (d1[u] + w > d1[v] && d1[u] + w < d2[v])
      {
        d2[v] = d1[u] + w;
        p = true;
      }
      if (d2[u] + w > d1[v] && d2[u] + w <d2[v])
      {
        d2[v] = d2[u] + w;
        p = true;
      }
      if (p && vis[v] == 0)
      {
        vis[v] = 1;
        q.push(v);
      }
    }
  }
}

int main ()
{
  scanf ("%d%d", &n, &r);
  for (int i = 0; i < r; i ++)
  {
    int x, y, w;
    scanf ("%d%d%d", &x, &y, &w);
    adj[x].push_back(makenode (y, w));
    adj[y].push_back(makenode (x, w));
  }
  spfa ();
  printf ("%d\n", d2[n]);
  return 0;
}

