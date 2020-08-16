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
const_int_2 INF=INT_MAX;
const int inf=1000005;
struct edge{
	int v;
	double w,y;
};
struct node{
	int v;
	double w;
	bool operator<(const node& a)const{
		return w>a.w;
	}
};
vector<edge> adj[inf];
priority_queue<node>q;
int n,m,a,b;
double d[inf];
bool vis[inf];
int main(){
	scanf("%d%d",&n,&m);
	int u,v,w;
	double ww;
	edge vw;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&v,&u,&w);
		ww=w;
		ww=100.0-w;
		vw.w=100.0/ww;
		vw.v=v;
		adj[u].push_back(vw);
		vw.v=u;
		adj[v].push_back(vw);
	}
	scanf("%d%d",&a,&b);
	for(int i=0;i<=n+1;i++){
		d[i]=INF;
		vis[i]=false;
	}
	node p;
	p.v=a;
	p.w=1;
	q.push(p);
	d[a]=100;
	while(!q.empty()){
		p=q.top();
		q.pop();
		if(vis[p.v]==true)continue;
		vis[p.v]=true;
		for(int i=0;i<adj[p.v].size();i++){
			int v=adj[p.v][i].v;
			double w=adj[p.v][i].w;
			if(d[p.v]*w<d[v]){
				d[v]=d[p.v]*w;
				node tmp;
				tmp.v=v;
				tmp.w=d[v];
				q.push(tmp);
			}
		}
	}
	printf("%.8lf",d[b]);
	return 0;
}
