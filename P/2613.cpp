#include<iostream>
#include<cstdio>
#include<cmath>
typedef long long ll;
const ll mod=19260817;

template <class Tp> inline Tp read()
{
  ll base=1;
  Tp x=0;
  char ch=getchar();
  while(ch>'9'||ch<'0')
  {
    if(ch=='-')
      base=-1;
    ch=getchar();
  }
  while(ch<='9'&&ch>='0')
    x=x*10%mod+(ch-'0')%mod,ch=getchar();
  return x%mod*base;
}

inline ll fastPow (ll x, ll y)
{
  ll r=1%mod,base=x%mod;
  while (y)
  {
    if (y&1)
    {
      r=r*base%mod;
    }
    base=base*base%mod,y>>=1;
  }
  return r%mod;
}

ll a,b,ans;

int main()
{
  // scanf("%lld%lld",&a,&b);
  a=read<ll>();
  b=read<ll>();
  // a%=mod,b%=mod;
  if(b==0)
  {
    printf("Angry!\n");
  }
  else
  {
    ans=a*fastPow(b,mod-2)%mod;
    printf("%lld",(ans+mod)%mod);
  }
  return 0;
}
