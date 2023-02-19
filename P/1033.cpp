#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double h, s, v, l, k;
int n;

int main ()
{
    scanf ("%lf%lf%lf%lf%lf%d", &h, &s, &v, &l, &k, &n);
    double t1 = sqrt (2.0 * h / 10.0), t2 = sqrt (2.0 * (h - k) / 10.0);
    int s1 = int (s - t2 * v + l), s2 = int (s - t1 * v);
    printf ("%d", min (s1, n) - max (s2, 0));
    return 0;
}