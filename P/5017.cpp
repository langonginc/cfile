#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a[105], dp[4000005][2];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf ("%d", &a[i]);
    }
    sort (a + 1, a + n + 1);
    int now = 1;
    for (int i = 1; i <= a[n]; i ++) {
        dp[i][0] = min (dp[i - 1][0], dp[i - 1][1]);
        if (a[now] == i) {
            dp[i][1] = min (dp[i - 1][0], dp[i - m][1])
        }
    }
}