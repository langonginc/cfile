#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
using namespace std;
const int inf = 1000000000;
struct edge
{
	int w, v;
};
struct node
{
	int pos, dis;
	bool operator < (const node &a) const
  {
		return dis > a.dis;
	}
};
bool vis[1000005];
int d[1000005], dp[1000005];
vector <edge> adj[1000005];
priority_queue <node> q;
int N, m, s;
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
  dp[s] = 1;
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
			if(n.dis+w<d[v]){
				d[v]=n.dis+w;
				node tmp;
				tmp.dis=d[v];
				tmp.pos=v;
				q.push(tmp);
        dp[v] = dp[n.pos];
			}
      else if (n.dis + w == d[v])
      {
        dp[v] = (dp[v] + dp[n.pos]) % 100003;
      }
		}
	}
}
int main(){
	scanf("%d%d",&N,&m);
	int u, v;
  s = 1;
	edge vw;
	for(int i=0;i<m;i++){
		scanf("%d%d", &u, &v);
    vw.w = 1;
    vw.v = v;
		adj[u].push_back(vw);
    vw.v = u;
    adj[v].push_back(vw);
	}
	djstl();
	for(int i=1;i<=N;i++){
		cout<<dp[i]%100003<<endl;
	}
	return 0;
}
