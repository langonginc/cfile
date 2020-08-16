#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main()
{
  ll t, n, a[ 100005 ], num;
  scanf("%lld",&t);
  while( t -- ) {
    scanf("%lld",&n);
    num = 0;
    for(int i = 1; i <= n; ++i)
    {
      scanf("%lld",&a[ i ] );
      num ^= a[ i ];
    }
    if(num)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
