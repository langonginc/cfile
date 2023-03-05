#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool b[15]; 

bool split (int x)
{
    while (x > 0)
    {
        if (b[x % 10] || x % 10 == 0) return false;
        else b[x % 10] = true;
        x /= 10;
    }
    return true;
}

int main ()
{
    for (int i = 1; i <= 9; i ++)
    {
        for (int j = 1; j <= 9; j ++)
        {
            for (int k = 1; k <= 9; k ++)
            {
                memset (b, 0, sizeof (b));
                int a = i * 100 + j * 10 + k;
                int b = a * 2;
                int c = a * 3;
                if (split (a) && split (b) && split (c))
                {
                    printf ("%d %d %d\n", a, b, c);
                }
            }
        }
    }
    return 0;
}