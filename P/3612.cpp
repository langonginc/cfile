#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

string str;
ll x;

ll fastPow(ll x, ll y)
{
    ll r = 1, base = x;
    while (y)
    {
        if (y & 1) r *= base;
        base *= base, y >>= 1;
    }
    return r;
}

ll dfs (ll id, ll len, ll p)
{
    if (id <= 0)
    {
        return p;
    }
    else if (p < (len >> 1))
    {
        return dfs (id - 1, (len >> 1), p);
    }
    else
    {
        return dfs (id - 1, (len >> 1), (p + (len >> 1) - 1) % (len >> 1));
    }
}

int main ()
{
    cin >> str >> x;
    ll len = str.length ();
    ll k = 1, i = len;
    while (i < x)
    {
        i <<= 1, k ++;
    }
    cout << str[dfs (k, len * fastPow (2, k), x - 1)];
    return 0;
}