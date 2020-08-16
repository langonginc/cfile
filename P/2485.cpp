/*
2485.cpp for luogu.com.cn
Atom Edit
*/

#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
const char orz[100]="Orz, I cannot find x!";
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

void bsgs(ll a,ll b,ll p)
{
  a%=p,b%=p;
  if(a==0 && b==0)
  {
    printf("1\n");
    return;
  }
  else if(a==0)
  {
    printf("%s\n",orz);
    return;
  }
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
  printf("%s\n",orz);
}

int main()
{
  ll t,k,x,y,z,p,q;
  scanf("%lld%lld",&t,&k);
  if(k==1)
  {
    for(ll i=0;i<t;i++)
    {
      scanf("%lld%lld%lld",&y,&z,&p);
      printf("%lld\n",fastPow(y,z,p));
    }
  }
  else if(k==2)
  {
    for(ll i=0;i<t;i++)
    {
      scanf("%lld%lld%lld",&y,&z,&p);
      x=0,q=0;
      ll gcd=exgcd(y,p,x,q);
      if(z%gcd==0)
      {
        x=(((x*z)/gcd)%(p/gcd)+(p/gcd))%(p/gcd);
        printf("%lld\n",x);
      }
      else
      {
        printf("%s\n",orz);
      }
    }
  }
  else
  {
    for(ll i=0;i<t;i++)
    {
      scanf("%lld%lld%lld",&y,&z,&p);
      bsgs(y,z,p);
    }
  }
  return 0;
}
