#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
const int mox = 10000;
stack <ll> s;

int main ()
{
    ll a, b, sum;
    char op;
    cin >> a;
    a %= mox;
    s.push(a);
    while (cin >> op >> b)
    {
        if (op == '*')
        {
            ll num = s.top();
            s.pop();
            ll dx = (num*b) % mox;
            s.push(dx);
        }
        else
        {
            s.push(b);
        }
    }
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
        sum %= mox;
    }
    cout << sum << endl;
    return 0;
}
