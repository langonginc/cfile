#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
const ll moder = 1e9 + 7;

ll n, a[maxn], b[maxn], pa[maxn], pb[maxn], ans;
ll ppa[maxn], ppb[maxn], pab[maxn];

int main () {
    scanf ("%lld", &n);
    for (int i = 1; i <= n; i ++) {
        scanf ("%lld", &a[i]);
        pa[i] = (pa[i - 1] + a[i]) % moder;
        ppa[i] = (ppa[i - 1] + pa[i]) % moder;
    }
    for (int i = 1; i <= n; i ++) {
        scanf ("%lld", &b[i]);
        pb[i] = (pb[i - 1] + b[i]) % moder;
        ppb[i] = (ppb[i - 1] + pb[i]) % moder;
    }
    for (int i = 1; i <= n; i ++) {
        pab[i] = (pab[i - 1] + (pa[i] * pb[i]) % moder) % moder;
    }
    for (int i = 1; i <= n; i ++) {
        // for (int j = i; j <= n; j ++) {
            ll a1 = (pab[n] - pab[i - 1] + moder) % moder;
            ll a2 = (pb[i - 1] * ((ppa[n] - ppa[i - 1] + moder) % moder) + moder) % moder;
            ll a3 = (pa[i - 1] * ((ppb[n] - ppb[i - 1] + moder) % moder) + moder) % moder;
            ll a4 = ((n - i + 1) * (pa[i - 1] * pb[i - 1] % moder) + moder) % moder;
            ans = (ans + a1 - a2 - a3 + a4 + moder) % moder;
            // ans = (ans + ((pa[j] - pa[i - 1]) * (pb[j] - pb[i - 1])) % moder) % moder;
        // }
    }
    printf ("%lld\n", ans);
    return 0;
}