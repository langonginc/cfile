#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
  int n, a[ 50 ];
  scanf( "%d", &n );
  for( int i = 0; i < n; i ++ )
  {
    scanf( "%d", &a[ i ] );
  }
  int step1 = 0;
  for( int i = 0; i < n; i ++ )
  {
    if( a[ i ] == 0 )
    {
      break;
    }
    step1 ++;
  }
  int step2 = 0;
  for( int i = n - 1; i >= 0; i -- )
  {
    if( a[ i ] == 0 )
    {
      break;
    }
    step2 ++;
  }
  if( ( step1 & 1 ) == 1 || ( step2 & 1 ) == 1 )
  {
    printf( "YES\n" );
  }
  else{
    printf( "NO\n" );
  }
  return 0;
}
