#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 5000005;

class Box
{
public:
    int bottom, size;
    void operator()(int b)
    {
        bottom = b;
        size ++;
    }
    bool operator<(const Box &_box) const
    {
        return bottom > _box.bottom;
    }
};

int a[inf];
Box b[inf];
int n, cnt;

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
        b[i].size = 0, b[i].bottom = -1;
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
    {
        int mx = -1, mxid = -1;
        for (int j = 1; j <= cnt; j ++)
        {
            if (b[j].bottom >= mx && b[j].bottom < a[i])
            {
                mx = b[j].bottom;
                mxid = j;
            }
        }
        if (mxid != -1) b[mxid](a[i]);
        else
        {
            b[++ cnt](a[i]);
        }
    }
    printf ("%d", cnt);
    return 0;
}
