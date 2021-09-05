#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1e6 + 5;

int n, l[inf], ans;

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &l[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        if (l[i] != 0)
        {
            int x = l[i] + 1;
            l[i] = 0;
            for (int j = i + 1; j <= n; j ++)
            {
                if (l[j] != 0 && l[j] == x)
                {
                    l[j] = 0;
                    x ++;
                }
            }
            ans ++;
        }
    }
    cout << ans;
    return 0;
}