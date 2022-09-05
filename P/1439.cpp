#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
const int inf = 1e5 + 5;

int n, f[inf], id[inf], b[inf], len;

int main ()
{
    scanf ("%d", &n);
    int x;
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &x);
        id[x] = i;
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &x);
        b[i] = id[x];
    }
    for (int i = 1; i <= n; i ++)
    {
        f[i] = INT_MAX;
    }
    f[0] = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (b[i] > f[len])
        {
            f[++ len] = b[i];
        }
        else
        {
            int left = 0, right = len, mid;
            while (left < right)
            {
                mid = (left + right) >> 1;
                if (f[mid] > b[i])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            f[left] = min (f[left], b[i]);
        }
    }
    printf ("%d\n", len);
    return 0;
}