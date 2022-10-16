#include <iostream>
#include <ctime>
#include <cstdio>
#include <climits>
#include <cstdlib>
using namespace std;
typedef long long ll;
const ll inf = 444444444444;
const ll tinf = 1e5 - 1;

char name1[100] = {"./test/1.in"};
char name2[100] = {"x.out"};

int t, l, r;

int main ()
{
    srand(time(NULL));
//    for (int i = 0; i < 10; i ++)
    {
//        name1[0] = i + '0';
        freopen (name1, "a+", stdout);
        ll t, l ,r;
        t = rand () % tinf + 1;
        printf ("%lld\n", t);
        for (int j = 1; j <= t; j ++)
        {
            l = 1ll * rand () * 7777777ll % (inf / 5ll);
            r = 1ll * rand () * 7777777ll % (inf / 5ll) + (inf / 5ll * 2ll) % inf;
            if (l > r)
            {
                std::cerr << "L > R!" << endl;
            }
            if (l < 0 || r < 0)
            {
                std::cerr << "Under 0!" <<endl;
            }
            if (l > inf || r > inf)
            {
                std::cerr << "Out of Max!" << endl;
            }
            printf ("%lld %lld\n", l, r);
        }
    }
}