#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 5005;
class Node 
{
    public:
    int high, value;
    void operator () (int _high, int _value)
    {
        high = _high;
        value = _value;
    }
};
bool cmp1 (Node & a, Node & b)
{
    return a.high < b.high;
}
bool cmp2 (Node & a, Node & b)
{
    return a.value < b.value;
}
Node a[inf];
int n, s, x;
int main ()
{
    int _a, _b;
    scanf ("%d%d", &n, &s);
    scanf ("%d%d", &_a, &_b);
    x = _a + _b;
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d%d", &_a, &_b);
        a[i](_a, _b);
    }
    int pos = 0;
    sort (a + 1, a + n + 1, cmp1);
    for (int i = 1; i <= n; i ++)
    {
        if (a[i].high <= x)
        {
            pos = i;
        }
        else break;
    }
    sort (a + 1, a + pos + 1, cmp2);
    int ans = 0;
    for (int i = 1; i <= pos; i ++)
    {
        if (a[i].value <= s)
        {
            s -= a[i].value;
            ans ++;
        }
        else break;
    }
    printf ("%d\n", ans);
    return 0;
}