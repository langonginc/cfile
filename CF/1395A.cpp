#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline bool f (int x)
{
  return x % 2;
}

int main ()
{
  int t, n;
  cin >> t;
  while (t --)
  {
    int r, g, b, w;
    cin >> r >> g >> b >> w;
    int s = f(r) + f(g) + f(b) + f(w);
    if (s <= 1)
    {
      printf ("Yes\n");
      continue;
    }
    if (s == 2)
    {
      printf ("No\n");
      continue;
    }
    if (s == 3)
    {
      if (r > 0 && g > 0 && b > 0)
      {
        printf ("Yes\n");
        continue;
      }
      else
      {
        printf ("No\n");
        continue;
      }
    }
    if (s == 4)
    {
      printf ("Yes\n");
      continue;
    }
  }
}
