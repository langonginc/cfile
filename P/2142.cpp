#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 10086 + 10;

char s1[inf], s2[inf];
int a[inf], b[inf], c[inf];
bool positive = true;

int main ()
{
    cin >> s1 >> s2;
    int len1 = strlen(s1), len2 = strlen(s2);
    int len = max (len1, len2);
    if (len1 < len2 || (len1 == len2 && strcmp(s1, s2) < 0))
    {
        positive = false;
        swap (s1, s2);
        swap (len1, len2);
    }
    for (int i = 0; i < len1; i ++)
    {
        a[i] = s1[len1 - i - 1] - '0';
    }
    for (int i = 0; i < len2; i ++)
    {
        b[i] = s2[len2 - i - 1] - '0';
    }
    for (int i = 0; i < len; i ++)
    {
        if (a[i] < b[i])
        {
            a[i + 1] --, a[i] += 10;
        }
        c[i] = a[i] - b[i];
    }
    if (!positive) printf ("-");
    while (c[len] == 0 && len > 0) len --;
    while (len >= 0) printf ("%d", c[len --]);
    return 0;
}