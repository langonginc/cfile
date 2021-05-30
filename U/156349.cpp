#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int inf = 200005;

ll n, a[inf], pre[inf];

int main ()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf ("%d", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n)
}