#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
const int inf = 1e6 + 5;

int n, m, a[inf], sum[inf], num, ansl, ansr, ansn = INT_MAX;

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    int l = 1, r = 0;
    while (l <= r + 1 && r <= n)
    {
        if (num < m) // less than all -> take right
        {
            if (sum[a[++ r]] == 0)
            {
                num ++;
            }
            sum[a[r]] ++;
        }
        else
        {
            if (ansn > r - l + 1)
            {
                ansn = r - l + 1;
                ansl = l, ansr = r;
            }
            if (sum[a[l]] == 1)
            {
                num --;
            }
            sum[a[l ++]] --;
        }
    }
    printf ("%d %d\n", ansl, ansr);
    return 0;
}