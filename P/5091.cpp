#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;

ll euler_phi(ll n) {
  ll ans=n;
  for (int i=2;i*i<=n;++i){
    if (n%i==0) {
      ans=ans/i*(i-1);
      while(n%i==0)n/=i;
    }
  }
  if(n>1)ans=ans/n*(n-1);
  return ans;
}

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

ll a,b,m;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  scanf("%lld%lld ",&a,&m);
  ll phi=euler_phi(m);
  char c;
  bool f=false;
  while(scanf("%c",&c)>0){
  // while(cin>>c){
    if (c<'0' || c>'9') break;
    b=b*10+(c-'0');
    if(b>=phi)f=true;
    b%=phi;
  }
  if(f)
  {
    printf("%lld",fastPow(a,b%phi+phi,m));
  }
  else
  {
    printf("%lld",fastPow(a,b,m));
  }
}
