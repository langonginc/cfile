#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
#define min( a, b ) ( (a) < (b) ? (a) : (b) )
#define max( a, b ) ( (a) > (b) ? (a) : (b) )
#define Inf 2147483647
using namespace std;
typedef long long ll;
const ll Mxn = 5000005;
class edge
{
public:
  ll to, next;
};

ll head[ Mxn ], Nn = 0, n, m, pre[ Mxn ], low[ Mxn ], dfstime, cut[ Mxn ];
ll ans[ Mxn ];
edge pool[Mxn];

inline void add( ll u, ll v )
{
  pool[ ++ Nn ].to = v,
  pool[ Nn ].next = head[u],
  head[ u ] = Nn;
}

ll tarjan( ll u, ll f )
{
  ll node = 1, t = 0, v, ch;
  low[ u ] = pre[ u ] = ++ dfstime;
  ans[ u ] = 2 * ( n - 1 );
  for( ll i = head[ u ]; i != 0; i = pool[ i ].next )
  {
    v = pool[ i ].to;
    if( pre[ v ] == 0 )
    {
      ch = tarjan( v, u );
      node += ch;
      low[ u ] = min( low[ u ], low[ v ] );
      if( low[ v ] >= pre[ u ] )
      {
        ans[ u ] += 2 * t * ch;
        t += ch;
      }
    }
    else if( pre[ v ] < pre[ u ] && v != f )
    {
      low[ u ] = min( low[ u ], pre[ v ] );
    }
  }
  ans[ u ] += 2 * t * ( n - t - 1 );
  return node;
}

int main()
{
  scanf( "%lld%lld", &n, &m );
  for( ll i = 0; i < m; i ++ )
  {
    ll x, y;
    scanf( "%lld%lld", &x, &y );
    add( x, y );
    add( y ,x );
  }

  for( ll i = 1; i <= n; i ++ )
  {
    if( pre[ i ] == 0 )
    {
      tarjan( i, 0 );
    }
  }

  for( ll i = 1; i <= n; i ++ )
  {
    printf( "%lld\n", ans[ i ] );
  }
  return 0;
}
