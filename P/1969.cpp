#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main ()
{
    int n, a, now = 0, ans = 0;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a);
        if (a > now) ans += a - now;
        now = a;
    }
    printf ("%d\n", ans);
    return 0;
}