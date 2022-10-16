#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int inf = 1e7 + 5;

int t, n, iserror[inf], nxt[inf], last;

inline bool have7 (int x)
{
    while (x)
    {
        if ((x % 10) == 7) return true;
        x /= 10;
    }
    return false;
}

int main ()
{
    for (int i = 1; i < inf; i ++)
    {
        if (iserror[i])
        {
            continue;
        }
        if (have7 (i))
        {
            for (int j = i; j < inf; j += i)
            {
                iserror[j] = true;
            }
        }
        else
        {
            nxt[last] = i;
            last = i;
        }
    }
    scanf ("%d", &t);
    while (t --)
    {
        scanf ("%d", &n);
        if (iserror[n])
        {
            printf ("-1\n");
        }
        else
        {
            printf ("%d\n", nxt[n]);
        }
    }
    return 0;
}
