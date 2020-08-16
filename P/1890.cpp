#include<iostream>
using namespace std;
#include<cstdio>
#include<cmath>
const int inf=1005;
int n,m,a[inf],sum[inf*4];//tag[inf*4];
int gcd(int x, int y){
    if(y == 0)
		return x;    
	return gcd(y, x%y); 
} 

inline int lc(int p){
	return p<<1;
}
inline int rc(int p){
	return p<<1|1;
}
//void movetag(int p,int l,int r,int f){
//	sum[p]+=f*(r-l+1);
//	tag[p]+=f;
//}
void pushup(int p){
	sum[p]=gcd(sum[lc(p)],sum[rc(p)]);
}
//void pushdown(int p,int l,int r){
//	int mid=(l+r)>>1;
//	movetag(lc(p),l,mid,tag[p]);
//	movetag(rc(p),mid+1,r,tag[p]);
//	tag[p]=0;
//}
//void update(int p,int l,int r,int ql,int qr,int d){
//	if(ql<=l&&r<=qr){
//		sum[p]+=d*(r-l+1);
//		tag[p]+=d;
//		return;
//	}
//	pushdown(p,l,r);
//	int mid=(l+r)>>1;
//	if(ql<=mid){
//		update(lc(p),l,mid,ql,qr,d);
//	}
//	if(mid<qr){
//		update(rc(p),mid+1,r,ql,qr,d);
//	}
//	pushup(p);
//}
void build(int p,int l,int r){
	if(l==r){
		sum[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lc(p),l,mid);
	build(rc(p),mid+1,r);
	pushup(p);
}
int check(int p,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return sum[p];
//	pushdown(p,l,r);
	int mid=(l+r)>>1,result=0;
	if(ql<=mid){
		result=gcd(result,check(lc(p),l,mid,ql,qr));
	}
	if(mid<qr){
		result=gcd(result,check(rc(p),mid+1,r,ql,qr));
	}
	return result;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",check(1,1,n,a,b));
	}
	return 0;
}
