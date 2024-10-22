#include <iostream>
#include <cstdio>
using namespace std;

int main () {
    long long t, n, k;
    cin >> t;
    while (t --) {
        cin >> n >> k;
        if (k == 0) {
            cout << 1 << endl;
        } else {
            long long x = n / (k + 1ll);
            long long y = n / k;
            cout << y - x << endl;
        }
    }
    return 0;
}