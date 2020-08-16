#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mxn = 1000005;
int l, m, s, t, f[mxn], a[105], k;
int sim = 0;


const int test = 0;

int main ()
{
  cin >> l >> s >> t >> m;
  for (int i = 0; i < m; i ++)
  {
    cin >> a[i];
    if (s == t)
    {
      if (a[i] % s == 0){
        sim ++;
      }
    }
  }
  if (s == t){
    cout << sim <<endl;
    return 0;
  }
  sort (a, a + m);
  int g = s * t;
  k = a[0];
  f[k]=1;
  for (int i = 1; i < m; i ++)
  {
    int d = a[i] - a[i - 1];
    if (d >= g)
    {
      k += g;
    }
    else{
      k += d;
    }
    f[k] = 1;
  }
  int nl = k + g;
  //printf ("%d\n", k);
  for (int i = 0; i <= nl + t; i ++)
  {
    int mx = 0;
    for (int j = i - t; j <= i - s; j ++)
    {
      if (j < 0)
        continue;
      mx = max (mx, f[j] + f[i]);
    }
    if (test) printf ("i: %d; max: %d; Orign: %d\n",i, mx,f[i]);
    f[i] = mx;
  }
  //cout << f[l];
  int mx = 0;
  for (int i = nl; i <= nl + t; i ++)
    mx = max (mx, f[i]);
  cout << mx;
  return 0;
}
