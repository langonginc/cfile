#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod=999911659;
const ll prime[4]={2,3,4679,35617};
ll factor[4][35620],inv[4][35620],a[4];

inline ll combination(ll n,ll m,ll index)
{
  return m>n?0:factor[index][n]*inv[index][factor[index][m]]%prime[index]*inv[index][factor[index][n-m]]%prime[index];
}

inline ll lucas(ll n,ll m,ll index)
{
  return m==0?1:combination(n%prime[index],m%prime[index],index)*lucas(n/prime[index],m/prime[index],index)%prime[index];
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

ll crt()
{
  ll ans=0;
  for(ll i=0;i<4;i++)
  {
    ans=(ans+a[i]*((mod-1)/prime[i])*inv[i][((mod-1)/prime[i])%prime[i]])%(mod-1);
  }
  return ans;
}

int main()
{
  ll n,g;
  scanf("%lld%lld",&n,&g);
  if(g%mod==0)
  {
    printf("0\n");
    return 0;
  }

  for(int i=0;i<4;i++)
  {
    factor[i][0]=factor[i][1]=inv[i][1]=1;
    for(ll j=2;j<prime[i];j++)
    {
      factor[i][j]=factor[i][j-1]*j%prime[i];
      inv[i][j]=(prime[i]-prime[i]/j)*inv[i][prime[i]%j]%prime[i];
    }

    for(ll j=1;j*j<=n;j++)
    {
      if(n%j==0)
      {
        a[i]=(a[i]+lucas(n,j,i))%prime[i];
        if(j*j!=n)
        {
          a[i]=(a[i]+lucas(n,n/j,i))%prime[i];
        }
      }
    }
  }

  printf("%lld",fastPow(g,crt(),mod));
  return 0;
}
