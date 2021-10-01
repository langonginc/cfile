#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 1e6 + 5;
struct Contest
{
    int left, right;
    int &l () {return left;}
    int &r () {return right;}
    bool operator < (const Contest &cmp) const
    {
        return right < cmp.right;
    }
} a[inf];

int n, vis[inf], ans;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i].l() >> a[i].r();
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
    {
        if (!vis[i])
        {
            ans ++;
            vis[i] = true;
            for (int j = i + 1; j <= n; j ++)
            {
                if (a[i].r() > a[j].l())
                {
                    vis[j] = true;
                }
            }
        }
    }
    cout << ans;
    return 0;
}