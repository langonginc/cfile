#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    long long t, a, b, c;
    scanf ("%lld", &t);
    while (t --)
    {
        scanf ("%lld%lld%lld", &a, &b, &c);
        printf ("%lld\n", (a + 2 * b + 3 * c) % 2);
    }
    return 0;
}