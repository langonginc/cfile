#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main ()
{
    long long n, x1, x2, x3;
    cin >> n;
    x1 = 1, x2 = 1;
    if (n <= 0)
    {
        cout << 0;
        return 0;
    }
    if (n == 1)
    {
        cout << x1;
        return 0;
    }
    if (n == 2)
    {
        cout << x2;
        return 0;
    }
    for (int i = 3; i <= n; i ++)
    {
        x3 = x1 + x2;
        x1 = x2;
        x2 = x3;
    }
    cout << x3;
    return 0;
}
