#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 105;
int n, a[inf], d[inf][inf], s[inf][inf];

const int test  = 0;

int main ()
{
  scanf ("%d", &n);
  for (int i = 0; i < n; i ++)
  {
    scanf ("%d", &d[0][i]);
    s[0][i] = d[0][i];
  }
  int mxans = 0, mnans = 0;
  for (int i = 1; i < n; i ++)
  {
    int mx = 0,mn = 2147483647, mxdw1 = 0, mxdw2 = 0, mndw1 = 0, mndw2 = 0;
    for (int j = 0; j <= n + 2; j ++)
    {
      int nw = d[i - 1][j % (n - i + 1)] + d[i - 1][(j + 1) % (n - i + 1)];
      int ns = s[i - 1][j % (n - i + 1)] + s[i - 1][(j + 1) % (n - i + 1)];
      if (nw > mx)
      {
        mx = nw;
        mxdw1 = j % (n - i + 1);
        mxdw2 = (j + 1) % (n - i + 1);
      }
      if (ns < mn)
      {
        mn = ns;
        mndw1 = j % (n - i + 1);
        mndw2 = (j + 1) % (n - i + 1);
      }
    }
    if (test)
    {
      for (int j = 0; j <= n - i; j ++)
      {
        printf ("%d ", d[i - 1][j]);
      }
      printf ("\n");
      for (int j = 0; j <= n - i; j ++)
      {
        printf ("%d ", s[i - 1][j]);
      }
    }

    int mxmv = 0, mnmv = 0;
    for (int j = 0; j < n - i; j ++)
    {
      // if (mxmv == 0 && (mxdw1 == j || mxdw2 == j))
      // {
      //   d[i][j] = mx;
      //   mxans += mx;
      //   //j ++;
      //   mxmv = 1;
      //   //continue;
      // }
      // else
      // {
      //   if (mxmv == 0)
      //   {
      //     d[i][j] = d[i - 1][j];
      //   }
      //   else
      //   {
      //     d[i][j] = d[i - 1][j + 1];
      //   }
      // }
      if (mxmv == 0 && mxdw1 == j)
      {
        d[i][j] = mx;
        mxans += mx;
        //j ++;
        mxmv = 1;
        //continue;
      }
      else if (mxmv == 0 && mxdw2 == j)
      {
        d[i][j] = mx;
        mxans += mx;
        mxmv = 2;
      }
      else
      {
        if (mxmv != 1)
        {
          d[i][j] = d[i - 1][j];
        }
        else
        {
          d[i][j] = d[i - 1][j + 1];
        }
      }
      if (mnmv == 0 && mndw1 == j)
      {
        s[i][j] = mn;
        mnans += mn;
        //j ++;
        mnmv = 1;
        //continue;
        // printf ("&");
      }
      else if (mnmv == 0 && mndw2 == j)
      {
        s[i][j] = mn;
        mnans += mn;
        mnmv = 2;
        // printf ("$");
      }
      else
      {
        if (mnmv != 1)
        {
          s[i][j] = s[i - 1][j];
        }
        else
        {
          s[i][j] = s[i - 1][j + 1];
        }
      }
    }
    if (test) printf ("\nmax is %d; mxans is %d; min is %d; mnans is %d\n", mx, mxans, mn, mnans);
  }
  printf ("%d\n%d", mnans, mxans);
}
