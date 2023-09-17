#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e3 + 5;

int a[maxn][maxn], b[maxn][maxn];

int main ()
{
    int n, k, x1, y1, x2, y2, ans = 0;
    scanf ("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
        a[x2][y2] ++;
        a[x1][y1] ++;
        a[x1][y2] --;
        a[x2][y1] --;
    }
    for (int i = 0; i <= 1e3; i ++)
    {
        for (int j = 0; j <= 1e3; j ++)
        {
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
            if (b[i][j] == k)
            {
                ans ++;
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}