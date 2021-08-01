#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 10005;
int number[inf], n, m, t;

int main ()
{
    scanf ("%d", &t);
    while (t --)
    {
        memset (number, 0, sizeof (number));
        number[0] = 1;
        int len = 1, over = 0, count = 0;
        scanf ("%d%d", &n, &m);
        for (int i = 2; i <= n; i ++)
        {
            over = 0;
            for (int j = 0; j < len; j ++)
            {
                number[j] = number[j] * i + over;
                over = number[j] / 10;
                number[j] %= 10;
            }
            while (over > 0)
            {
                number[len ++] = over % 10;
                over /= 10;
            }
        }
        for (int i = 0; i < len; i ++)
        {
            if (number[i] == m)
            {
                count ++;
            }
        }
        printf ("%d\n", count);
    }
    return 0;
}