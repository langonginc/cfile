#include <iostream>
#include <cstdio>
using namespace std;
double minv = 10000001, na, nb, a, b, normal, t, n;

int main ()
{
    cin >> a >> b >> n;
    normal = (a * 1.0) / (b * 1.0);
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            t = (i * 1.0) / (j * 1.0);
            if (t >= normal && t - normal < minv)
            {
                minv = t - normal;
                na = i, nb = j;
            }
        }
    }
    cout << na << " " << nb << endl;
    return 0;
}