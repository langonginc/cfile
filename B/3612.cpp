#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 1e5 + 5;

int pre[inf], n, a, b;

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a);
        pre[i] = pre[i - 1] + a;
    }
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d%d", &a, &b);
        printf ("%d\n", pre[b] - pre[a - 1]);
    }
    return 0;
}