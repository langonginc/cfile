#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
const int mxn = 5005;
class edge{
public:
  int v, next;
  // void operator () ( int _v, int _next)
  // {
  //   v = _v,
  //   next = _next;
  // }
} pool[ mxn ];
int n, nn, m, head[ mxn ], pre[ mxn ], low[ mxn ], dfstime, bcc_count;
int cut[ mxn ];
stack <int> s;
vector <int> bcc[ mxn ];

inline void add( int u, int v )
{
  pool[ ++ nn ].v = v;
  pool[ ++ nn ].next = head[ u ];
  head[ u ] = nn;
}

void tarjan( int u, int f )
{
  low[ u ] = pre[ u ] = ++ dfstime;
  s.push( u );
  int ch = 0;
  for( int i = head[ u ]; i; i = pool[i].next )
  {
    int v = pool[ i ].v;
    if( pre[ v ] == 0 )
    {
      ch ++;
      tarjan( v, u );
      low[ u ] = min( low[ u ], low[ v ] );
      if( low[ v ] >= pre[ u ] )
      {
        cut[ u ] = 1;
        bcc[ ++ bcc_count ].clear();
        while( true )
        {
          int now = s.top();
          s.pop();
          bcc[ bcc_count ].push_back( now );
          if( now == v )
          {
            break;
          }
        }
        bcc[ bcc_count ].push_back( u );
      }
      else if( v != f )
      {
        low[ u ] = min( low[ u ], pre[ v ] );
      }
    }
  }
  if( f == 0 && ch == 1 )
  {
    cut[ u ] = 0;
  }
}

int main( int argc, char* argv[] )
{
  int cs = 0;
  while( ++ cs )
  {
    scanf( "%d", &m );
    if( m == 0 )
    {
      break;
    }
    printf( "Case %d: ", cs );
    nn = dfstime = bcc_count = n = 0;
    memset( head, 0, sizeof( head ) );
    memset( pre, 0, sizeof( pre ) );
    memset( low, 0, sizeof( low ) );
    memset( cut, 0, sizeof( cut ) );
    for( int i = 1; i <= m; i ++ )
    {
      int s, t;
      scanf( "%d%d", &s, &t );
      add( s, t );
      add( t, s );
      n = max( n, max( s, t ) );
    }
    int res = 0;
    ll num = 1;
    for( int i = 1; i <= n; i ++ )
    {
      if( pre[ i ] == 0 )
      {
        tarjan( i, 0 );
      }
    }
    for( int i = 1; i <= bcc_count; i ++ )
    {
      int count = 0;
      int len = bcc[ i ].size();
      for( int j = 0; j < len; j ++ )
      {
        if( cut[ bcc[ i ][ j ] ] )
        {
          count ++;
        }
      }
      if( count == 0 )
      {
        res += 2,
        num *= len * ( len - 1 ) >> 1;
      }
      else if( count == 1 ){
        res += 1,
        num *= ( len - 1 );
      }
    }
    printf( "%d %lld\n", res, num );
  }
  return 0;
}
