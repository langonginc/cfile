#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main ()
{
    ll n, x, count = 0;
    cin >> n >> x;
    for (ll i = 1; i <= n; i ++)
    {
        int num = i;
        while (num != 0)
        {
            ll numd = num % 10;
            num /= 10;
            if (numd == x)
            {
                count ++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
