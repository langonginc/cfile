#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;
const int inf = 5e4 + 1;

ll t, n, a[inf];

int main ()
{
  cin >> t;
  while (t --)
  {
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
      cin >> a[i];
    }
    if (a[1] + a[2] <= a[n])
    {
      cout << "1 2 " << n << endl;
    }
    else
    {
      cout << "-1" << endl;
    }
  }
  return 0;
}
