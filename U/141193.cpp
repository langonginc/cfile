#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

bool match1(char *x, char *y)
{
    int px = 0, py = 0, lx = strlen(x), ly = strlen(y);
    while (px < lx && py < ly)
    {
        if (x[px] == y[py])
        {
            py ++;
            // cout << 'y';
        }
        else
        {
            px ++;
            // cout << 'x';
        }
    }
    return py == ly;
}

bool match2(char *x, char *y)
{
    int px = 0, py = 0, lx = strlen(x), ly = strlen(y);
    while (px < lx && py < ly)
    {
        if (x[px] == y[py])
        {
            px ++, py ++;
        }
        else
        {
            py ++;
        }
    }
    if (px < lx)
    {
        return true;
    }
    return false;
}

int main ()
{
    char a[10000], b[10000];
    int t;
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%s%s", a, b);
        if (match1(a,b))
        {
            printf ("yes ");
            if (match2(a,b))
            {
                printf ("shiling ");
            }
            if (match2(b,a))
            {
                printf ("lianji ");
            }
            printf ("\n");
        }
        else
        {
            printf ("no\n");
        }
    }
    return 0;
}
