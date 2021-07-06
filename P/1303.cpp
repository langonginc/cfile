#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 50001;
char cha[inf], chb[inf];
int a[inf], b[inf], c[inf];

int main ()
{
    cin >> cha >> chb;
    int lena = strlen(cha), lenb = strlen(chb);
    for (int i = 0; i < lena; i ++) a[i] = cha[i] - '0';
    for (int i = 0; i < lenb; i ++) b[i] = chb[i] - '0';
    for (int i = 0; i < lena; i ++)
    {
        for (int j = 0; j < lenb; j ++)
        {
            c[i + j + 1] += a[i] * a[j];
            printf (" [INFO] %d/%d : Add %d*%d=%d\n", i, j, a[i], a[j], c[i + j + 1]);
        }
    }
    int len = lena + lenb + 1;
    for (int i = len - 1; i >= 0; i --)
    {
        if (c[i] >= 10)
        {
            c[i - 1] += c[i] / 10;
            printf (" [INFO] %d : Move %d to %d\n", i, c[i], c[i - 1]);
            c[i] %= 10;
            printf (" [INFO] %d : Move %d\n", i, c[i]);
        }
    }
    while (c[len] == 0 && len > 0) len --;
    int left = 0;
    while (c[left] == 0 && left < len) left ++;
    for (int i = left; i <= len; i ++)
    {
        printf ("%d", c[i]);
    }
    return 0;
}