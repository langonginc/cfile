#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 5 * 1e5 + 5;
class Number
{
    public:
        ll start, end;
        bool operator < (const Number &t) const
        {
            if (start < t.start) return true;
            else if (start > t.start) return false;
            else if (end > t.end) return true;
            else return false;
        }
}a[inf];

int n;

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        ll x, y;
        scanf ("%lld%lld", &x, &y);
        a[i].start = x - y, a[i].end = x + y;
    }
    sort (a + 1, a + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
    {
        int j = i + 1;
        while (j <= n && a[j].start >= a[i].start && a[j].end <= a[i].end)
        {
            cnt ++;
            j ++;
        }
        i = j - 1;
    }
    printf ("%d", n - cnt);
    return 0;
}