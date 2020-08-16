#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;

ll fastPow(ll x, ll y, ll mod)
{
  ll r=1%mod,base=x%mod;
  while(y){
    if(y&1)
      r=r*base%mod;
    base=base*base%mod;
    y>>=1;
  }
  return r%mod;
}

void bsgs(ll a,ll b,ll p)
{
  ll m=ceil(sqrt(p));
  ll t=b;
  map<ll,ll> dict;
  dict[b]=0;
  for(ll i=1;i<m;i++)
  {
    t=t*a%p;
    dict[t]=i;
  }
  ll m1=fastPow(a,m,p);
  t=1;
  for(ll i=1;i<=m;i++)
  {
    t=t*m1%p;
    if(dict.count(t)!=0)
    {
      printf("%lld\n",i*m-dict[t]);
      return;
    }
  }
  printf("no solution\n");
}

int main()
{
  ll a,b,p;
  scanf("%lld%lld%lld",&p,&a,&b);
  bsgs(a,b,p);
  return 0;
}
