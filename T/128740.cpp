#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int mxn = 15;
const int inf = 2147483647;
const int dx[ 4 ] = { 0, 0, 1, -1 };
const int dy[ 4 ] = { 1, -1, 0, 0 };
int n, m, k, now, ans;
int filed[ mxn ][ mxn ];
int count[ mxn ][ mxn ];

bool watch( int x, int y )
{
  for( int i = 0; i < 4; i ++ )
  {
    for( int  j = 0; j < 10; j ++ )
    {
      int nx = x + j * dx[ i ];
      int ny = y + j * dy[ i ];
      if( ( nx > 0 ) && ( nx <= n ) && ( ny > 0 ) && ( ny <= n ) )
      {
        if( filed[ nx ][ ny ] == 1 )
        {
          break;
        }
        else if( filed[ nx ][ ny ] == 2 )
        {
          return false;
        }
      }
    }
  }
  return true;
}

bool finish()
{
  for( int i = 1; i <= n; i ++ )
  {
    for( int j = 1; j <= m; j ++ )
    {
      if( filed[ i ][ j ] == 0 )
      {
        if( watch( i, j ) == true )
        {
          return false;
        }
      }
      else if( ( filed[ i ][ j ] == 1 ) && ( count[ i ][ j ] != -1) )
      {
        int t = 0;
        for( int k = 0; k < 4; k ++ )
        {
          int nx = i + dx[ k ];
          int ny = j + dy[ k ];
          if( filed[ nx ][ ny ] == 2 )
          {
            t ++;
          }
        }
        if( t != count[ i ][ j ] )
        {
          return false;
        }
      }
    }
  }
  return true;
}

bool valid( int x, int y )
{
  if( filed[ x ][ y ] == 1 && count[ x ][ y ] != -1)
  {
    int t = 0;
    for( int i = 0; i < 4; i ++ )
    {
      int nx = x + dx[ i ];
      int ny = y + dy[ i ];
      if( filed[ nx ][ ny ] == 2 )
      {
        t ++;
      }
    }
    return ( t < count[ x ][ y ] );
  }
  return true;
}

bool ifput( int x, int y )
{
  for( int i = 0; i < 4; i ++ )
  {
    int nx = x + dx[ i ];
    int ny = y + dy[ i ];
    if( ! valid( nx, ny ) )
    {
      return false;
    }
  }
  for( int i = 0; i < 4; i ++ )
  {
    for( int j = 1; j < 10; j ++ )
    {
      int nx = x + ( j * dx[ i ] );
      int ny = y + ( j * dy[ i ] );
      if( ( nx > 0 ) && ( nx <= n ) && ( ny > 0 ) && ( ny <= n ) )
      {
        if( filed[ nx ][ ny ] == 1 )
        {
          break;
        }
        else if( filed[ nx ][ ny ] == 2 )
        {
          return false;
        }
      }
    }
  }
  return true;
}

void dfs( int x, int y )
{
  if( now > ans )
  {
    return;
  }
  else if( x > n )
  {
    if( finish() == true )
    {
      ans = min( ans, now );
    }
  }
  else if( y > m )
  {
    dfs( x + 1, 1 );
  }
  else if( filed[ x ][ y ] != 0 )
  {
    if( ( x > 1 ) && ( filed[ x - 1 ][ y ] == 0 ) && watch( x - 1, y ) )
    {
      return;
    }
    dfs( x, y + 1 );
  }
  else
  {
    if( ifput( x, y ) )
    {
      filed[ x ][ y ] = 2, now ++;
      dfs( x, y + 1 );
      filed[ x ][ y ] = 0, now --;
    }
    dfs( x, y + 1 );
  }
}

int main( int argc, char* argv[] )
{
  while(1)
  {
    scanf( "%d%d", &n, &m );
    if( ( n == 0 ) && ( m == 0) )
    {
      break;
    }
    scanf( "%d", &k );
    memset( filed, 0, sizeof( filed ) );
    memset( count, 0, sizeof( count ) );
    ans = inf;
    for( int i = 1; i <= k; i ++ )
    {
      int a, b, x;
      scanf( "%d%d%d", &a, &b, &x );
      filed[ a ][ b ] = 1,
      count[ a ][ b ] = x;
    }
    dfs( 1, 1 );
    if( ans == inf )
    {
      printf( "No solution\n" );
    }
    else
    {
      printf( "ans:%d\n", ans );
    }
  }
  return 0;
}
