/*
* TLE
* 这是一个正确的版本但被卡常数所以 TLE
* TLE
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int inf = 55;
int n, t;
int dp[5000005];
vector <int> v;
vector <int> w;

int main ()
{
    v.push_back(0);
    w.push_back(0);
    scanf ("%d%d", &n, &t);
    for (int i = 1; i <= n; i ++)
    {
        int a, b, c, d, g;
        scanf ("%d%d%d%d", &a, &b, &c, &d);
        g = c / d;
        if (c % d != 0)
        {
            g ++;
        }
        for (int j = 1; j < g; j ++)
        {
            w.push_back(a);
            v.push_back(b * d);
        }
        w.push_back(a);
        v.push_back(b * ((c % d) == 0?d:(c % d)));
    }
    int nn = v.size();
    for (int i = 1; i <= nn; i ++)
    {
        for (int j = t; j >= w[i]; j --)
        {
            dp[j] = max (dp[j], dp[j - w[i]] + v[i]);
        }
    }
    printf ("%d\n", dp[t]);
    return 0;
}