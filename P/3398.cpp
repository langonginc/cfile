#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<climits>
#include<cmath>
#include<vector>
using namespace std;
const int INF=INT_MAX;
const int inf=100005;
struct node{
	int to,w,next;
}pool[3*inf];
int n,m,nn,par[inf][20],dep[inf],head[inf],lg[inf];
void add(int u,int v){
	pool[++nn].to=v;
	pool[nn].next=head[u];
	head[u]=nn;
}
void dfs(int r,int f){
//	cout<<r<<" "<<f<<endl;
	dep[r]=dep[f]+1;
	par[r][0]=f;
	for(int i=1;(1<<i)<=dep[r];i++){
		par[r][i]=par[par[r][i-1]][i-1];
	}
	for(int i=head[r];i!=0;i=pool[i].next){
		if(pool[i].to!=f){
			dfs(pool[i].to,r);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	while(dep[x]>dep[y]){
		x=par[x][lg[dep[x]-dep[y]]-1];
	}
	if(x==y)return x;
	for(int i=lg[dep[x]];i>=0;i--){
		if(par[x][i]!=par[y][i]){
			x=par[x][i],y=par[y][i];
		}
	}
	return par[x][0];
}
bool pass(int x,int a,int b){
	if(dep[x]<dep[lca(a,b)])return false;
	return x==lca(x,a)|| x==lca(x,b);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++){
		lg[i]=lg[i-1]+((1<<lg[i-1])==i);
	}
	dfs(1,0);
	for(int i=0;i<m;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(pass(lca(a,b),c,d)||pass(lca(c,d),a,b)){
			printf("Y\n");
		}
		else{
			printf("N\n");
		}
	}
	return 0;
}
