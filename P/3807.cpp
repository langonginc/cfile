#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll t,n,m,p;

ll fastPow(ll x, ll y, ll mod)
{
  ll r=1%mod,base=x%mod;
  while(y){
    if(y&1)
      r=r*base%mod;
    base=base*base%mod,y>>=1;
  }
  return r%mod;
}

ll inv(ll x)
{
  return fastPow(x,p-2,p);
}

ll factor(ll x)
{
  ll ans=1;
  for(ll i=1;i<=x;i++)
  {
    ans=ans*i%p;
  }
  return ans%p;
}

inline ll combination(ll a,ll b)
{
  return b>a?0:factor(a)*inv(factor(b)*factor(a-b)%p)%p;
}

inline ll lucas(ll a,ll b)
{
  return b==0?1:combination(a%p,b%p)*lucas(a/p,b/p)%p;
}

int main()
{
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld%lld%lld",&n,&m,&p);
    printf("%lld\n",lucas(m+n,m));
  }
  return 0;
}
