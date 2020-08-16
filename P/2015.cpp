#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int inf=105;
struct e{
	int apple,to;
};
e add(int to,int apple){
	e a;
	a.apple=apple,a.to=to;
	return a;
}
vector<e>adj[inf];
int n,q,dp[inf][inf];
void dfs(int u,int father){
	dp[u][0]=0;
	if(adj[u].size()==1){
		return ;
	}
	for(int i=0;i<adj[u].size();i++){
		if(adj[u][i].to==father){
			adj[u].erase(adj[u].begin()+i);
			break;
		}
	}
	dfs(adj[u][0].to,u);
	dfs(adj[u][1].to,u);
	dp[u][1]=max(adj[u][0].apple,adj[u][1].apple);
	for(int i=2;i<=q;i++){
		dp[u][i]=max(dp[u][i],adj[u][0].apple+dp[adj[u][0].to][i-1]);
		dp[u][i]=max(dp[u][i],adj[u][1].apple+dp[adj[u][1].to][i-1]);
		for(int j=0;j<=i-2;j++){
			dp[u][i]=max(dp[u][i],adj[u][0].apple+adj[u][1].apple+dp[adj[u][0].to][j]+dp[adj[u][1].to][i-2-j]);
		}
	}
	return;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		adj[x].push_back(add(y,z));
		adj[y].push_back(add(x,z));
	}
	dfs(1,0);
	printf("%d",dp[1][q]);
	return 0;
}
