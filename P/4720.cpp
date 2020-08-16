#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
namespace math{
  inline ll fastPow(ll x, ll y, ll mod)
  {
    ll r=1%mod,base=x%mod;
    while(y){
      if(y&1)
        r=r*base%mod;
      base=base*base%mod,y>>=1;
    }
    return r%mod;
  }
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
  inline ll inv(ll n,ll p)
  {
    ll x,y;
    exgcd(n,p,x,y);
    return (x%p+p)%p;
  }
  ll factor(ll n,ll p,ll pk)
  {
    if(n==0)return 1;
    ll ans=1;
    for(ll i=2;i<pk;i++)
    {
      if(i%p!=0)
      {
        ans=(ans*i)%pk;
      }
    }
    ans=fastPow(ans,n/pk,pk);
    for(ll i=2;i<=n%pk;i++)
    {
      if(i%p!=0)
      {
        ans=(ans*i)%pk;
      }
    }
    return ans*factor(n/p,p,pk)%pk;
  }
  inline ll comb(ll n,ll m,ll p,ll pk)
  {
    ll r=0;
    for(ll i=n;  i>0;i/=p)r+=i/p;
    for(ll i=m;  i>0;i/=p)r-=i/p;
    for(ll i=n-m;i>0;i/=p)r-=i/p;
    ll f1=factor(n,  p,pk),
       f2=factor(m,  p,pk),
       f3=factor(n-m,p,pk);
    return f1*inv(f2,pk)%pk*inv(f3,pk)%pk*fastPow(p,r,pk)%pk;
  }
  inline ll crt(ll a,ll m,ll p)
  {
    return a*inv(p/m,m)*(p/m);
  }
}
using math::crt;
using math::comb;

int main()
{
  ll n,m,p,t,ans=0;
  scanf("%lld%lld%lld",&n,&m,&p);
  t=p;
  for(ll i=2;i*i<=t;i++)
  {
    if(t%i==0)
    {
      ll pk=1;
      while(t%i==0)
      {
        t /=i,
        pk*=i;
      }
      ans=(ans+crt(comb(n,m,i,pk),pk,p))%p;
    }
  }
  if(t>1)
  {
    ans=(ans+crt(comb(n,m,t,t),t,p))%p;
  }
  printf("%lld\n",ans);
  return 0;
}
