#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int N;

inline int getbit (int x)
{
    int cnt = 1;
    while (x /= 10)
    {
        cnt ++;
    }
    return cnt;
}

int dfs (int n, int last, int bit)
{
    printf ("%d, %d, %d\n", n, last, bit);
    int k = 1, p = 1, ans = 1;
    for (int i = 1; i <= N && i <= last / 2; i ++)
    {
        if (i >= p * 10)
        {
            p *= 10, k ++;
        }
        ans += dfs (i * p * 10 + n, i, k + bit);
    }
    return ans;
}

int main ()
{
    scanf ("%d", &N);
    printf ("%d\n", dfs (N, INT_MAX, getbit (N)));
    return 0;
}