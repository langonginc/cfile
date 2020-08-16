#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;
const int INF=INT_MAX;
const int inf=300000;
struct node{
	int u,v,w;
	bool operator<(const node &a)const{
		return w<a.w;
	}
}ph[inf];
int n,m,f[inf],ans=0,c=0;
int find(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=find(f[x]);
	return f[x];
}
bool kal(){
	for(int i=0;i<m;i++){
		node p=ph[i];
		if(find(p.u)!=find(p.v)){
			f[find(p.u)]=find(p.v);
			ans+=p.w;
			c++;
			if(c==n-1)return true;
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&ph[i].u,&ph[i].v,&ph[i].w);
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(ph,ph+m);
	if(kal()==true){
		cout<<ans;
	}
	else{
		cout<<"orz";
	}
	return 0;
}
