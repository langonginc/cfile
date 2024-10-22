#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;

inline int mmin (int x, int y, int z) {
    return min(min(x, y), z);
}

struct Member {
    int id, a, b, c, rankA, rankB, rankC;
    Member () {}
    Member (int _id, int _a, int _b, int _c) {
        id = _id, a = _a, b = _b, c = _c;
    }
    const int vmin () {
        return mmin(rankA, rankB, rankC);
    }
} a[maxn];

bool cmpA (Member x, Member y) {
    return x.a > y.a;
}

bool cmpB (Member x, Member y) {
    return x.b > y.b;
}

bool cmpC (Member x, Member y) {
    return x.c > y.c;
}

bool cmpId (Member x, Member y) {
    return x.id < y.id;
}

int n;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[i] = Member(i, x, y, z);
    }
    a[0] = Member(0, -1, -1, -1);
    sort(a + 1, a + n + 1, cmpA);
    for (int i = 1; i <= n; i ++) {
        if (a[i].a == a[i - 1].a) {
            a[i].rankA = a[i - 1].rankA;
        } else {
            a[i].rankA = i;
        }
    }
    sort(a + 1, a + n + 1, cmpB);
    for (int i = 1; i <= n; i ++) {
        if (a[i].b == a[i - 1].b) {
            a[i].rankB = a[i - 1].rankB;
        } else {
            a[i].rankB = i;
        }
    }
    sort(a + 1, a + n + 1, cmpC);
    for (int i = 1; i <= n; i ++) {
        if (a[i].c == a[i - 1].c) {
            a[i].rankC = a[i - 1].rankC;
        } else {
            a[i].rankC = i;
        }
    }
    sort(a + 1, a + n + 1, cmpId);
    for (int i = 1; i <= n; i ++) {
        printf ("%d\n", a[i].vmin());
    }
    return 0;
}