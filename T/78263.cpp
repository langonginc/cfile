#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
// #define debug
const int inf = 5000005;

class Box
{
public:
    int b, s;

    bool operator<(const Box &_box) const
    {
        if (s > _box.s)
        {
            return true;
        }
        else if (s < _box.s)
        {
            return false;
        }
        return b < _box.b;
    }
};

Box init(int _b, int _s)
{
    Box _t;
    _t.b = _b, _t.s = _s;
    return _t;
}

int a[inf];
priority_queue <Box> q;
int n, cnt;

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    sort (a + 1, a + n + 1);
    q.push (init (a[1], 1));
    for (int i = 2; i <= n; i ++)
    {
        Box x = q.top();
        #ifdef debug
        printf (" [INFO] IN loop: %d, READ value: %d, READ top FROM q: [value: %d, size: %d]\n", i, a[i], x.b, x.s);
        #endif
        if (a[i] >= x.s)
        {
            #ifdef debug
            printf (" [INFO] MOVED\n");
            #endif
            q.pop();
            q.push(init(a[i], x.s + 1));
        }
        else
        {
            #ifdef debug
            printf (" [INFO] CREATED\n");
            #endif
            q.push(init(a[i], 1));
        }
    }
    printf ("%d", q.size());
    return 0;
}
