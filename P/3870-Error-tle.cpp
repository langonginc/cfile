#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int inf = 2e5 + 5;
int n, m, a[inf], t[inf], tag[inf], sqrtn;

inline int pos (int l)
{
    return l / sqrtn + (l % sqrtn != 0);
}

inline int inpos (int l)
{
    return l % sqrtn;
}

void movetag (int p)
{
    if (tag[p])
    {
        for (int i = (p - 1) * sqrtn + 1; i <= p * sqrtn; i++)
        {
            a[i] = !a[i];
        }
        tag[p] = 0;
    }
}

void update (int l, int r)
{
    // for (int i = pos (l) + (inpos(l - 1) ? 1 : 0); i < pos(r) + (inpos(r) ? 0 : 1); i ++)
    // {
    //     tag[i] = !tag[i];
    //     if (tag[i] ^ a[]) t[i] += sqrtn;
    //     else t[i] -= sqrtn;
    // }
    // if (inpos (l - 1))
    // {
    //     movetag (pos (l));
    //     for (int i = l; i <= pos (l) * sqrtn; i ++)
    //     {
    //         a[i] = !a[i];
    //         if (a[i]) t[i] ++;
    //         else t[i] --;
    //     }
    // }
    // if (inpos (r))
    // {
    //     movetag (pos (r));
    //     for (int i = (pos (r) - 1) * sqrtn + 1; i <= r; i ++)
    //     {
    //         a[i] = !a[i];
    //         if (a[i]) t[i] ++;
    //         else t[i] --;
    //     }
    // }
    for (int i = l; i <= r; i ++)
    {
        a[i] = !a[i];
        if (a[i]) t[pos (i)] ++;
        else t[pos (i)] --;
    }
}

int query (int l, int r)
{
    int result = 0;
    for (int i = pos (l) + (inpos(l - 1) ? 1 : 0); i < pos(r) + (inpos(r) ? 0 : 1); i ++)
    {
        result += t[i];
        // printf ("GET %d from block %d\n", t[i], i);
    }
    if (inpos (l - 1))
    {
        movetag (pos (l));
        for (int i = l; i <= pos (l) * sqrtn; i ++)
        {
            result += a[i];
        }
    }
    if (inpos (r))
    {
        movetag (pos (r));
        for (int i = (pos (r) - 1) * sqrtn + 1; i <= r; i ++)
        {
            result += a[i];
        }
    }
    return result;
}

int main ()
{
    scanf ("%d%d", &n, &m);
    sqrtn = sqrt (n);
    while (m --)
    {
        int op, l, r;
        scanf ("%d%d%d", &op, &l, &r);
        if (op == 0)
        {
            update (l, r);
        }
        else printf ("%d\n", query (l, r));
    }
    return 0;
}