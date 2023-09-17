#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;

int n, a[maxn], b[maxn], c[maxn];
int dp[4 * maxn][5][5], ans;

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf ("%d%d%d", &a[i], &b[i], &c[i]);
    }
    a[n + 1] = a[1], b[n + 1] = b[1], c[n + 1] = c[1];
    for (int i = 2; i <= n + 1; i ++) {
        dp[i][1][1] = max (dp[i - 1][2][2], dp[i - 1][3][2]) + a[i];
        dp[i][2][1] = dp[i - 1][3][2] + b[i];
        dp[i][2][2] = dp[i - 1][1][1] + b[i];
        dp[i][3][2] = max (dp[i - 1][2][1], dp[i - 1][1][1]) + c[i];
    }
    for (int i = 1; i <= 3; i ++) {
        for (int j = 1; j <= 2; j ++)
        {
            ans = max (ans, dp[n + 1][i][j]);
        }
    }
    printf ("%d\n", ans);
    return 0;
}