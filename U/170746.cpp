#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[105];
int cnt, t;

int main ()
{
    scanf ("%d", &t);
    while (t --)
    {
        cnt = 0;
        scanf ("%s", str);
        for (int i = 0; i < strlen(str);)
        {
            int l = 0;
            while (str[i ++] == 'L' )
            {
                l ++;
            }
            cnt = max (cnt, l);
        }
        printf ("%d\n", cnt + 1);
    }
    return 0;
}