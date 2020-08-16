// Codeforces 1399A

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

inline int absd (int x)
{
  return x > 0 ? x : -x;
}

vector <int> a;

int main ()
{
  int t, n;
  scanf ("%d", &t);
  while (t --)
  {
    a.clear();
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
      int x;
      scanf ("%d", &x);
      a.push_back(x);
    }
    int f = 0;
    sort (a.begin(), a.end());
    for (int i = 1; i < a.size(); i ++)
    {
      if (a[i] - a[i - 1] > 1)
      {
        f = 1;
        break;
      }
    }
    printf (f ? "NO\n" : "YES\n");
  }
  return 0;
}
