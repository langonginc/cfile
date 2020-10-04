#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
const int mxn = 105, mxm = 105;

const int dx[5] = { 0, 0, 1, -1 };
const int dy[5	] = { 1, -1, 0, 0 };

/*
* 0 NULL
* 1 RED
* 2 YELLOW
*/

int n, m, ans[mxn][mxm],field[mxn][mxm], fastans = INT_MAX ;


void dfs(int x, int y, int sum, bool isuse)
{
	if (x < 1 || x > m || y < 1 || y > m)
	{
		return;
	}
	if (sum >= ans[x][y])
	{
		return;
	}
	ans[x][y] = sum;
	if (x == m && y == m)
	{
		fastans = min(fastans, ans[x][y]);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i],
			ny = y + dy[i];
		if (field[nx][ny] != 0)
		{
			if (field[nx][ny] == field[x][y])
			{
				dfs(nx, ny, sum, false);
			}
			else
			{
				dfs(nx, ny, sum + 1, false);
			}
		}
		else
		{
			if (!isuse)
			{
				field[nx][ny] = field[x][y];
				dfs(nx, ny, sum + 2, true);
				field[nx][ny] = 0;
			}
		}
	}
}

int main()
{
	cin >> m >> n;
	memset(ans, 0x3f3f3f3f, sizeof(ans));
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			ans[i][j] = INT_MAX;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		field[x][y] = c + 1;
	}
	dfs(1, 1, 0, 0);
	if (fastans == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << fastans;
	}
	return 0;
}
