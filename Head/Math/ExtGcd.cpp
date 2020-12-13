#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
  if(b==0)
  {
    x=1,y=0;
    return a;
  }
  else
  {
    ll x1,y1,g=exgcd(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1;
    return g;
  }
}
