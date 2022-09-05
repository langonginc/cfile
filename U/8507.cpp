#include <iostream>
#include <cstdio>
using namespace std;

int a, b;

int main ()
{
    scanf ("%d%d", &a, &b);
    int estudent = b / a;
    double ans = double (estudent) / double (b);
    printf ("%.16lf\n", ans);
    return 0;
}