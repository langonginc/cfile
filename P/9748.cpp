#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main () {
    int n, ans = 0, ans2 = 0;
    scanf ("%d", &n);
    while (n > 0) {
        ans ++;
        if ((n - 1) % 3 == 0 && ans2 == 0) {
            ans2 = ans;
        }
        n -= (n - 1) / 3 + 1;
    }
    printf ("%d %d\n", ans, ans2 == 0 ? ans : ans2);
    return 0;
}