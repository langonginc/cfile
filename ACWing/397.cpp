#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
const int mxn = 400005;

class edge
{
public:
  int v, next;
} pool[ 4 * mxn ];

int n, m, q, head[ mxn ], nn, low[ mxn ], pre[ mxn ], bccno[ mxn ], bcc_count;
int bridge[ mxn * 4 ], dep[ mxn ], anc[ mxn ][ 20 ], dfstime;
vector < int > adj[ mxn ];

void add( int u, int v )
{
  pool[ nn ]. v = v;
  pool[ nn ]. next = head[ u ];
  head[ u ] = nn ++;
}

void tarjan(int u, int f )
{
  pre[ u ] = low[ u ] = ++ dfstime;
  for( int i = head[ u ]; i != -1; i = pool[ i ]. next )
  {
    int v = pool[ i ]. v;
    if( pre[ v ] == 0 )
    {
      tarjan( v, u );
      low[ u ] = min( low[ u ], low[ v ] );
      if( low[ v ] > pre[ u ] )
      {
        bridge[ i ] = bridge[ i ^ 1 ] = 1;
      }
    }
    else if( v != f )
    {
      low[ u ] = min( low[ u ], pre[ v ] );
    }
  }
}

void dfs( int u )
{
  bccno[ u ] = bcc_count;
  for( int i = head[ u ]; i != -1; i = pool[ i ]. next )
  {
    if( bridge[ i ] )
    {
      continue;
    }
    int v = pool[ i ]. v;
    if( bccno[ v ] == 0 )
    {
      dfs( v );
    }
  }
}

void lca_dfs( int u, int f )
{
  dep[ u ] = dep[ f ] + 1;
  anc[ u ][ 0 ] = f;
  for( int i = 1; i < 20; i ++ )
  {
    anc[ u ][ i ] = anc[ anc[ u ][ i - 1 ] ][ i - 1 ];
  }
  for( int i = 0; i < adj[ u ]. size(); i ++ )
  {
    int v = adj[ u ][ i ];
    if( v == f )
    {
      continue;
    }
    else
    {
      lca_dfs( v, u );
    }
  }
}

int lca( int x, int y )
{
  if( dep[x] < dep[y] )
  {
    swap(x, y);
  }
  for(int i = 19; i >= 0; i--)
  {
    if( dep[anc[x][i]] >= dep[y] )
    {
      x = anc[x][i];
    }
  }
  if( x == y ) return x;
  for( int i = 19; i >= 0; i-- )
  {
    if(anc[x][i] != anc[y][i])
    {
      x = anc[x][i], y = anc[y][i];
    }
  }
  return anc[x][0];
}

int main()
{
  scanf( "%d%d", &n ,&m );
  memset( head, -1, sizeof( head ) );
  for( int i = 0; i < m; i ++ )
  {
    int u, v;
    scanf( "%d%d", &u, &v );
    add( u, v );
    add( v, u );
  }
  tarjan( 1, 0 );
  for( int i = 1; i <= n; i ++ )
  {
    if( bccno[ i ] == 0 )
    {
      bcc_count++;
      dfs( i );
    }
  }
  for( int u = 1; u <= n; u ++ )
  {
    for( int i = head[ u ]; i != -1; i = pool[ i ]. next )
    {
      if( bridge[ i ] )
      {
        int v = pool[ i ].v;
        if( bccno[ u ] != bccno[ v ] )
        {
          adj[ bccno[ u ] ]. push_back( bccno[ v ] );
        }
      }
    }
  }
  lca_dfs( 1, 0 );
  int q;
  scanf( "%d", &q );
  for( int i = 0; i < q; i ++ )
  {
    int u, v;
    scanf( "%d%d", &u, &v );
    int nu = bccno[ u ];
    int nv = bccno[ v ];
    printf( "%d\n", dep[ nu ] + dep[ nv ] - 2 * dep[ lca( nu, nv ) ] );
  }
  return 0;
}
