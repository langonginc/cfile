#include <iostream>
#include <cstdio>
using namespace std;

int n, ans;

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = i + i; j <= n; j += i)
        {
            for (int k = j + j; k <= n; k += j)
            {
                if (i + j + k == n)
                {
                    ans ++;
                }
            }
        }
    }
    printf ("%d\n", ans);
    return 0;
}