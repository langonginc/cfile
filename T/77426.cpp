#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;

inline ll popcount (ll x)
{
    ll ans = 0;
    while (x > 0)
    {
        ans += x % 2;
        x >>= 1;
    }
    return ans;
}

inline ll lowbit (ll x)
{
    return x & -x;
}

int main ()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    while (popcount(n) > k)
    {
        ans += lowbit (n);
        n += lowbit (n);
    }
    cout << ans << endl;
    return 0;
}
