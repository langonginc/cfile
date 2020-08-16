#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
const int inf = 205;

ll n, m, a[inf], b[inf], c[inf];

int main ()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i ++)
  {
    cin >> a[i];
    c[i] = LLONG_MAX;
  }
  for (int i = 1; i <= m; i ++)
  {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i ++)
  {
    for (int j = 1; j <= m; j ++)
    {
      c[i] = min (c[i], a[i] & b[i]);
    }
  }
  ll ans = c[1];
  for (int i = 2; i <= n; i ++)
  {
    ans |= c[i];
  }
  cout << ans;
  return 0;
}
