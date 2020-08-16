#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int count;

inline void out (int n, int a, int b)
{
  printf ("move %d from %d to %d\n", n, a, b);
  count ++;
}

void hannoi (int n, int a, int b, int c)
{
  if (n == 1)
  {
    out (1, a, c);
  }
  else
  {
    hannoi (n - 1, a, c, b);
    out (n, a, c);
    hannoi (n - 1, b, a, c);
  }
}

int main ()
{
  int n;
  scanf ("%d", &n);
  hannoi (n, 1, 2, 3);
  printf ("%d\n", count);
  return 0;
}
