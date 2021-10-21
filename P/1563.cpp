#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1e5 + 5;
int n, m, side[inf];
char name[inf][5005];

inline int rp (int i, int a, int s)
{
    if (side[i] == 0)
    {
        if (a)
        {
            return s;
        }
        else return -s;
    }
    else
    {
        if (a)
        {
            return -s;
        }
        else return s;
    }
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i ++)
    {
        scanf ("%d%s\n", &side[i], name[i]);
    }
    int p = 0;
    for (int i = 1; i <= m; i ++)
    {
        int a, s;
        scanf ("%d%d", &a, &s);
        p = (p + rp (p, a, s) + n + n) % n;
    }
    printf ("%s\n", name[p]);
    return 0;
}