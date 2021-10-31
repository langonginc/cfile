#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main ()
{
    int t, a, b, c;
    scanf ("%d", &t);
    while (t --)
    {
        scanf ("%d%d%d", &a, &b, &c);
        if (a > b && a > c)
            printf ("0 ");
        else printf ("%d ", max (b, c) - a + 1);

        if (b > a && b > c)
            printf ("0 ");
        else printf ("%d ", max (a, c) - b + 1);

        if (c > a && c > b)
            printf ("0\n");
        else printf ("%d\n",max (a, b) - c + 1);
    }
    return 0;
}