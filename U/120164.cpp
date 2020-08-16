#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iomanip>
#include<cstdlib> 
#include<set>
#include<vector> 
#include<climits>
using namespace std;
typedef long long ll;
const int INF=INT_MAX/3;
const int inf=200005;
int n,m,mod = INF,sum[4*inf],mtag[4*inf],atag[4*inf],a[inf];
inline ll lc(ll p){
  return p<<1;
}
inline ll rc(ll p){
  return p<<1 |1;
}
void pushup(ll p){
  sum[p]=(sum[lc(p)]+sum[rc(p)]);
}
void movetag(ll p,ll l,ll r,ll mt,ll at){
  sum[p]=(sum[p]*mt+at*(r-l+1));
  atag[p]=(atag[p]*mt+at);
  mtag[p]=(mtag[p]*mt);
}
void build(ll p,ll l,ll r){
  mtag[p]=1,atag[p]=0;
  if(l==r){
    sum[p]=a[p];
    return ;
  }
  ll mid=(l+r)>>1;
  build(lc(p),l,mid);
  build(rc(p),mid+1,r);
  pushup(p); 
}
void pushdown(ll p,ll l,ll r){
  ll mid=(l+r)>>1;
  movetag(lc(p),l,mid,mtag[p],atag[p]);
  movetag(rc(p),mid+1,r,mtag[p],atag[p]);
  atag[p]=0,mtag[p]=1;
}
void xorupdate(ll p,ll l,ll r,ll ql,ll qr,ll k){
  if(ql<=l&&r<=qr){
		sum[p]=(sum[p]^k);
		mtag[p]=(mtag[p]^k);
		atag[p]=(atag[p]^k);
    return ;
  }
  pushdown(p,l,r);
  ll mid=(l+r)>>1;
  if(ql<=mid){
    xorupdate(lc(p),l,mid,ql,qr,k);
  }
  if(mid<qr){
    xorupdate(rc(p),mid+1,r,ql,qr,k);
  }
  pushup(p);
}
ll check(ll p,ll l,ll r,ll ql,ll qr){
  if(ql<=l&&r<=qr){
    return sum[p];
  }
  pushdown(p,l,r);
  ll mid=(l+r)>>1, result=0;
  if(ql<=mid){
    result+=check(lc(p),l,mid,ql,qr);
  }
  if(mid<qr){
    result+=check(rc(p),mid+1,r,ql,qr);
  }
  return result;
}
int main(){
  scanf("%d%d",&n,&m);
  for (int i = 1; i <= n; i ++)
    scanf ("%d", &a[i]);
  build(1,1,n);
  for(ll i=1;i<=m;i++){
    ll op,x,y,z;
    scanf ("%lld", &op);
    if (op == 1)
    {
      scanf("%lld%lld%lld",&x,&y,&z);
      xorupdate(1,1,n,x,y,z);
    }
    else
    {
      scanf ("%lld%lld", &x, &y);
      printf ("%lld\n",check(1, 1, n, x, y));
    }
  }
  return 0;
}
