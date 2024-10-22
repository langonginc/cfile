#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main () {
    int t, n, m;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        if (m == n || (m + 1) / n >= 2) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}