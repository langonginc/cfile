#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 200;
int n, k, ans;

void dfs (int d, int sum, int v)
{
    if (sum > n) return;
    if (d > k)
    {
        if (sum == n)
        {
            ans ++;
        }
        return ;
    }
    for (int i = v; i <= n - sum; i ++)
    {
        dfs (d + 1, sum + i, i);
    }
}

int main ()
{
    cin >> n >> k;
    dfs (1, 0, 1);
    cout << ans;
    return 0;
}