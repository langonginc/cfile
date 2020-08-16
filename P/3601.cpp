#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll Mn=1e6+5;
const ll mod=666623333;
ll prime[Mn],l,r,phi[Mn],vis[Mn],pc,ans,a[Mn];

void getprime(){
  for(ll i=2;i<Mn;i++){
    if(a[i])
      prime[pc++] = i;
    for(ll j=0;j<pc && prime[j]*i<Mn;j++){
      a[prime[j]*i]=false;
      if(i%prime[j]==0)
        break;
    }
  }
}

int main(){
  scanf("%lld%lld" ,&l,&r);
  for(int i=0;i<Mn;i++)a[i]=true;
  getprime();
  for(ll i=l;i<=r;i++){
    vis[i-l]=i;
    phi[i-l]=i;
  }
  for(ll i=0;i<pc && prime[i]*prime[i]<=r;i++){
    ll p=prime[i],start=l;
    if(l%p!=0){
      start=l/p*p+p;
    }
    for(ll j=start;j<=r;j=j+p){
      phi[j-l]=phi[j-l]/p*(p-1);
      while(vis[j-l]%p==0)
        vis[j-l]/=p;
    }
  }
  for(ll i=l;i<=r;i++){
    if(vis[i-l]>1){
      phi[i-l]=phi[i-l]/vis[i-l]*(vis[i-l]-1);
    }
    ans=(ans+(i-phi[i-l]))%mod;
  }
  printf("%lld\n",ans);
  return 0;
}

