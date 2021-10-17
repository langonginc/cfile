#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    int s, v, minute = 0, hour = 8;
    scanf ("%d%d", &s, &v);
    int t = s / v + (s % v == 0 ? 0 : 1) + 10;
    if (t / 60 >= 8 && t % 60 != 0)
    {
        hour = 24 - t / 60 + 8 + (t % 60 == 0 ? 0 : -1);
        minute = (60 - t % 60) % 60;
    }
    else
    {
        hour = hour - t / 60 + (t % 60 == 0 ? 0 : -1);
        minute = (60 - t % 60) % 60;
    }
    if (hour < 10) printf ("0");
    printf ("%d:", hour);
    if (minute < 10) printf ("0");
    printf ("%d\n", minute);
    return 0;
}