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
const_int_2 INF=INT_MAX/3;
const int inf=100000;
struct edge{
	int u,v,w;
	bool operator<(const edge& a)const{
	return w<a.w;
	}
}ph[inf];
//struct node{
//	int pos,dis;
//	bool operator<(const node& a)const{
//		return dis>a.dis;
//	}
//};
int n,m,c=0,f[inf],ans=-1;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void kal(){
	for(int i=0;i<m;i++){
		edge p=ph[i];
		if(find(p.u)!=find(p.v)){
			f[find(p.u)]=find(p.v);
			ans=max(p.w,ans);
			c++;
			if(c==n-1)return;
		}
	}
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&ph[i].u,&ph[i].v,&ph[i].w);
	}
	for(int i=0;i<=n;i++){
		f[i]=i;
	}
	sort(ph,ph+m);
	kal();
	cout<<c<<" "<<ans;
	return 0;
} 
