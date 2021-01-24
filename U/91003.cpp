#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
const int moo = 1e9 + 7;
const int inf = 35;

ll a, b;
ll dp[inf];

int main ()
{
    scanf ("%lld%lld", &a, &b);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= b; i ++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf ("%lld\n", (dp[b] - dp[a] + 1) % moo);
    return 0;
}