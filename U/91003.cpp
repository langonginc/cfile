#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
const int moo = 1e9 + 7;
const int inf = 1e7+10;

ll a, b;
ll dp[inf];

int main ()
{
    scanf ("%lld%lld", &a, &b);
    dp[1] = 1;
    dp[2] = 1;
    for (ll i = 3; i <= b - a + 1; i ++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % moo;
    }
    printf ("%lld\n", dp[b - a + 1] % moo);
    return 0;
}
