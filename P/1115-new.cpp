#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
int n, a, f, ans = INT_MIN;

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a);
        f = max (f + a, a);
        ans = max (ans, f);
    }
    printf ("%d\n", ans);
    return 0;
}