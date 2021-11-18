#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 5e5 + 5;
int t, n, a[inf];
int main ()
{
    scanf ("%d", &t);
    while (t --)
    {
        scanf ("%d", &n);
        for (int i = 1; i <= n; i ++)
        {
            scanf ("%d", &a[i]);
        }
        if (n & 1)
        {
            if (a[1] + a[2] != 0)
            {
                printf ("%d %d %d ", -a[3], -a[3], a[1] + a[2]);
            }
            else if (a[1] + a[3] != 0)
            {
                printf ("%d %d %d ", -a[2], a[1] + a[3], -a[2]);
            }
            else printf ("%d %d %d ", a[2] + a[3], -a[1], -a[1]);
        }
        for (int i = (n & 1) ? 4 : 1; i <= n; i += 2)
        {
            printf ("%d %d ", -a[i + 1], a[i]);
        }
        printf ("\n");
    }
    return 0;
}