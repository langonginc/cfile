#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 1e6 + 5;

int n, q, a[maxn];
int sqrtN, tag[maxn];

int queryOver (int l, int r, int c)
{
    int k1 = 0, k2 = 0, ans = 0;
    while (sqrtN * k1 < l) k1 ++;
    while (sqrtN * k2 <= r) k2 ++;
    k2 --;
    for (int i = k1; i < k2; i ++)
    {
        for (int j = i * sqrtN; j < (i + 1) * sqrtN; j ++)
        {
            if (a[j] + tag[i] >= c)
            {
                ans ++;
            }
        }
    }
    for (int i = l; i < sqrtN * k1; i ++)
    {
        if (a[i] + tag[k1 - 1] >= c)
        {
            ans ++;
        }
    }
    for (int i = sqrtN * k2; i <= r; i ++)
    {
        if (a[i] + tag[k2] >= c)
        {
            ans ++;
        }
    }
    return ans;
}

void add (int l, int r, int w)
{
    int k1 = 0, k2 = 0;
    while (sqrtN * k1 < l) k1 ++;
    while (sqrtN * k2 <= r) k2 ++;
    k2 --;
    for (int i = k1; i < k2; i ++)
    {
        tag[i] += w;
    }
    for (int i = l; i < sqrtN * k1; i ++)
    {
        a[i] += w;
    }
    for (int i = sqrtN * k2; i <= r; i ++)
    {
        a[i] += w;
    }
}

int main ()
{
    scanf ("%d%d", &n, &q);
    for (int i = 0; i < n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    sqrtN = int (sqrt (n));
    for (int i = 1; i <= q; i ++)
    {
        char ch;
        int l, r, x;
        scanf ("\n%c%d%d%d", &ch, &l, &r, &x);
        l --, r --;
        if (ch == 'M') add (l, r, x);
        else printf ("%d\n", queryOver (l, r, x));
    }
    return 0;
}