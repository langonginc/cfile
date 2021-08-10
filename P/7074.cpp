#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
// typedef int ll;
const int inf = 1005;
const ll INF = LLONG_MIN;

ll a[inf][inf], f[inf][inf][4];
/*
0 => right
1 => down
2 => up
*/
int n, m;
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            scanf ("%lld", &a[i][j]);
            f[i][j][0] = f[i][j][1] = f[i][j][2] = INF;
        }
    }
    f[1][1][0] = f[1][1][1] = f[1][1][2] = a[1][1];
    for (int i = 2; i <= n; i ++)
    {
        f[i][1][1] = f[i - 1][1][1] + a[i][1];
    }
    for (int j = 2; j <= m; j ++) // Go by rows
    {
        // f[1][j][0] = f[1][j][1] = f[1][j][2] = a[1][j];
        // f[n - 1][j][0] = f[n - 1][j][1] = f[n - 1][j][2] = a[n - 1][j];
        for (int i = 1; i <= n; i ++)
        {
            f[i][j][0] = max (f[i][j - 1][0], max (f[i][j - 1][1], f[i][j - 1][2])) + a[i][j];
        }
        for (int i = 2; i <= n; i ++)
        {
            f[i][j][1] = max (f[i - 1][j][0], f[i - 1][j][1]) + a[i][j];
        }
        for (int i = n - 1; i >= 1; i --)
        {
            f[i][j][2] = max (f[i + 1][j][0], f[i + 1][j][2]) + a[i][j];
            // ll n1=f[i + 1][j][0];
            // ll n2= f[i + 1][j][2];
            // printf ("%d", max(n1,n2));
            // printf ("%d,%d: %d/%d(%d) + %d = %d\n", i, j,n1 , 
            //    n2, max (n1,n2), a[i][j], 
            //     f[i][j][2]);
        }
    }
    printf ("%lld\n", max (f[n][m][0], max (f[n][m][1], f[n][m][2])));
    // for (int i = 1; i <= n; i ++)
    // {
    //     for (int j = 1; j <= m; j ++)
    //     {
    //         printf ("%d ", max (f[i][j][0], max (f[i][j][1], f[i][j][2])));
    //     }
    //     printf ("\n");
    // }
    // for (int i = 1; i <= n; i ++)
    // {
    //     for (int j = 1; j <= m; j ++)
    //     {
    //         printf ("%d ", f[i][j][0]);
    //     }
    //     printf ("\n");
    // }
    // for (int i = 1; i <= n; i ++)
    // {
    //     for (int j = 1; j <= m; j ++)
    //     {
    //         printf ("%d ", f[i][j][1]);
    //     }
    //     printf ("\n");
    // }
    // for (int i = 1; i <= n; i ++)
    // {
    //     for (int j = 1; j <= m; j ++)
    //     {
    //         printf ("%d ", f[i][j][2]);
    //     }
    //     printf ("\n");
    // }
    return 0;
}