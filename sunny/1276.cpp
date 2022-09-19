#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1e5 + 5;

int num[inf];
char str[inf];

int main ()
{
    cin >> str;
    int len = strlen (str);
    for (int i = 0, j = len - 1; i < len; i ++, j --)
    {
        num[i] = str[j] - '0';
    }
    while (true)
    {
        int sum = 0;
        for (int i = 0; i < len; i ++)
        {
            sum += num[i];
        }
        if (sum < 10)
        {
            printf ("%d\n", sum);
            break;
        }
        len = 0;
        while (sum)
        {
            num[len ++] = sum % 10;
            sum /= 10;
        }
    }
    return 0;
}