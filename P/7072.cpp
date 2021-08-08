#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 100005;
int b[inf], n, w;

int main ()
{
    scanf ("%d%d", &n, &w);
    for (int i = 1; i <= n; i ++)
    {
        int a;
        scanf ("%d", &a);
        b[a] ++;
        int p = max (1, i * w / 100), cnt = 0, line = 601;
        while (cnt < p)
        {
            cnt += b[-- line];
        }
        printf ("%d ", line);
    }
    return 0;
}