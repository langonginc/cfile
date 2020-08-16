#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
const int INF=1000005;
const int inf=50005;
inline int lc(int p){
	return p<<1;
}
inline int rc(int p){
	return p<<1|1;
}
int n,m,a[inf],mi[inf*4],ma[inf*4];
void push(int p){
	mi[p]=min(mi[lc(p)],mi[rc(p)]);
	ma[p]=max(ma[lc(p)],ma[rc(p)]);
}
void build(int p,int l,int r){
	if(l==r){
		mi[p]=a[l];
		ma[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lc(p),l,mid);
	build(rc(p),mid+1,r);
	push(p);
}
int checkmi(int p,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return mi[p];
	int ans=INF,mid=(l+r)>>1;
	if(ql<=mid){
		ans=min(ans,checkmi(lc(p),l,mid,ql,qr));
	}
	if(mid<qr){
		ans=min(ans,checkmi(rc(p),mid+1,r,ql,qr));
	}
	return ans;
}
int checkma(int p,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return ma[p];
	int ans=-1,mid=(l+r)>>1;
	if(ql<=mid){
		ans=max(ans,checkma(lc(p),l,mid,ql,qr));
	}
	if(mid<qr){
		ans=max(ans,checkma(rc(p),mid+1,r,ql,qr));
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	for(int i=0;i<m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		int ca=checkma(1,1,n,l,r),ci=checkmi(1,1,n,l,r);
		printf("%d\n",ca-ci);
	}
	return 0;
}
