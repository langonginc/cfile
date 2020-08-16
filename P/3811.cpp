#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll inv[100000005],n,p;
int main(){
  scanf("%lld%lld",&n,&p);
  inv[1]=1;
  for(ll i=2;i<=n;i++){
    inv[i]=( (p-p/i) *inv[p%i] )%p;
  }
  for(ll i=1;i<=n;i++){
    printf("%lld\n",inv[i]);
  }
  return 0;
}

