namespace math{
    typedef long long ll;
    ll fastpow(ll x, ll y, ll mod){
        ll r=1%mod,base=x%mod;
        while(y){
            if(y&1){
                r=r*base%mod;
            }
            base=base*base%mod,y>>=1;
        }
        return r%mod;
    }
    ll gcd(ll x,ll y){
      return y?gcd(y,x%y):x;
    }
    int gcd(int x,int y){
      return y?gcd(y,x%y):x;
    }
}
#include<iostream>
#include<cstdio>
using namespace std;
using namespace math;
ll mod=1e9+7;
int main(){
  ll w,n,k;
  scanf("%lld%lld%lld",&w,&n,&k);
  printf("%lld\n",(w*fastpow(fastpow(2,k,mod),mod-2,mod))%mod);
  return 0;
}

