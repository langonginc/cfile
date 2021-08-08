#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int inf = 30005;
int a[inf][inf], n;

void dfs (int num, int x, int y, int dire)
{
    a[x][y] = num;
    if (num >= n * n)
    {
        return;
    }
    int nx = x + dx[dire], ny = y + dy[dire];
    if (nx > 0 && nx <= n && ny > 0 && ny <= n && a[nx][ny] == 0)
    {
        dfs (num + 1, nx, ny, dire);
    }
    else
    {
        int tdire = (dire + 1) % 4;
        int tx = x + dx[tdire], ty = y + dy[tdire];
        dfs (num + 1, tx, ty, tdire);
    }
}

int main ()
{
    cin >> n;
    dfs (1, 1, 1, 0);
    for (int i = 1; i <= n ; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            printf ("%d ", a[i][j]);
        }
        printf ("\n");
    }
    return 0;
}