#include <iostream>
#include <cstdio>
using namespace std;

int n, k, a[105];

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        scanf ("%d", &a[i]);
        if (a[i] == 0)
        {
            a[i] = 3;
        }
    }
    scanf ("%d", &k);
    int x = 0, fcase = 0;
    while (true)
    {
        fcase = 0;
        for (int i = 0; i < n; i ++)
        {
            if (a[i] != 0)
            {
                x ++;
                if (x == k)
                {
                    x = 0;
                    // printf ("- %d\n", i);
                    a[i] --;
                    // fcase ++;
                }
            } else 
            {
                fcase ++;
            }
        }
        if (fcase >= n - 1)
        {
            break;
        }
    }
    for (int i = 0; i < n; i ++)
    {
        if (a[i] != 0)
        {
            printf ("%d\n", i + 1);
        }
    }
    return 0;
}