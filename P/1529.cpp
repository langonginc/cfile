#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1e3 + 5;
const int INF = INT_MAX / 5;
int p, dis[inf], ph[inf][inf], vis[inf];

int main ()
{
  cin >> p;
  for (int i = 0; i < inf; i ++)
  {
    for (int j = 0; j < inf; j ++)
    {
      ph[i][j] = INF;
    }
  }
  vis[52] = true;
  for (int i = 0; i < p; i ++)
  {
    char x, y;
    int w, tx, ty;
    cin >> x >> y >> w;
    if (x >= 'a' && x <= 'z')
    {
      tx = x - 'a' + 1;
    }
    else
    {
      tx = x - 'A' + 27;
    }
    if (y >= 'a' && y <= 'z')
    {
      ty = y - 'a' + 1;
    }
    else
    {
      ty = y - 'A' + 27;
    }
    if (ph[tx][ty] == 0)
    {
      ph[tx][ty] = w;
      ph[ty][tx] = w;
    }
    if (w < ph[tx][ty])
    {
      ph[tx][ty] = w;
      ph[ty][tx] = w;
    }
  }
  for (int i = 1; i <= 51; i ++)
  {
    dis[i] = ph[52][i];
  }
  int u, mans;
  for (int i = 1; i <= 51; i ++)
  {
    mans = INF;
    for (int j = 1; j <= 51; j ++)
    {
      if (vis[j] == 0 && dis[j] < mans)
      {
        mans = dis[j];
        u = j;
      }
    }
    vis[u] = 1;
    for (int j = 1; j <= 51; j ++)
    {
      if (dis[j] > dis[u] + ph[u][j] && vis[j] == 0 && ph[u][j] < INF)
      {
        dis[j] = dis[u] + ph[u][j];
      }
    }
  }
  int ans = INF, anspos;
  for (int i = 1; i <= 51; i ++)
  {
    if (dis[i] < ans && i >= 27)
    {
      ans = dis[i];
      anspos = i;
    }
  }
  char chans = anspos - 27 + 'A';
  cout << chans << " " << ans << endl;
  return 0;
}
