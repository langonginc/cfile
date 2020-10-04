#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const int inf = 40005;

int prime[inf], ping[inf], ans[inf];

/*int qpow(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a;
    else
    {
        int temp = qpow(a, n / 2);
        return temp * temp;
    }
}*/

void getp()
{
    for (int i = 2; i <= 40000; ++i) prime[i] = 1;
    for (int i = 2; i * i <= 40000; ++i) {
        if (prime[i] == 1)
        {
            for (int j = i*i; j <= 40000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

int _main()
{
    getp();
    int n;
    for (int p = 2; p < inf-5; p++)
    {
        //long long p1 = p;
        if (prime[p] == 0)
            continue;
        for (int p1 = p; p1 <= inf; p1 *= p)
        {
            if (p1 >= inf) break;
            ping[p1] = 1;
        }
    }
    for (int i = 1; i < inf; i++)
    {
        ans[i] = ans[i - 1] + ping[i];
    }
    while (cin >> n)
    {
        /*for (int i = 1; i <= n; i++)
            if (ping[i])
                cout << i << " ";*/
        int s = 0;
        //for (int i = 1; i <= n; i++) s += ping[i];
        cout << ans[n] << endl;
    }
    return 0;
}
