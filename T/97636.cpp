#include <iostream>
#include <cstdio>
using namespace std;

int main (){
    int a, b;
    cin >> a >> b;
    if (a > b)
    {
        swap(a,b);
    }
    if (a == b)
    {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 0;
    for (int i = 1; true; i ++)
    {
        a ++, b --;
        ans += 2 * i;
        if (a == b)
        {
            break;
        }
        if (a > b)
        {
            ans -= i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
