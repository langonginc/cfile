#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;

int main ()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    while (n > k)
    {
        ans += (n % 2);
        n >>= 1;
    }
    ans += k - n;
    cout << ans;
    return 0;
}
