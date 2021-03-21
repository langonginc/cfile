#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
using namespace std;
const int inf = 1005;

int n, g[inf][inf];

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int k, x;
        scanf ("%d", &k);
        for (int j = 1; j <= k; j ++)
        {
            scanf ("%d", &x);
            g[i][x] = 1;
            // g[x][i] = 1;
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            printf ("%d ", g[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
