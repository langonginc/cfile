#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int mxn = 2005;
class People
{
public:
  int u, deep;
  bool operator< ( const People &a )const
  {
    return deep > a.deep;
  }
  /*void operator() ( int _u, int _deep )
  {
    u = _u, deep = _deep;
  }*/
} hero[ mxn ];

class edge{
public:
  int to, next;
} pool[ mxn ];

int n, s, k, head[ mxn ], Nn, dep[ mxn ], lg[ mxn ][ 15 ];
int spr[ mxn ], hero_count, spr_count;

void add( int u, int v )
{
  pool[ ++ Nn ].to = v,
  pool[ Nn ].next = head[ u ],
  head[ u ] = Nn;
}

void chdfs( int u, int f )
{
  int ch = 0;
  dep[ u ] = dep[ f ] + 1,
  lg[ u ][ 0 ] = f;
  for( int i = 1; i < 13; i ++ )
  {
    lg[ u ][ i ] = lg[ lg[ u ][ i - 1 ] ][ i - 1 ];
  }
  for( int i = head[ u ]; i; i = pool[ i ].next )
  {
    int v = pool[ i ].to;
    if( v != f )
    {
      ch ++;
      chdfs( v, u );
    }
  }
  if( ch == 0 )
  {
    hero[ hero_count ].u=u;
	  hero[ hero_count++ ].deep=dep[u];
  }
}

int lca( int x, int y )
{
  if( dep[ x ] < dep[ y ] )
  {
    swap( x, y );
  }
  for( int i = 12; i >= 0; i -- )
  {
    if( dep[ lg[ x ][ i ] ] >= dep[ y ] ){
      x = lg[ x ][ i ];
    }
  }
  if( x == y )
  {
    return x;
  }
  for( int i = 12; i >= 0; i -- )
  {
    if( lg[ x ][ i ] != lg[ y ][ i ] )
    {
      x = lg[ x ][ i ],
      y = lg[ y ][ i ];
    }
  }
  return lg[ x ][ 0 ];
}

int find( int x )
{
  int t = k;
  for( int i = 0;  i < 12 && t; i ++ )
  {
    if(t & 1){
			x = lg[ x ][ i ];
  	}
  	t >>= 1;
  }
  return x;
}
int dis(int x, int y){
	int l = lca(x, y);
	return dep[x] + dep[y] - 2 * dep[l];
}
int main( int argc, char* argv[] )
{
  int cs;
  scanf( "%d", &cs );
  while( cs -- )
  {
    scanf( "%d%d%d", &n, &s, &k );
    Nn = hero_count = 0;
    memset( head, 0, sizeof( head ) ),
    memset( lg, 0, sizeof( lg ) ),
    memset( dep, 0, sizeof( dep ) );
    for( int i = 0; i < n-1; i ++ )
    {
      int x, y ;
      scanf( "%d%d", &x, &y );
      add( x, y );
      add( y, x );
    }
    chdfs( s, 0 );
    sort( hero, hero + hero_count );
    spr[ 0 ] = s,
    spr_count = 1;
    for( int i = 0; i < hero_count; i ++ )
    {
      bool save = 0;
      for( int j = 0; j < spr_count; j ++ )
      {
		    if (dis(hero[i].u, spr[j]) <= k){
          save = 1;
          break;
        }
      }
      if( ! save )
      {
        spr[ spr_count ++ ] = find( hero[ i ].u );
      }
    }
    printf( "%d\n", ( spr_count - 1 ) );
  }
  return 0;
}
