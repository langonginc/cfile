#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int main ()
{
    string s;
    cin >> s;
    ll ans = 0, base = 1;
    for (int i = 0; i < s.length () - 2; i ++)
    {
        if (i == 1 || i == 5) continue;
        ans = (ll (s[i] - '0') * base + ans) % 11;
        base ++;
    }
    if (ans == ll (s[s.length () - 1] - '0') || (ans == 10 && s[s.length () - 1] == 'X'))
    {
        cout << "Right" << endl;
    }
    else
    {
        s[s.length () - 1] = (ans == 10 ? 'X' : (ans + '0'));
        cout << s;
    }
    return 0;
}