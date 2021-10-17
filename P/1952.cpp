#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, a[205], b[205], c[205];
string s1, s2;

inline int char_to_int (char x)
{
    if (x >= '0' && x <= '9')
    {
        return x - '0';
    }
    return x - 'a' + 10;
}

inline char int_to_char (int x)
{
    if (x < 10) return x + '0';
    return x + 'a' - 10;
}

int main ()
{
    cin >> n >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();
    int len = max (len1, len2);
    for (int i = 0; i < len1; i ++)
    {
        a[len1 - i] = char_to_int (s1[i]);
    }
    for (int i = 0; i < len2; i ++)
    {
        b[len2 - i] = char_to_int (s2[i]);
    }
    for (int i = 1; i <= len; i ++)
    {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / n;
        c[i] %= n;
    }
    if (c[len + 1] != 0) len ++;
    for (int i = len; i > 0; i --)
    {
        printf ("%c", int_to_char (c[i]));
    }
    return 0;
}