#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int inf = 10005;
const int cost[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, m, a[inf], visit[inf];
string dp[inf];

inline bool small (string a, string b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();
}

inline string its (int x)
{
    string tempstr;
    tempstr += (char)(x + '0');
    return tempstr;
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i ++)
    {
        scanf ("%d", &a[i]);
    }
    visit[0] = 1;
    sort (a, a + m);
    reverse (a, a + m);
    for (int i = 0; i < m; i ++)
    {
        int val = cost[a[i]];
        for (int j = val; j <= n; j ++)
        {
            if (visit[j - val] && small(dp[j], dp[j - val] + its(a[i])))
            {
                dp[j] = dp[j - val] + its(a[i]);
            }
            visit[j] = true;
        }
    }
    // printf ("%s\n", dp[n]);
    cout << dp[n] << endl;
    return 0;
}