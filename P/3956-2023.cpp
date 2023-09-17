#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
using namespace std;
const int maxm = 105;

const int dx[5] = {0, 1, -1, 0, 0};
const int dy[5] = {0, 0, 0, 1, -1};

int n, m, ans = INT_MAX;
int field[maxm][maxm];
int vis[maxm][maxm];
int cache[maxm][maxm];

void dfs (const int x, const int y, const int cost, const bool hasColor) {
    if (x == m && y == m) {
        ans = min (ans, cost);
        return;
    }
    if (cost >= ans || cost >= cache[x][y]) {
        return;
    }
    cache[x][y] = cost;
    for (int i = 1; i <= 4; i ++) {
        const int nx = x + dx[i];
        const int ny = y + dy[i];
        if (nx >= 1 && ny >= 1 && nx <= m && ny <= m && !vis[nx][ny]) {
            vis[nx][ny] = true;
            if (field[nx][ny] > 0) {
                dfs (nx, ny, (field[nx][ny] == field[x][y] ? cost : cost + 1), true);
            } else if (hasColor) {
                field[nx][ny] = field[x][y];
                dfs (nx, ny, cost + 2, false);
                field[nx][ny] = 0;
            }
            vis[nx][ny] = false;
        }
    }
}

int main () {
    scanf ("%d%d", &m, &n);
    for (int i = 1; i <= n; i ++) {
        int x, y, c;
        scanf ("%d%d%d", &x, &y, &c);
        field[x][y] = c + 1;
    }
    memset (cache, 0x3f, sizeof(cache));
    dfs (1, 1, 0, true);
    printf ("%d\n", ans == INT_MAX ? -1 : ans);
    return 0;
}