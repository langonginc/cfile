#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
using namespace std;
const int inf=1000000000;
const int AC=0;
struct edge{
	int w,v;
};
struct node{
	int pos,dis;
	bool operator <(const node &a)const{
		return dis>a.dis;
	}
};
bool vis[100005];
int d[100005];
vector<edge> adj[100005];
priority_queue<node> q;
int N,m,s;
void djstl(){
	for(int i=1;i<=N;i++){
		vis[i]=false;
		d[i]=inf;
	}
	node n;
	n.pos=s;
	n.dis=0;
	q.push(n);
	d[s]=0;
	while(!q.empty()){
		n=q.top();
		q.pop();
		if(vis[n.pos]==true){
			continue;
		}
		vis[n.pos]=true;
		for(int i=0;i<adj[n.pos].size();i++){
			int v=adj[n.pos][i].v;
			int w=adj[n.pos][i].w;
			if(d[n.pos]+w<d[v]){
				d[v]=d[n.pos]+w;
				node tmp;
				tmp.dis=d[v];
				tmp.pos=v;
				q.push(tmp);
			}
		}
	}
}
int main(){
//	memset(vis,0,sizeof(vis)d);
//	memset(d,0x3f,sizeof(d));
	scanf("%d%d%d",&N,&m,&s);
	
  int u;
	edge vw;
	for(int i=0;i<m;i++){
		scanf("%d%d%d", &u, &vw.v, &vw.w);
		adj[u].push_back(vw);
	}
	djstl();
	for(int i=1;i<=N;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
