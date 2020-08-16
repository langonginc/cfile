#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
bool stan;
void gcd( ll a, ll b )
{
  if( a >= 2 * b || a == b )
  {
    return ;
  }
  stan = ! stan;
  gcd( b, a % b );
}

int main()
{
  ll t, n, m;
  scanf( "%lld", &t );
  while( t -- )
  {
    scanf( "%lld%lld", &n, &m );
    if( n < m )
    {
      swap( n, m );
    }
    stan = true;
    gcd( n, m );
    if( stan )
    {
      printf( "Stan wins\n" );
    }
    else{
      printf( "Ollie wins\n" );
    }
  }
  return 0;;
}
