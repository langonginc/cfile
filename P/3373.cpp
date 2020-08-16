//模板2 
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
typedef const int const_int_2;
typedef long long ll;
const_int_2 INF=INT_MAX/3;
const int inf=100005;
int n,m,mod,a[inf],sum[4*inf],mtag[4*inf],atag[4*inf];
inline ll lc(ll p){
	return p<<1;
}
inline ll rc(ll p){
	return p<<1 |1;
}
void pushup(ll p){
	sum[p]=(sum[lc(p)]+sum[rc(p)])%mod;
}
void movetag(ll p,ll l,ll r,ll mt,ll at){
	sum[p]=(sum[p]*mt+at*(r-l+1))%mod;
	atag[p]=(atag[p]*mt+at)%mod;
	mtag[p]=(mtag[p]*mt)%mod;
}
void build(ll p,ll l,ll r){
	mtag[p]=1,atag[p]=0;
	if(l==r){
		sum[p]=a[l]%mod;
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
		sum[p]=(sum[p]+k*(r-l+1))%mod;
		atag[p]=(atag[p]+k)%mod;
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
		sum[p]=(sum[p]*k)%mod;
		mtag[p]=(mtag[p]*k)%mod;
		atag[p]=(atag[p]*k)%mod;//add
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
		return sum[p]%mod;
	}
	pushdown(p,l,r);
	ll mid=(l+r)>>1,result=0;
	if(ql<=mid){
		result+=check(lc(p),l,mid,ql,qr);
	}
	if(mid<qr){
		result+=check(rc(p),mid+1,r,ql,qr);
	}
	return result%mod;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&mod);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	build(1,1,n);
	for(ll i=1;i<=m;i++){
		ll type,x,y,k;
		scanf("%lld",&type);
		if(type==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			mulupdate(1,1,n,x,y,k);
		}
		else if(type==2){
			scanf("%lld%lld%lld",&x,&y,&k);
			addupdate(1,1,n,x,y,k);
		}
		else{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",check(1,1,n,x,y));
		}
	}
	return 0;
} 
