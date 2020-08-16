#include<iostream>
#include<cstdio>
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
    x=y1;
    y=x1-a/b*y1;
    return g;
  }
}

ll n,x,m=1,mi,ai,t,y;

inline ll mul(ll a,ll b,ll m)
{
  ll base=a%m,r=0;
  while(b)
  {
    if(b&1)
      r=(r+base)%m;
    base=(base<<1)%m;
    b>>=1;
  }
  return r;
}

int main()
{
  scanf("%lld",&n);
  for(ll i=0;i<n;i++)
  {
    scanf("%lld%lld",&mi,&ai);
    ll c=((ai-x)%mi+mi)%mi;
    ll g=exgcd(m,mi,t,y);
    t=mul(t,c/g,mi/g);
    x=(x+t*m);
    m=m/g*mi;
    x=(x%m+m)%m;
  }
  printf("%lld",x);
  return 0;
}

