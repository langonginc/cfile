#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<climits>
using namespace std;
const int INF=INT_MAX;
const int inf=105;
struct edge{
	int v,w;
};
struct node{
	int v,w;
	bool operator <(const node &a)const{
		return w>a.w;
	}
};
vector<edge> adj[inf];

int N,a,b,d[inf];
bool vis[inf];
void dij(){
	for(int i=0;i<=N;i++){
		vis[i]=false;
		d[i]=INF;
	}
	node n;
	n.v=a;
	n.w=0;
	priority_queue<node> q;
	q.push(n);
	d[a]=0;
	while(!q.empty()){
		n=q.top();
		q.pop();
		if(n.v==b)
			return;
		if(vis[n.v]==true){
			continue;
		}
		vis[n.v]=true;
		for(int i=0;i<adj[n.v].size();i++){
			int v=adj[n.v][i].v;
			int w=adj[n.v][i].w;
			if(d[n.v]+w<d[v]){
				d[v]=d[n.v]+w;
				node tmp;
				tmp.w=d[v];
				tmp.v=v;
				q.push(tmp);
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&N,&a,&b);
	int k;
	edge u;
	for(int i=1;i<=N;i++){
		scanf("%d%d",&k,&u.v);
		u.w=0;
		adj[i].push_back(u);
		for(int j=1;j<k;j++){
			scanf("%d",&u.v);
			u.w=1;
			adj[i].push_back(u);
		}
	}
	dij();
	if(d[b]>=INF){
		printf("-1");
	}
	else{
		printf("%d",d[b]);
	}
	return 0;
}
