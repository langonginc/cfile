#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 2e4 + 5;

int n, dpl[inf], dpr[inf], l[inf], r[inf];

inline int abs (int x)
{
    return x >= 0 ? x : -x;
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d", &l[i], &r[i]);
    }
    l[0] = 1, r[0] = 1;
    l[n + 1] = n, r[n + 1] = n;
    n ++;
    dpl[0] = dpr[0] = -1;
    for (int i = 1; i <= n; i ++)
    {
        dpl[i] = (r[i] - l[i]) + min (abs (r[i] - l[i - 1]) + dpl[i - 1], abs (r[i] - r[i - 1]) + dpr[i - 1]) + 1;
        dpr[i] = (r[i] - l[i]) + min (abs (l[i] - l[i - 1]) + dpl[i - 1], abs (l[i] - r[i - 1]) + dpr[i - 1]) + 1;
    }
    printf ("%d\n", min (dpl[n], dpr[n]) - 1);
    return 0;
}