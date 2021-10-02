#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
class Node
{
    public:
    int cost, value;
    bool operator < (const Node& other) const
    {
        return cost < other.cost;
    }
    void operator () (int _cost, int _value)
    {
        cost = _cost;
        value = _value;
    }
} a[2000005];
int n, m, ans;
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int _a, _b;
        scanf ("%d%d", &_a, &_b);
        a[i](_a, _b);
    }
    sort (a + 1, a + m + 1);
    for (int i = 1; i <= m; i ++)
    {
        if (n <= 0) break;
        if (a[i].value <= n)
        {
            ans += a[i].cost * a[i].value;
            n -= a[i].value;
        }
        else
        {
            ans += a[i].cost * n;
            break;
        }
    }
    printf ("%d", ans);
    return 0;
}