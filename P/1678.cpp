#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
const int inf = 100005;

long long m, n, sch[inf], stu[inf];

inline long long aabs (long long x)
{
    return x >= 0 ? x : -x;
}

int main ()
{
    scanf ("%lld%lld", &m, &n);
    for (int i = 1; i <= m; i ++)
    {
        scanf ("%lld", &sch[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%lld", &stu[i]);
    }
    sort (sch + 1, sch + m + 1);
    long long res = 0;
    for (int i = 1; i <= n; i ++)
    {
        long long l = 1, r = m, mid, ans = LLONG_MAX;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (stu[i] == sch[mid])
            {
                ans = 0;
                break;
            }
            else if (stu[i] > sch[mid])
            {
                l = mid + 1;
                ans = min (ans, aabs (sch[mid] - stu[i]));
            }
            else 
            {
                r = mid - 1;
                ans = min (ans, aabs (sch[mid] - stu[i]));
            }
        }
        res += ans;
    }
    printf ("%lld\n", res);
    return 0;
}