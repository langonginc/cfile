#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#define min( x, y ) ((x)<(y)?(x):(y))
using namespace std;
const int Mxn = 200010;
class edge
{
public:
  int to, next;
};

int head[Mxn], Nn = 0, n, m, pre[ Mxn ], low[ Mxn ], dfstime, cut[ Mxn ];
edge pool[Mxn];

inline void add( int u, int v )
{
  pool[ ++ Nn ].to = v,
  pool[ Nn ].next = head[u],
  head[ u ] = Nn;
}

void tarjan( int u, int f )
{
  pre[ u ] = low[ u ] = ++ dfstime;
  int ch = 0;
  for( int i = head[ u ]; i ; i = pool[ i ].next )
  {
    int v = pool[ i ].to;
    if( pre[ v ] == 0 )
    {
      ch ++;
      tarjan( v, u );
      low[ u ] = min( low[ u ], low[ v ] );
      if(low[ v ] >= pre[ u ] )
      {
        cut[u] = true;
      }
    }
    else if( pre[ v ] < pre[ u ] && v != f )
    {
      low[ u ] = min( low[ u ], pre[ v ] );
    }
  }
  if( f == 0 && ch == 1)
  {
    cut[ u ] = false;
  }
}

int main()
{
  scanf( "%d%d", &n, &m );
  for( int i = 0; i < m; i ++ )
  {
    int x,y;
    scanf( "%d%d", &x, &y );
    add( x, y );
    add( y, x );
  }

  for( int i = 1; i <= n; i ++ )
  {
    if( pre[ i ] == 0 )
    {
      tarjan( i, 0 );
    }
  }

  int ans = 0;
  vector<int> vec;
  for( int i = 0; i <= n; i ++ )
  {
    if( cut[ i ] == true )
    {
      ans++;
      vec.push_back( i );
    }
  }
  printf( "%d\n", ans );
  for( int i = 0; i < vec.size(); i ++ )
  {
    printf( "%d ", vec[ i ] );
  }
  return 0;
}
