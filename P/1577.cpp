#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 1e9+2;
int n, k, cleft, cright, ans, mid, len[100005];

inline bool check (int mid)
{
    ll sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        sum += len[i] / mid;
    }
    return sum >= k;
}

int main ()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    {
        double input;
        cin >> input;
        len[i] = (int)(input * 100);
    }
    cleft = 1, cright = inf;
    while (cleft <= cright)
    {
        mid = (cleft + cright) / 2;
        if (check (mid))
        {
            ans = mid;
            cleft = mid + 1;
        }
        else
        {
            cright = mid - 1;
        }
    }
    printf ("%.2lf\n", (double)(ans/100.0));
    return 0;
}
