#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1e7 + 5;

int t, n, iserror[inf], w[205], wc;

inline void adder () // No Problem
{
    w[1] ++;
    for (int i = 1; i <= wc; i ++)
    {
        w[i + 1] += w[i] / 10;
        w[i] %= 10;
    }
    if (w[wc + 1] != 0) wc ++;
}

int main ()
{
    w[1] = 0, wc = 1;
    for (int i = 1; i < inf; i ++)
    {
//        adder ();
//        if (iserror[i])
//        {
//            continue;
//        }
//        bool flag = false;
//        for (int j = 1; j <= wc; j ++)
//        {
//            if (w[j] == 7) flag = true;
//        }
//        // if (flag || i % 7 == 0)
//        if (flag)
//        {
//            for (int j = i; j < inf; j += i)
//            {
//                iserror[j] = true;
//            }
//        }
        if (iserror [i])
        {
            for (int j = 1; j <=)
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
            while (iserror[++ n]);
            printf ("%d\n", n);
        }
    }
    return 0;
}
