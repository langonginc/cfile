#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 4e4 +5;

int n, a[inf], b[inf], butn, setn, but[inf], flag[inf];
ll ans, set[inf];

inline int get (int x)
{
    return lower_bound (set + 1, set + setn + 1, x) - set;
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d", &a[i], &b[i]);
        but[++ butn] = a[i], but[++ butn] = b[i];
    }
    sort (but, but + butn + 1);
    for (int i = 1; i <= butn; i ++)
    {
        if (but[i] != but[i - 1] || i == 1)
        {
            set[++ setn] = ll (but[i]);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        int x = get (a[i]), y = get(b[i]);
        for (int j = x; j < y; j ++)
        {
            flag[j] = 1;
        }
    }
    for (int i = 1; i < setn; i ++)
    {
        if (flag[i])
        {
            ans += set[i + 1] - set[i];
        }
    }
    printf ("%lld\n", ans);
    return 0;
}