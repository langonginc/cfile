#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, f[15];

int main ()
{
    scanf ("%lld", &n);
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    for (int i = 4; i <= n; i ++)
    {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
    printf ("%lld\n", f[n]);
    return 0;
}