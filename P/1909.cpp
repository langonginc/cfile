#include <iostream>
using namespace std;
typedef long long ll;

int main ()
{
    ll n, a1, a2, a3, b1, b2, b3, ans1 = 0, ans2 = 0, ans3 = 0, ans;
    cin >> n >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    ll n1 = n;
    while (n1 > 0)
    {
        n1 -= a1, ans1 += b1;
    }
    ll n2 = n;
    while (n2 > 0)
    {
        n2 -= a2, ans2 += b2;
    }
    ll n3 = n;
    while (n3 > 0)
    {
        n3 -= a3, ans3 += b3;
    }
    ans = min (ans1, min(ans2,ans3));
    cout << ans << endl;
    return 0;
}
