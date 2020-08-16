#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1e6+1;
int n, k, a [inf], sum [inf], ans;

int main ()
{
  scanf ("%d%d", &n, &k);
  for (int i = 1; i <= n; i ++)
  {
    scanf ("%d", &a [i]);
    sum [i] = sum [i - 1] + a [i];
  }

  for (int i = 1; i <= n - k; i ++)
  {
    ans = max (ans, sum [i + k] - sum [i - 1]);
  }
  printf ("%d", ans);
  return 0;
}
