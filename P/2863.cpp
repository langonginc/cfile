#include<iostream>
using namespace std;
#include<cstdio>
#include<stack>
#include<vector>
const int inf=5*1e5+5;
vector<int>adj[inf];
stack<int>s;
int n,m,pre[inf],low[inf],sccno[inf],scc,tm,ans;
bool vis[inf];
void tarjan(int u){
	pre[u]=low[u]=++tm;
	s.push(u);
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(pre[v]==0){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(sccno[v]==0){
			low[u]=min(low[u],pre[v]);
		}
	}
	if(pre[u]==low[u]){
		scc++;
		int c=0;
		while(inf){
			int temp=s.top();
			s.pop();
			c++;
			sccno[temp]=scc;
			if(temp==u){
				break;
			}		
		}
		ans+=(c>1);
	}
	vis[u]=1;
	return;
}
void dfs_start(){
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			tarjan(i);
		}
	}
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
	}
	dfs_start();
//	for(int i=1;i<=scc;i++){
//		ans+=(sccno[i]>1);
//	}
	printf("%d\n",ans);
//	for(int i=1;i<=scc;i++){
//		printf("%d ",sccno[i]);
//	}
	return 0;;
}
