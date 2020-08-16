#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll mod=10007;
ll a,b,n,m,k,zuhe[1005][1005];

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
void getC()
{
  for(ll i=0;i<=1000;i++){
    zuhe[i][0]=1;
    zuhe[i][i]=1;
  }
  for(ll i=2;i<=1000;i++){
    for(ll j=1;j<=1000;j++){
      zuhe[i][j]=(zuhe[i-1][j]+zuhe[i-1][j-1])%mod;
    }
  }
}

int main()
{
  getC();
  scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
  a%=mod,b%=mod;
  printf("%lld\n",(fastPow(a,n,mod)%mod)*(fastPow(b,m,mod)%mod)*(zuhe[k][n]%mod)%mod);
  return 0;
}
