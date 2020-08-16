#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll f[200005];

inline ll pen(ll n)
{
  return ( 3 * n * n - n ) >> 1;
}

int main()
{
  ll n, p;
  scanf("%lld%lld", &n, &p);
  f[0] = 1;
  for(ll i = 1; i <= n; i++)
  {
    for(ll j = 1; true; j++)
    {
      ll a = pen( j ),
         b = pen( -j ),
         flag = -1;
      if( j & 1 )
      {
        flag=1;
      }
      if( a <= i )
      {
        f[i] = ( f[i] + flag * f[i-a] + p ) % p;
      }
      if( b <= i )
      {
        f[i] = ( f[i] + flag * f[i-b] + p ) % p;
      }
      if( a>i || b>i )
      {
        break;
      }
    }
  }
  printf("%lld", f[n]);
  return 0;
}
