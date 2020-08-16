#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 100005;

int n, m, f[inf], a[inf];

struct Road
{
  int x, y, z; 
  bool operator < (const Road &oth) const
  {
    return z > oth.z;
  }
} s[inf];

inline int find (int x)
{
  if (f[x] == x)
    return x;
  else
    return f[x] = find(f[x]);
}

int main ()
{
  scanf ("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++)
  {
    scanf ("%d", &a[i]);
  }
  for (int i = 1; i <= m; i ++)
  {
    scanf ("%d%d%d", &s[i].x, &s[i].y, &s[i].z);
  }
  int ans = -1, cnt = 0;
  for (int i = 0; i <= n; i ++)
  {
    f[i] = i;
  }
  sort(s + 1, s + m + 1);
  for (int i = 1; i <= m; i ++)
  {
    while (true)
    {
      //printf ("I'm here...\n");
      if (find (cnt) == find (a[cnt]))
      {
        cnt ++;
        if (cnt >= n)
        {
          printf ("%d\n", ans);
          return 0;
        }
      }
      else
      {
        break;
      }
      
    }
    int nx = find (s[i].x);
    int ny = find (s[i].y);
    if (nx != ny)
    {
      f[nx] = ny;
      ans = s[i].z;
    }
  }
  printf ("%d", ans);
  return 0;
}

