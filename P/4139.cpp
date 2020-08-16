#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

ll phi[19009000],prime[19009000],tot;

void EulerTable(ll n)
{
  phi[1]=1;
  for(ll i=2;i<=n;i++)
  {
    if(phi[i]==0)
    {
      phi[i]=i-1,prime[tot++]=i;
    }
    for(ll j=0;j<tot && i*prime[j]<=n;j++)
    {
      if(i%prime[j]==0)
      {
        phi[i*prime[j]]=phi[i]*prime[j];
        break;
      }
      else
      {
        phi[i*prime[j]]=phi[i]* (prime[j]-1);
      }
    }
  }
}

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

ll f(ll n)
{
  if(n==1)return 0;
  else return fastPow(2,f(phi[n])+phi[n],n);
}

int main()
{
  EulerTable(10000000);
  ll t,n;
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld",&n);
    printf("%lld\n",f(n));
  }
  return 0;
}
