#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
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
vector<int> ter;
priority_queue<node> q;
int N,m,s,c[100005];
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
  // ter.push_back(1);
	while(!q.empty()){
		n=q.top();
		q.pop();
		if(vis[n.pos]==true){
			continue;
		}
    printf("%d _ POS\n",n.pos);
    ter.push_back(n.pos);
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
//	memset(vis,0,sizeof(vis));
//	memset(d,0x3f,sizeof(d));
  int k;
	scanf("%d%d%d",&N,&m,&k);
  s=1;
	int u;
	edge vw;
	for(int i=0;i<m;i++){
		scanf("%d%d%d", &u, &vw.v, &vw.w);
		adj[u].push_back(vw);
	}
	djstl();
  int ans=0,bnum=0;
  for(int i=0;i<ter.size();i++){
    printf("%d _ IN TER[]\n",ter[i]);
  }
	for(int i=1;i<ter.size();i++){
    int xu=ter[i-1],xv=ter[i],xz=0;
    for(int j=0;j<adj[xu].size();j++){
      if(adj[xu][j].v==xv){
        xz=adj[xu][j].w;
        break;
      }
    }
    c[bnum++]=xz;
    if(ter[i]==N)break;
  }
  for(int i=0;i<bnum;i++){
    printf("%d _ SORT \n",c[i]);
  }
  sort(c,c+bnum);
  for(int i=bnum-1;i>=bnum-k;i--){
    ans+=-c[i];
    printf("%d is\n",c[i]);
  }
  for(int i=bnum-k-1;i>=0;i--){
    ans+=c[i];
    printf("%d\n",c[i]);
  }
  printf("%d\n",ans);
	return 0;
}
