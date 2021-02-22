#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <climits>
using namespace std;
const int inf = 100005;

int n, a[inf], suf[inf];
stack <int> s;

void instack (int startp, int endp)
{
    // printf (" [INFO] %d -> %d\n", startp, endp);
    for (int i = startp; i <= endp; i ++)
    {
        s.push (a[i]);
    }
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
    }
    suf[n] = n;
    for (int i = n - 1; i > 0; i --)
    {
        if (a[suf[i + 1]] < a[i])
        {
            suf[i] = suf[i + 1];
        }
        else
        {
            suf[i] = i;
        }
    }
    int p = suf[1];
    instack (1, p);
    while (!s.empty() && p < n)
    {
        while (!s.empty() && s.top() < a[suf[p + 1]])
        {
            printf ("%d ", s.top());
            s.pop();
        }
        instack (p + 1, suf[p + 1]);
        p = suf[p + 1];
    }
    while (!s.empty())
    {
        printf ("%d ", s.top());
        s.pop();
    }
    return 0;
}
