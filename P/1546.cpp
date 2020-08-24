#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
using namespace std;
const int inf = 105;

int n, adj[inf][inf], vis[inf], cost[inf];

int main ()
{
  cin >> n;
  for (int i = 1; i <= n; i ++)
  {
    for (int j = 1; j <= n; j ++)
      cin >> adj[i][j];
  }
  for (int i = 0; i <= n; i ++)
  {
    cost[i] = INT_MAX;
    vis[i] = 0;
  }
  cost[1] = 0;
  int res = 0;
  for (int i = 0; i < n; i ++)
  {
    int index = 0;
    for (int j = 1; j <= n; j ++)
    {
      if (vis[j] == 0 && cost[j] < cost[index])
      {
        index = j;
      }
    }
    vis[index] = 1;
    res += cost[index];
    for (int j = 1; j <= n; j ++)
    {
      if (vis[j] == 0 && cost[j] > adj[index][j])
      {
        cost[j] = adj[index][j];
      }
    }
  }
  printf ("%d\n", res);
  return 0;
}
