#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int mxn = 500005;

int n, m, k, a, v, t, b[mxn], mk;

int main ()
{
  cin >> n >> m;
  b [0] = 1;
  for (int i = 0; i < n; i ++)
  {
    cin >> k >> a;
    for (mk = 1; mk < a; mk *= 2)
    {
      v = k * mk;
      if (v > mxn)
      {
        break;
      }
      else
      {
        for (int j = mxn - 1; j >= v; j --)
        {
          if (b [j - v])
          {
            b [j] = 1;
          }
        }
        a -= mk;
      }
    }
  }
  for (int i = 0; i < m; i ++)
  {
    cin >> t;
    if (b [t])
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
  return 0;
}
