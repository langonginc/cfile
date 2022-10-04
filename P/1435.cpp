#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1005;

int dp[inf][inf];
string s;

int main ()
{
    cin >> s;
    int len = s.length ();
    for (int k = 1; k < len; k ++)
    {
        for (int i = 1; i <= len - k; i ++)
        {
            int j = i + k;
            if (s[i - 1] == s[j - 1])
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = min (dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    printf ("%d\n", dp[1][len]);
    return 0;
}