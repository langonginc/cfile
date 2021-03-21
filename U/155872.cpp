#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int inf = 1e7 + 5;
const ll p = 998244353;

ll inv[inf], n, sum;

int main ()
{
    cin >> n;
    inv[1] = 1;
    for (int i = 2; i <= n; i ++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
        sum = (sum + inv[i]) % p;
    }
    cout << (sum + 1) % p << endl;
    return 0;
}
