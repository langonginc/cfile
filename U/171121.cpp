#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 15;
class Group
{
    public:
        int t, len, a[13];
} group[1005];
int n, m, a[inf], grc;

int main ()
{
    // memset (a, 0x3f, sizeof (a));

    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        a[i] = 2147483647;
    }
    for (int i = 1; i <= n; i ++)
    {
        int t, b;
        scanf ("%d%d", &t, &b);
        if (b == 1)
        {
            int c;
            scanf ("%d", &c);
            a[c] = min (a[c], t);
        }
        else
        {
            grc ++;
            group[grc].len = b, group[grc].t = t;
            for (int j = 1; j <= b; j ++)
            {
                scanf ("%d", &group[grc].a[j]);
            }
        }
    }
    // for (int i = 1; i <= grc; i ++)
    // {
    //     int sum = 0;
    //     for (int j = 1; j <= group[i].len; j ++)
    //     {
    //         sum += a[group[i].a[j]];
    //     }
    //     if (group[i].t < sum)
    //     {

    //     }
    // }
    int sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] == 2147483647)
        {
            printf ("-1");
            return 0;
        }
        sum += a[i];
    }
    printf ("%d", sum);
    return 0;
}