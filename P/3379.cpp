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
const int inf=500005;
int n,m,s,par[inf][30],head[3*inf],lg[3*inf],nn=0,dep[3*inf];
struct node{
	int to,w,next;
}pool[3*inf];
void add(int u,int v){
	pool[++nn].to=v;
	pool[nn].next=head[u];
	head[u]=nn;
}
void dfs(int r,int f){
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
			x=par[x][i];
			y=par[y][i];
		}
	}
	return par[x][0];
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++){
		lg[i]=lg[i-1]+((1<<lg[i-1])==i);
	}
	dfs(s,0);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y)); 
	}
	return 0;
} 
