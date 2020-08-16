#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<climits>
#include<cmath>
#include<vector>
using namespace std;
const int INF=INT_MAX;
const int inf=10000005; 
int posterl[1005],posterr[1005],a[10000],n,m,unin,treen,bucket[inf];
bool cover[inf];
inline int lc(int p);
inline int rc(int p);
bool update(int p,int l,int r,int ql,int qr);
void pushup(int p);
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>posterl[i]>>posterr[i];
		a[2*i-1]=posterl[i];
		a[2*i]=posterr[i];
	}
	sort(a+1,a+1+2*m);
	unin=unique(a+1,a+1+2*m)-(a+1);
	treen=1;
	for(int i=0;i<unin;i++){
		bucket[a[i]]=treen;
		if(a[i+1]-a[i]==1){
			treen++;
		}
		else{
			treen+=2;
		}
	}
	bucket[a[unin]]=treen;
	int ans=0;
	for(int i=m;i>=1;i--){
		if(!update(1,1,treen,bucket[posterl[i]],bucket[posterr[i]])){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
void pushup(int p){
	cover[p]=cover[lc(p)] && cover[rc(p)];
}
bool update(int p,int l,int r,int ql,int qr){
	if(cover[p]){
		return true;
	}
	bool ans=true;
	if(ql<=l&&r<=qr){
		ans=cover[p];
		cover[p]=true;
		return ans;
	}
	int mid=(l+r)>>1;
	if(ql<=mid){
		if(!update(lc(p),l,mid,ql,qr)){
			ans=false;
		}
	}
	if(mid<qr){
		if(!update(rc(p),mid+1,r,ql,qr)){
			ans=false;
		}
	}
	pushup(p);
	return ans;
}
inline int lc(int p){
	return p<<1;
}
inline int rc(int p){
	return p<<1|1;
}
