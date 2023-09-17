#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

int n, k, num[15], cnt;

void dfs (int wei)
{
    if (wei > k)
    {
        int x = num[1], flag = 0;
        for (int i = 2; i < wei; i ++)
        {
            if (x != num[i])
            {
                flag = 1;
            }
        }
        if (wei != 2 && flag == 0) return;
        for (int i = 1; i < wei; i ++)
        {
            printf ("%d", num[i]);
        }
        printf (", ");
        cnt ++;
        return;
    }
    num[wei] = 6;
    dfs (wei + 1);
    num[wei] = 8;
    dfs (wei + 1);
    num[wei] = 0;
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        k = i;
        dfs (1);
    }
    printf ("\n");
    printf ("%d\n", cnt);
    return 0;
}