#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 10005;

int n, t[inf], c[inf], p[inf], tm[inf * inf], val[inf * inf], dp[inf], nn, T;

int main ()
{
    int hh1, mm1, hh2, mm2;
    scanf ("%d:%d %d:%d %d", &hh1, &mm1, &hh2, &mm2, &n);
    T = (hh2 * 60 + mm2) - (hh1 * 60 + mm1);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d%d", &t[i], &c[i], &p[i]);
        if (p[i] == 0) p[i] = 1e7;
        int base = 1;
        while (p[i])
        {
            if (p[i] < base)
            {
                tm[++ nn] = p[i] * t[i];
                val[nn] = p[i] * c[i];
                break;
            }
            tm[++ nn] = base * t[i];
            val[nn] = base * c[i];
            p[i] -= base;
            base <<= 1;
        }
    }
    for (int i = 1; i <= nn; i ++)
    {
        for (int j = T; j >= tm[i]; j --)
        {
            dp[j] = max (dp[j], dp[j - tm[i]] + val[i]);
        }
    }
    printf ("%d\n", dp[T]);
    return 0;
}