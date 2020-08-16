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
const int inf=10005;
int n,m,mod = INF,sum[4*inf],mtag[4*inf],atag[4*inf],tili;
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
		sum[p]=1;
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
void addupdate(ll p,ll l,ll r,ll ql,ll qr,ll k){
	if(ql<=l&&r<=qr){
		sum[p]=(sum[p]+k*(r-l+1));
		atag[p]=(atag[p]+k);
		return ;
	}
	pushdown(p,l,r);
	ll mid=(l+r)>>1;
	if(ql<=mid){
		addupdate(lc(p),l,mid,ql,qr,k);
	}
	if(mid<qr){
		addupdate(rc(p),mid+1,r,ql,qr,k);
	}
	pushup(p);
}
void mulupdate(ll p,ll l,ll r,ll ql,ll qr,ll k){
	if(ql<=l&&r<=qr){
		sum[p]=(sum[p]*k);
		mtag[p]=(mtag[p]*k);
		atag[p]=(atag[p]*k);
		return;
	}
	pushdown(p,l,r);
	ll mid=(l+r)>>1;
	if(ql<=mid){
		mulupdate(lc(p),l,mid,ql,qr,k);
	}
	if(mid<qr){
		mulupdate(rc(p),mid+1,r,ql,qr,k);
	}
	pushup(p);
}
ll check(ll p,ll l,ll r,ll ql,ll qr){
	if(ql<=l&&r<=qr){
		return sum[p];
	}
	pushdown(p,l,r);
	ll mid=(l+r)>>1,result=0;
	if(ql<=mid){
		result+=check(lc(p),l,mid,ql,qr);
	}
	if(mid<qr){
		result+=check(rc(p),mid+1,r,ql,qr);
	}
	return result;
}
int main(){
	scanf("%d%d%d",&n,&m,&tili);
	build(1,1,n);
	for(ll i=1;i<=m;i++){
		int x,y;
    scanf("%d%d",&x,&y);
    tili += check(1,1,n,x,y);
    mulupdate(1,1,n,x,y,-1);
	}
  if (tili > 0)
    printf ("%d", tili);
  else
    printf ("NO!");
	return 0;
} 
