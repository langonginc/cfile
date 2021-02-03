#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int inf = 1e5 + 10;

long long f[inf];

int main ()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        printf ("0");
        return 0;
    }
    if (n == 2)
    {
        printf ("00");
        return 0;
    }
    int t;
    f[1] = 0, f[2] = 1;
    printf ("00");
    int cnt = 3;
    for (int i = 3; i <= n; i ++)
    {
        f[i] = f[i - 1] + f[i - 2];
        while (cnt < f[i])
        {
            if (cnt > n) return 0;
            printf ("o");
            cnt ++;
        }
        if (cnt == f[i]){
            if (cnt > n) return 0;
            cnt ++;
            printf ("0");
        }
    }
    while (cnt <= n)
    {
        printf ("o");
        cnt ++;
    }
    return 0;
}
