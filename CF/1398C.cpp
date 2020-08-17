#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;
const int inf = 1e5 + 5;
/*
int t, n, sum[inf], ans;

//#define deb

int main ()
{
  ios::sync_with_stdio(false);cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t --)
  {
    memset (sum, 0, sizeof (sum));
    ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i ++)
    {
      int x = s[i - 1] - '0';
      sum[i] = sum[i - 1] + x;
      for (int j = 1; j <= i; j ++)
      {
        int c = i - j + 1;
        int s = sum[i] - sum[j - 1];
        if (c == s)
        {
          ans ++;
          #ifdef deb
          printf ("left=%d right=%d is avaliable.\n", j, i);
          #endif
        }
        else
        {
          #ifdef deb
          printf ("left=%d right=%d sum=%d pro=%d is not avaliable.\n", j, i, s, c);
          #endif
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
*/
