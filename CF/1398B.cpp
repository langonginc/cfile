#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 505;
int t, a[inf], p;
string s;

int main ()
{
  cin >> t;
  while (t --)
  {
    memset (a, 0, sizeof(a));
    p = 0;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i ++)
    {
      if (s[i] == '1')
      {
        int j = i;
        while (j + 1 < len && s[j + 1] == '1')
        {
          j ++;
        }
        a[++ p] = j - i + 1;
        i = j;
      }
    }
    sort (a + 1, a + p + 1);
    int ans = 0;
    for (int i = p; i > 0; i -= 2)
    {
      ans += a[i];
    }
    cout << ans << endl;
  }
  return 0;
}
