#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char mid[55], aft[55];

void dfs (int midl, int midr, int aftl, int aftr)
{
    if (midl > midr || aftl > aftr)
    {
        return;
    }
    printf ("%c", aft[aftr]);
    for (int i = midl; i <= midr; i ++)
    {
        if (mid[i] == aft[aftr])
        {
            dfs (midl, i - 1, aftl, aftl + i - midl - 1);
            dfs (i + 1, midr, aftl + i - midl, aftr - 1);
            break;
        }
    }
}

int main ()
{
    scanf ("%s%s", mid, aft);
    dfs (0, strlen(mid) - 1, 0, strlen(mid) - 1);
    return 0;
}