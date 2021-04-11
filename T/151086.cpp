#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1005;

int n, value[inf];

int main ()
{
    cin >> n;
    for (int i = 2; i <= n; i ++)
    {
        for (int j = 1; j < i; j ++)
        {
            if (i % j == 0)
            {
                value[i] += j;
                // printf ("  %d: + %d\n", i, j);
            }
        }
        // printf ("%d: %d\n", i, value[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n - i; j ++)
        {
            for (int k = 1; k <= n - i - j; k ++)
            {
                if (i + j + k <= n)
                {
                    ans = max (value[i] + value[j] + value[k], ans);
                }
            }
        }
    }
    cout << ans;
    return 0;
}