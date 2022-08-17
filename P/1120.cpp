#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int inf = 65;

int n, a[inf], len[inf], sum, pre[inf], d;

void dfs (int nowlen, int rest, int p)
{
    if (nowlen == 0)
    {
        dfs (d, rest - 1, a[n]);
        return;
    }
    else if (rest == 0)
    {
        printf ("%d\n", d);
        exit (0);
    }
    if (p >= nowlen)
    {
        p = nowlen;
    }
    while (p && len[p] == 0) p --;
    for (; p; p = pre[p])
    {
        if (len[p])
        {
            len[p] --;
            dfs (nowlen - p, rest, p);
            len[p] ++;
            if ((nowlen == p) || (nowlen == d))
            {
                return;
            }
        }
    }
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
        len[a[i]] ++, sum += a[i];
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] != a[i - 1])
        {
            pre[a[i]] = a[i - 1];
        }
    }
    for (d = a[n]; (d << 1) <= sum; d ++)
    {
        if ((sum % d) == 0)
        {
            dfs (d, sum / d, a[n]);
        }
    }
    printf ("%d\n", sum); // :( So bad.
    return 0;
}