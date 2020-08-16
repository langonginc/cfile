#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;
const int inf = 105;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int f[inf][inf];
bool vis[inf][inf];
int n, m;

void dfs (int x, int y)
{
  printf ("%d %d\n", x, y);
  vis[x][y] = 1;
  for (int i = 0; i < 4; i ++)
  {
    int nx = x + dx[i],
        ny = y + dy[i];
    if (nx <= 0 || nx > n || ny <= 0 || ny > m)
    {
      continue;
    }
    while (true)
    {
      if (nx <= 0 || nx > n || ny <= 0 || ny > m)
      {
        break;
      }
      if (!vis[nx][ny])
      {
        dfs (nx, ny);
        break;
      }
      nx += dx[i],
      ny += dy[i];
    }
  }
}

int main ()
{
  int x, y;
  scanf ("%d%d%d%d", &n, &m, &x, &y);
  vis[x][y] = 1;
  dfs (x, y);
  return 0;
}
