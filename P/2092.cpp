#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
using namespace std;
typedef long long ll;

ll list[1000005], Q, q, cnt;

int main () {
    scanf ("%lld", &Q);
    q = Q;
    for (ll i = 2; i * i <= Q; i ++) 
    {
        while (q % i == 0)
        {
            list[++ cnt] = i;
            q /= i;
        }
    }
    if (q != 1) list[++ cnt] = q;
    if (cnt == 1)
    {
        printf ("1\n0\n");
    }
    else if (cnt == 2)
    {
        printf ("2\n");
    }
    else
    {
        printf ("1\n%lld\n", list[1] * list[2]);
    }
    return 0;
}