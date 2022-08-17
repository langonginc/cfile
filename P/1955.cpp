#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
const int inf = 1e6 + 5;

class Checkset
{
    private:
        int f[inf];
    public:
        void init (int max_value = inf)
        {
            for (int i = 1; i <= max_value; i ++)
            {
                f[i] = i;
            }
        }
        int find (int x)
        {
            if (f[x] == x)
            {
                return x;
            }
            return f[x] = find (f[x]);
        }
        void merge (int x, int y)
        {
            x = find (x), y = find (y);
            if (x != y)
            {
                f[x] = y;
            }
        }
} *checkset = new Checkset();

int n, x[inf], y[inf], z[inf], b[inf], s[inf], bn, sn;

int main ()
{
    int t;
    scanf ("%d", &t);
    while (t --)
    {
        bn = 0, sn = 0;        
        scanf ("%d", &n);
        for (int i = 1; i <= n; i ++)
        {
            scanf ("%d%d%d", &x[i], &y[i], &z[i]);
            b[++ bn] = x[i], b[++ bn] = y[i];
        }
        sort (b + 1, b + bn + 1);
        for (int i = 1; i <= bn; i ++)
        {
            if (b[i] != b[i - 1])
            {
                s[++ sn] = b[i];
            }
        }
        for (int i = 1; i <= n; i ++)
        {
            x[i] = lower_bound (s + 1, s + sn + 1, x[i]) - s,
            y[i] = lower_bound (s + 1, s + sn + 1, y[i]) - s;
        }
        checkset->init (sn);
        for (int i = 1; i <= n; i ++)
        {
            if (z[i])
            {
                checkset->merge (x[i], y[i]);
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i ++)
        {
            if (! z[i])
            {
                if (checkset->find (x[i]) == checkset->find (y[i]))
                {
                    flag = false;
                    break;
                }
            }
        }
        printf (flag ? "YES\n" : "NO\n");
    }
    return 0;
}