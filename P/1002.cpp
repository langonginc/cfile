#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int inf = 35;
const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m, nx, ny;
bool unavi[inf][inf];
ull dp[inf][inf];

int main ()
{
  cin >> n >> m >> nx >> ny;
  n ++, m ++, nx ++, ny ++;
  unavi[nx][ny] = true;
  for (int i = 0; i < 8; i ++)
  {
    int x = nx + dx[i];
    int y = ny + dy[i];
    if (x < 1 || y < 1 || x > n || y > m)
    {
      continue;
    }
    unavi[x][y] = true;
  }
  dp[1][1] = 1;
  for (int i = 1; i <= n; i ++)
  {
    for (int j = 1; j <= m; j ++)
    {
      if (unavi[i][j]) continue;
      dp[i][j] = max (dp[i][j], dp[i-1][j] + dp[i][j-1]);
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}