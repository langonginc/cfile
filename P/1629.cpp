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
typedef const int const_int_forever;
const_int_forever INF=INT_MAX;
const_int_forever AC=0;
const int inf=1000000;
struct edge{
	int pos,dis;
};
struct node{
	int pos,dis;
	bool operator<(const node &a)const{
		return dis>a.dis;
	}
};
priority_queue<node>q;
vector<edge> adj1[inf/5];
vector<edge> adj2[inf/5];
int d1[inf/5],d2[inf/5],N,M;
bool vis[inf/5];
int main(){
	scanf("%d%d",&N,&M);
	int u,v,w;
	edge a;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&u,&v,&w);
		a.dis=w;
		a.pos=v;
		adj1[u].push_back(a);
		a.pos=u;
		adj2[v].push_back(a);
	}
	for(int i=1;i<=N;i++){
		vis[i]=false;
		d1[i]=INF;
	}
	node n;
	n.dis=0;
	n.pos=1;
	q.push(n);
	d1[1]=0;
	while(!q.empty()){
		n=q.top();
		q.pop();
		if(vis[n.pos]==true){
			continue;
		}
		vis[n.pos]=true;
		for(int i=0;i<adj1[n.pos].size();i++){
			int v=adj1[n.pos][i].pos;
			int w=adj1[n.pos][i].dis;
			if(d1[n.pos]+w<d1[v]){
				d1[v]=d1[n.pos]+w;
				node tmp;
				tmp.dis=d1[v];
				tmp.pos=v;
				q.push(tmp);
			}
		}
	}
	while(!q.empty()){
		q.pop();
	}
	for(int i=1;i<=N;i++){
		d2[i]=INF;
		vis[i]=false;
	}
	n.dis=0;
	n.pos=1;
	q.push(n);
	d2[1]=0;
	while(!q.empty()){
		n=q.top();
		q.pop();
		if(vis[n.pos]==true){
			continue;
		}
		vis[n.pos]=true;
		for(int i=0;i<adj2[n.pos].size();i++){
			int v=adj2[n.pos][i].pos;
			int w=adj2[n.pos][i].dis;
			if(d2[n.pos]+w<d2[v]){
				d2[v]=d2[n.pos]+w;
				node tmp;
				tmp.dis=d2[v];
				tmp.pos=v;
				q.push(tmp);
			}
		}
	}
	for(int i=1;i<=N;i++){
		if(d1[i]>=INF||d2[i]>=INF){
			printf("ERROR value with -1::short length is error");
			return -1;
		}
		d1[i]+=d2[i];
	}
	int sum=0;
	for(int i=1;i<=N;i++){
		sum+=d1[i];
	}
	cout<<sum;
	return AC;
}
