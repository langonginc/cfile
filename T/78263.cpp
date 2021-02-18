#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
short b[1000000005];
int main ()
{
    int n, x;
    short ans = 0;
    cin >> n;
    for (int i = 0; i < n ; i ++)
    {
        cin >> x;
        b[x] ++;
        ans = max(ans, b[x]);
    }
    cout << ans << endl;
    return 0;
}
