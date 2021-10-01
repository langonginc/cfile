#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Array
{
    int a, id;
    bool operator < (const Array &x) const
    {
        return a < x.a;
    }
};
int main ()
{
    int n;
    Array a[1005];
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i].a;
        a[i].id = i;
    }
    sort (a + 1, a + n + 1);
    double ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (i != n) ans += a[i].a * (n - i);
        cout << a[i].id << " ";
    }
    ans /= double (n * 1.00);
    printf ("\n%.2lf\n", ans);
    return 0;
}