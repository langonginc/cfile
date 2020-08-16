#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;
const int mxn = 15050;
const int dx [8] = {1,1,1,0,-1,-1,-1,0};
const int dy [8] = {-1,0,1,1,1,0,-1,-1};
bool filed [mxn][mxn], vis [mxn][mxn];
int n, m, max_stars, now, count_stars;
int can [10000005], max_can, count_can;

void dfs (int x, int y)
{
  vis [x][y] = 1;
  if (filed[x][y])
    now ++;
  else
    return;

  for (int i = 0; i < 8; i ++)
  {
    int nx = x + dx [i];
    int ny = y + dy [i];
    if (nx > 0 && ny > 0 && nx <= n && ny <= m && !vis [nx][ny])
    {
      dfs (nx, ny);
    }
  }
}

int main ()
{
  scanf ("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++)
  {
    for (int j = 1; j <= m; j ++)
    {
      char ch;
      // scanf ("%c", &ch);
      cin >> ch;
      if (ch == '*')
      {
        filed [i][j] = 1;
      }
      else
      {
        filed [i][j] = 0;
      }
    }
  }

  for (int i = 1; i <= n; i ++)
  {
    for (int j = 1; j <= m; j ++)
    {
      if (filed [i][j] && !vis [i][j])
      {
        now = 0;
        dfs (i, j);
        can [now] ++;
        max_stars = max (max_stars, now * can [now]);
        count_stars ++;
        //printf ("(%d, %d) is the %d \n", i, j, count_stars);
      }
    }
  }
  for (int i = 1; i <= n * m; i ++)
  {
    max_can = max (max_can, can [i]);
    if (can [i])count_can++;
  }
  printf ("%d %d\n", count_can, max_stars);
  return 0;
}
