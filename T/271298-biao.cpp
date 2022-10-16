#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int inf = 1005;

int a[inf], num[inf], sum[inf], t, l ,r, p[inf][5];

int getwei (int x)
{
    if (x < 10) {
        return 1;
    }
    if (x >= 10 && x < 100) {
        return 2;
    }
    if (x >= 100 && x < 1000) {
        return 3;
    }
    return 0;
}

int getrest (int x, int k)
{
    if (x < 10) {
        return x;
    }
    if (x >= 10 && x < 100) {
        if (k % 2 == 0)
        {
            return x % 10;
        }
        else return x / 10 + x % 10;
    }
    if (x >= 100 && x < 1000) {
        if (k % 3 == 0)
        {
            return x % 100;
        }
        if (k % 3 == 1) return (x / 10) % 10 + x % 10;
        if (k % 3 == 2) return (x / 10) % 10 + x % 10 + x / 100;
    }
    return 0;
}

int getrest2 (int x, int k)
{
    if (x < 10) {
        return x;
    }
    if (x >= 10 && x < 100) {
        if (k % 2 == 0)
        {
            return x / 10;
        }
        else return x / 10 + x % 10;
    }
    if (x >= 100 && x < 1000) {
        if (k % 3 == 0)
        {
            return x / 100;
        }
        if (k % 3 == 1) return (x / 10) % 10 + x / 100;
        if (k % 3 == 2) return (x / 10) % 10 + x % 10 + x / 100;
    }
    return 0;
}

int main ()
{
//    int cnt = 0;
//    for (int i = 1; i <= 1e6 + 5; i ++)
//    {
//        for (int j = 1; j <= i; j ++)
//        {
//            printf ("%d", i);
//            if (i < 10) cnt += 1;
//            if (i >= 10 && i < 100) cnt += 2;
//            if (i >= 100 && i < 1000) cnt += 3;
//            if (i >= 1000 && i < 10000) cnt += 4;
//            if (i >= 10000) exit (1);
//            if (cnt > 1e6) exit (0);
//        }
//    }
//    cout << getrest (123, 1) << endl;
//    cout << getrest (123, 2) << endl;

    scanf ("%d", &t);

    for (int i = 1; i < inf - 1; i ++)
    {
        if (i < 10) {
            a[i] = a[i - 1] + 1 * i;
            num[i] = i;
            sum[i] = sum[i - 1] + num[i] * i;
            p[i][0] = 1, p[i][1] = i;
        }
        if (i >= 10 && i < 100) {
            a[i] = a[i - 1] + 2 * i;
            num[i] = i / 10 + i % 10;
            sum[i] = sum[i - 1] + num[i] * i;
            p[i][0] = 2, p[i][1] = i / 10, p[i][2] = i % 10;
        }
        if (i >= 100 && i < 1000) {
            a[i] = a[i - 1] + 3 * i;
            num[i] = i / 100 + (i / 10) % 10 + i % 10;
            sum[i] = sum[i - 1] + num[i] * i;
            p[i][0] = 3, p[i][1] = i / 100, p[i][2] = (i / 10) % 10, p[i][3] = i % 10;
        }
    }

    while (t --)
    {
        scanf ("%d%d", &l, &r);
        int left = 1, right = 819, mid, hl, hr, rl, rr;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (l <= a[mid])
            {
                right = mid - 1;
                hl = mid;
                rl = a[mid] - l;
            }
            else left = mid + 1;
        }

        left = 1, right = 819;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (r <= a[mid])
            {
                right = mid - 1;
                hr = mid;
                rr = r - a[mid - 1];
            }
            else left = mid + 1;
        }

//        printf ("%d=%d, %d=%d\n", hl, rl, hr, rr);
        int kl = rl / p[hl][0] * num[hl];
        for (int i = p[hl][0] - (rl % p[hl][0]); i <= p[hl][0]; i ++) kl += p[hl][i];
        int kr = (rr) / p[hr][0] * num[hr];
        for (int i = 1; i <= (rr) % p[hr][0]; i ++) kl += p[hr][i];
//        printf ("%d %d\n", kl, kr);

        int ans = kl + kr + sum[hr - 1] - sum[hl];
        printf ("%d\n", ans);
    }


    return 0;
}