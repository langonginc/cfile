#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 5005;

class Node
{
public:
    int l, r;
    bool operator < (const Node &x) const
    {
        if (l == x.l) return r < x.r;
        return l < x.l;
    }
} a[inf];

int n, dp[inf], ans;

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d", &a[i].l, &a[i].r);
    }
    sort (a + 1, a + n + 1);
    // for (int i = 1; i < n; i ++)
    // {
    //     for (int j = i + 1; j <= n; j ++)
    //     {
    //         if (a[i].r > a[j].r)
    //         {
    //             dp[i] = max (dp[i], dp[j] + 1);
    //         }
    //     }
    //     ans = max (ans, dp[i]);
    // }
    for (int i = 2; i <= n; i ++)
    {
        for (int j = 1; j < i; j ++)
        {
            if (a[j].r > a[i].r)
            {
                dp[i] = max (dp[i], dp[j] + 1);
            }
        }
        ans = max (ans, dp[i]);
    }
    printf ("%d", ans + 1);
    return 0;
}