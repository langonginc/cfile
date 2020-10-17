#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

const int inf = 105;
const int dx[8] = { -1,0,1,1,1,0,-1,-1 };
const int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int field[inf][inf];
int num[inf][inf];
bool vis[inf][inf];
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j++)
		{
			char x;
			cin >> x;
			if (x == '*')
				field[i][j] = -1;
		}
	int x, y;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (field[i][j] == -1)
			{
				for (int k = 0; k < 8; k++)
				{
					x = dx[k] + i,
					y = dy[k] + j;
					if (x >= 1 && y >= 1 && x <= n && y <= m && field[x][y] != -1)
					{
						//printf("add %d,%d\n", x, y);
						field[x][y]++;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
		{
			if (field[i][j] == -1)
			{
				cout << '*';
			}
			else
			{
				cout << field[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
