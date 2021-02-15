#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 10005;

#ifndef Pro_Class
#define Pro_Class
class Pro
{
public:
    ll _p, _t;

    ll &p();
    ll &t();
    bool operator<(Pro &_class) const
    {
        return _p > _class._p;
    }
};

ll &Pro::p()
{
    return _p;
}
ll &Pro::t()
{
    return _t;
}
#endif

ll n, k, cnt[inf], num = 1, f[inf];
Pro a[inf];

int main ()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i ++)
    {
        cin >> a[i].p() >> a[i].t();
        cnt[a[i].p()] ++;
    }
    sort (a + 1, a + k + 1);
    for (int i = n; i > 0; i --)
    {
        if (cnt[i] == 0)
        {
            f[i] = f[i + 1] + 1;
        }
        else
        {
            for (int j = 1; j <= cnt[i]; j ++)
            {
                if (f[i + a[num].t()] > f[i])
                {
                    f[i] = f[i + a[num].t()];
                }
                num ++;
            }
        }
    }
    cout << f[1] << endl;
    return 0;
}
