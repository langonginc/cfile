#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;
const ll mxn = 500005;
const char noway[] = "No solution";

int n, m, start, tree_count, target, pre[ mxn ], low[ mxn ], dfstime;
vector < int > adj[ mxn ], adj_tree[ mxn ];
stack < int > s;

void tarjan( int u, int f )
{
  pre[ u ] = low[ u ] = ++ dfstime;
  s. push( u );
  for( int i = 0; i < adj[ u ]. size(); i ++ )
  {
    int v = adj[ u ][ i ];
    if( pre[ v ] == 0 )
    {
      tarjan( v, u );
      low[ u ] = min( low[ u ], low[ v ] );
      if( low[ v ] >= pre[ u ] )
      {
        tree_count ++;
        while( true )
        {
          int x = s. top();
          s. pop();
          adj_tree[ tree_count ]. push_back( x );
          adj_tree[ x ]. push_back( tree_count );
          if( x == v )
          {
            break;
          }
        }
        adj_tree[ u ]. push_back( tree_count );
        adj_tree[ tree_count ]. push_back( u );
      }
    }
    else if( v != f )
    {
      low[ u ] = min( low[ u ], pre[ v ] );
    }
  }
}

void dfs( int u, int f, int ans )
{
  if( u == target )
  {
    if( ans == 0 )
    {
      printf( "%s\n", noway );
    }
    else
    {
      printf( "%d\n", ans );
    }
    exit( 0 );
  }
  else
  {
    if( u != start && adj_tree[ u ]. size() > 1 && u <= n )
    {
      if( ans == 0 )
      {
        ans = u;
      }
      else
      {
        ans = min( ans, u );
      }
    }
    for( int i = 0; i < adj_tree[ u ]. size(); i ++ )
    {
      int x = adj_tree[ u ][ i ];
      if( x == f )
      {
        continue;
      }
      else
      {
        dfs( x, u, ans );
      }
    }
  }
  return;
}

int main( int argc, char* argv[] )
{
  scanf( "%d", &n );
  while( true ){
    int x, y;
    scanf( "%d%d", &x, &y );
    if( x == 0 && y == 0 )
    {
      break;
    }
    else
    {
      adj[ x ]. push_back( y );
      adj[ y ]. push_back( x );
      m ++;
    }
  }
  scanf( "%d%d", &start, &target );
  tree_count = n;
  tarjan( start, 0 );
  if( pre[ target ] == 0 )
  {
    printf( "%s\n", noway );
  }
  else{
    dfs( start, 0, 0 );
  }
  ; return 0;
}
