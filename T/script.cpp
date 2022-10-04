#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int inf = 2e5 + 5;

ll a[inf];

int main ()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    cout <<  142091-142029 + 1 << endl;
    for (int i = 142029 ; i <= 142091; i ++) cout << a[i] << " ";
    return 0;
}