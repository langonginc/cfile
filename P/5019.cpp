#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 100005;
int n, a[inf], ans;

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] > a[i - 1])
        {
            ans += a[i] - a[i - 1];
        }
    }
    printf ("%d", ans);
    return 0;
}