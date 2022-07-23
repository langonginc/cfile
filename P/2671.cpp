#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
// typedef long long ll;
const int inf = 1e5 + 5;
const int moder = 10007;

int n, m, num[inf], col[inf];
int scount[inf][2], ssum[inf][2], ans;

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &num[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &col[i]);
        scount[col[i]][i % 2] ++;
        ssum[col[i]][i % 2] = (ssum[col[i]][i % 2] + num[i]) % moder;
    }
    for (int i = 1; i <= n; i ++)
    {
        ans = (i * ((ssum[col[i]][i % 2] - num[i]) + num[i] * (scount[col[i]][i % 2] - 1) % moder) % moder + ans) % moder;
    }
    printf ("%d\n", ans % moder);
    return 0;
}