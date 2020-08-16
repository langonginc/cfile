#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 10000005 + 5;
bool cmp( ll a, ll b )
{
  return a > b;
}
ll n, l, v, a[ inf ], sum[ inf ], q, t;

int main()
{
  scanf( "%lld%lld%lld", &n, &l, &v );
  for( int i = 1; i <= n; i ++ )
  {
    scanf( "%lld", &a[ i ] );
  }
  sort( a + 1, a + n + 1, cmp );
  for( int i = 1; i <= n; i ++ )
  {
    sum[ i ] = sum[ i - 1 ] + a[ i ];
  }
  scanf( "%lld", &q );
  for( int i = 1; i <= q; i ++ )
  {
    scanf( "%lld", &t );
    ll left = 0, right = n, mid = 0, ans = 2147483647;
    while( left <= right )
    {
      mid = ( left + right ) >> 1;
      if( sum[ mid ] + l > t * v )
      {
        ans = mid;
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    printf( "%lld\n", ans == 2147483647 ? -1 : ans );
  }
  return 0;
}
