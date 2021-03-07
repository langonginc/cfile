#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<climits>
using namespace std;
typedef long long ll;
const int INF=INT_MAX/2;
const int inf=3005;
int dfs(int u);
struct e{
	int to,w;
};
e add(int to,int w){
	e a;
	a.to=to,a.w=w;
	return a;
}
int n,m,s,dp[inf][inf],pay[inf];
vector<e>adj[inf];
int main(){
	scanf("%d%d",&n,&m);
	s=n-m;
	for(int i=1;i<=s;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			adj[i].push_back(add(x,y));
		}
	}
	for(int i=m;i<=n;i++){
		scanf("%d",&pay[i]);
	}
	dfs(1);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%d  ",dp[i][j]);
//		}
//		printf("\n");
//	}
	printf("%d",dp[1][n]);
	return 0;
}
int dfs(int u){
	if(u>s){
		dp[u][1]=pay[u];
		return 1;
	}
	int total=0;
	for(int i=0;i<adj[u].size();i++){
		int w=adj[u][i].w;
		int to=adj[u][i].to;
		int c=dfs(to);
		total+=c;
		for(int j=total;j>0;j--){
			for(int k=1;k<=c;k++){
				if(j-k>=0){
					dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[to][k]+w);
				}
			}
		}
		return total;
	}
}
