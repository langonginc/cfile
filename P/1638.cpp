#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, a[1000005], b[2005], ans;

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    int left = 1, right = 1, k = 1, ansleft, ansright;
    b[a[1]] = 1;
    ans = 10000005;
    while (left <= right && right <= n)
    {
        if (k == m)
        {
            if (ans > right - left + 1)
            {
                ans = right - left + 1;
                ansleft = left, ansright = right;
            }
            b[a[left]] --;
            if (b[a[left]] == 0)
            {
                k --;
            }
            left ++;
        }
        else
        {
            right ++;
            b[a[right]] ++;
            if (b[a[right]] == 1)
            {
                k ++;
            }
        }
    }
    printf ("%d %d\n", ansleft, ansright);
    return 0;
}