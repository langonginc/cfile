#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
const int inf = 100005;
const int INF = INT_MAX;

struct node
{
  int v, w;
};

inline node mks (int v, int w)
{
  node a;
  a.v = v, a.w = w;
  return a;
}

vector <node> adj1[inf];
vector <node> adj2[inf];
int n, m, cost[inf], mx[inf], mn[inf], d1[inf], d2[inf], vis1[inf], vis2[inf];

void spfa1 ()
{
  queue <int> q;
  for (int i = 0; i <= n; i ++)
  {
    d1[i] = INF;
    vis1[i] = 0;
  }
  q.push (1);
  //d1[1] = 0;
  vis1[1] = 1;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    if (vis1[u])
      continue;
    for (int i = 0; i < adj1[u].size(); i ++)
    {
      int v = adj1[u][i].v;
      int w = adj1[u][i].w;
      if (min(d1[u], w) < d1[v])
      {
        d1[v] = min(d1[u], w);
        if (!vis1[v])
        {
          vis1[v] = 1;
          q.push(v);
        }
      }
    }
  }
}

void spfa2 ()
{
  queue <int> q;
  for (int i = 0; i <= n; i ++)
  {
    d2[i] = 0;
  }
  q.push(n);
  //d2[n] = 0;
  vis2[n] = 1;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    if (vis2[u])
      continue;
    vis2[u] = 1;
    for (int i = 0; i < adj2[u].size(); i ++)
    {
      int v = adj2[u][i].v;
      int w = adj2[u][i].w;
      if (max(d2[u], w) > d2[v])
      {
        d2[v] = max(d2[u], w);
        if (!vis2[v])
        {
          vis2[v] = 1;
          q.push(v);
        }
      }
    }
  }
}

int main (int argc, char* argv[])
{
  scanf ("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++)
  {
    scanf ("%d", &cost[i]);
  }
  for (int i = 0; i < m; i ++)
  {
    int x, y, z;
    scanf ("%d%d%d", &x, &y, &z);
    adj1[x].push_back(mks(y, cost[x]));
    adj2[y].push_back(mks(x, cost[y]));
    if (z == 2)
    {
      adj1[y].push_back(mks(x, cost[y]));
      adj2[x].push_back(mks(y, cost[x]));
    }
  }
  spfa1(), spfa2();
  int mx = 0;
  for (int i = 1; i <= n; i ++)
  {
    mx = max (d2[i] - d1[i], mx);
  }
  printf ("%d" ,mx);
  return 0;
}

